#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/shm.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

#define SHM_KEY 6362074913
#define SEG_SIZE 0x6400

struct Process
{
  int PID;
  int PPID;
  int PGID;
  int RSS;
  struct tm *procTime;
  char procName[20];
};

void printkproc(struct kinfo_proc *kp) {
  printf("%d\t%d\t%d\t%d\t%s\n", kp->ki_pid, kp->ki_ppid, kp->ki_pgid,
         kp->ki_rssize, kp->ki_comm);
}

void printProc(struct Process *pr)
{
  printf("%d\t%d\t%d\t%d\t%s\n", pr->PID, pr->PPID, pr->PGID, pr->RSS,
         pr->procName);
}

bool gotSigUser = false;
bool gotSigTerm = false;

void sigUserHandler(int sigCode) {
  gotSigUser = true;
  if (sigCode == SIGUSR1)
    printf("Received SIGUSR1\n");
}

void sigTerminator(int sigCode) {
  gotSigTerm = true;
  if (sigCode == SIGTERM)
    printf("Received SIGTERM\n");
}

void destroy(void *shm, int segment_id) {
  shmdt(shm);
  shmctl(segment_id, IPC_RMID, 0);
}

std::string procToString(struct Process *pr) {
  std::string proc;
  proc.append(std::to_string(pr->PID) + '\t');
  proc.append(std::to_string(pr->PPID) + '\t');
  proc.append(std::to_string(pr->PGID) + '\t');
  proc.append(std::to_string(pr->RSS) + '\t');
  proc.append(std::string(std::to_string(pr->procTime->tm_mday)) + 
            ' ' + std::to_string(pr->procTime->tm_hour) + ':' +
            std::to_string(pr->procTime->tm_min) + ':' +
            std::to_string(pr->procTime->tm_sec) + '\t');
  proc.append(std::string(pr->procName) + '\n');
  return proc;
}

int main() {
  /*
  struct sigaction act, oact;
  memset(&act, 0, sizeof(act));
  memset(&oact, 0, sizeof(oact));
  int sigVal = sigaction(SIGUSR1, &act, 0);
  int sigEnd = sigaction(SIGTERM, &act, &oact);
  */
  signal(SIGUSR1, sigUserHandler); // SIG_DFL
  signal(SIGTERM, sigTerminator);
  const int shared_segment_size = SEG_SIZE;
  int segment_id = shmget("/get_processes", shared_segment_size, 
                  IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
  printf("Shared memory segment ID is %d\n", segment_id);
    kill(getpid(), SIGUSR1);
      if (segment_id == -1) {
        perror("Shared memory parent");
        exit(100);
      }
      char *shm;
      shm = (char*) shmat (segment_id, 0, 0);
      printf ("shared memory attached at address %p\n", shm);
      if (shm == (void *)-1) {
        perror("Shared memory parent attach");
        destroy(shm, segment_id);
        exit(2);
      }
        if (gotSigTerm)
        {
          shmdt(shm);
          exit(144);
        }
        else if (gotSigUser) {
          struct kinfo_proc kp[100];
          const char *proc_info_header = 
                    "\nPID \t PPID \t PGID \t RSSIZE \t TIME \t COMMAND\n";
          sprintf(shm, proc_info_header);
          size_t len = sizeof(kp);
          std::vector<std::string> proc_vec;
          /* Fill out the first three components of the mib */
          int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PROC};
          sysctl(mib, 3, &kp, &len, NULL, 0);
          /* Fetch and print entries for pid's < 100 */
          for (int i = 0; i < 100; i++) {
            struct Process curProc;
            len = sizeof(kp);
            if (len > 0)
            {
              curProc.PID = kp[i].ki_pid;
              curProc.PPID = kp[i].ki_ppid;
              curProc.PGID = kp[i].ki_pgid;
              curProc.RSS = kp[i].ki_rssize;
              curProc.procTime = localtime(&kp[i].ki_start.tv_sec);
              strcpy(curProc.procName, kp[i].ki_comm);
            }
            if(curProc.PID != 0)
              proc_vec.push_back(procToString(&curProc));
          }
          std::string procs = std::accumulate(proc_vec.begin(), proc_vec.end(), std::string{}); 
          char writeToShm[procs.length() + 1];
          strcpy(writeToShm, procs.c_str());
          sprintf(shm + strlen(proc_info_header), "%s", procs.c_str());
          // if (shmctl(segment_id, IPC_RMID, 0) == -1)
          // {
          //   perror("shmctl");
          //   destroy(shm, segment_id);
          //   exit(6);
          // }
        }
        else {
          raise(*reinterpret_cast<int*>SIG_ERR);
        }
  return 0;
}
