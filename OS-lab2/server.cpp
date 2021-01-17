/**
* Warning: this code was written whatever works, so it hard-to-read
*/

#define _BSD_SOURCE
#include <arpa/inet.h>
#include <iostream>
#include <sys/shm.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 70
#define MAX_NUM_ARGS 5

using namespace std;

class Server {
private:
  int servSock;
  int clientConnection;
  struct sockaddr_in server;
  struct sockaddr_in client;
  int size_of_addstruct = sizeof(sockaddr_in);
public:
 
  Server(int port) {
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
  }

  void CreateSocket() {
    servSock = socket(AF_INET, SOCK_STREAM, 0);
    if (servSock == -1) {
      cout << "Unable to create socket\n";
      exit(-1);
    }
    cout << "Socket was created\n";
  }

  void Bind() {
    if (bind(servSock, (struct sockaddr *)&server, sizeof(server)) != 0) {
      perror("Unable to bind\n");
      exit(1);
    }
    cout << "Binding was finished successfully\n";
  }

  void Accept() {
    clientConnection = accept(servSock, (struct sockaddr *)&client,
                              (socklen_t *)&size_of_addstruct);
    if (clientConnection < 0) {
      perror("Accept Failed\n");
      exit(-3);
    }
    cout << "Connection was accepted successfully\n";
  }

  void dup2Safe(int oldfd, int newfd) {
  int return_value = dup2(oldfd, newfd);
  if(return_value == -1) {
    fprintf(stderr, "Unable to execute dup2(%d, %d)", oldfd, newfd);
    exit(1);
  }
}

void closeSafe(int fd) {
  int return_value = close(fd);
  if(return_value == -1) {
    fprintf(stderr, "Unable to execute close(%d)", fd);
    exit(1);
  }
}

void quit(int status) {
    kill(0, SIGTERM);
    exit(status);
  }

  void createPipe(int* pipefd) {
  if(pipe(pipefd)) {
    fprintf(stderr, "Unable to create pipe");
    exit(1);
  }
}

void parseCommand(char* buffer, char** command, char** args, int max_size) {
  char* return_value = fgets(buffer, max_size, stdin);

  if(return_value == NULL) {
    quit(1);
  }   
  size_t len = strlen(buffer);
  if(buffer[len - 1] == '\n')
    buffer[len - 1] = '\0';

  *command = strtok(buffer, " ");
  args[0] = *command;
}

  void Run() {
    CreateSocket();
    Bind();
    listen(servSock, 3);
    Accept();
    int data_size;
    char clientMessage[100];
    char *serverReply;
    while ((data_size = recv(clientConnection, clientMessage, 100, 0)) > 0) {
      if(!strcmp(clientMessage, "GET_PROC")) {
        int segment_id;
        char *shm;      	
        char *args[3] = {"ls", "-l", NULL};
        if(fork() == 0)
	        execvp("./bin/get_processes.exe", args);
        
        printf("Enter the shared memory id: ");
        scanf("%d", &segment_id);
        shm = (char *)shmat(segment_id, NULL, 0);
        printf ("shared memory reattached at address %p\n", shm);
        serverReply = shm;
        write(clientConnection, serverReply, strlen(serverReply));
        shmctl (segment_id, IPC_RMID, 0);
        memset(serverReply, 0, sizeof(serverReply));
        /* Print out the string from shared memory.  */
      }
      else if(!strcmp(clientMessage, "GET_COMM")) {
        int pipefd[3];
        createPipe(pipefd);
        char buffer[MAX_COMMAND_LENGTH];
        char* command;
        char* args[MAX_NUM_ARGS + 2];
        int child_pid;
        args[MAX_NUM_ARGS + 1] = NULL;
  
              while((child_pid = waitpid(-1, NULL, WNOHANG)) > 0) {
                printf("Process %d terminated\n", child_pid);
            }

            printf("Enter command > ");
            parseCommand(buffer, &command, args, MAX_COMMAND_LENGTH);
            if(command == NULL) {
              continue;
            }

            if(strcmp(command, "exit") == 0) {
              quit(0);
            } 
          else {
            int pid = fork();
          if(pid == -1) {
            fprintf(stderr, "Unable to fork.\n");
            quit(1);
          }
          printf("%d\n", pid);
          if(pid == 0) {
            closeSafe(pipefd[0]);
            dup2Safe(pipefd[1], fileno(stdout));
            execvp(command, args);
            fprintf(stderr, "Unable to start command: %s\n", command);
            quit(1);
          } else if(pid > 0) {
            printf("Started process with pid %d\n", pid);
            
            while(waitpid(pid, NULL, 0) == -1);
            printf("Process %d ended\n", pid);
            }
          }
        char buf[1024];
        //closeSafe(pipefd[1]);
        read(pipefd[0], &buf, 100);
        //closeSafe(pipefd[0]);
        printf("%s", buf);
        strncpy(serverReply, buf, strlen(buf));
        write(clientConnection, serverReply, 200);
        memset(serverReply, 0, sizeof(serverReply));
      }
      else {
      strncpy(serverReply, clientMessage, strlen(clientMessage));
      write(clientConnection, serverReply, 200);
      memset(serverReply, 0, sizeof(serverReply));
      }
    }

    if (data_size == 0) {
      cout << "Client disconnected\n";
      exit(0);
    } else if (data_size == -1) {
      perror("Receiving failed\n");
    }
  }

  int getConnectionSocket() const { return clientConnection; }

  int getServerSocket() const { return servSock; }
};


int main() {
  Server server(6660);
  server.Run();
  return 0;
}
