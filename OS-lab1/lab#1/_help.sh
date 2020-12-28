function _help {
	printf "<---------DOCUMENTATION---------> \n"
	printf "Functions: \n1. calc\n2. search\n3. reverse\n4. strlen\n5. log\n6. exit\n7. help\n"
	printf "\t1. Calc funciton requires 2 integer aruments and has 4 features:\n\t1. sum; outputting summary of 2 arguments\n\t2. sub; outputting substraction of the 1st argument from the 2nd.\n\t3. mul; outputting multiplication of 2 arguments\n\t4. div; outputting dividing 1st argument by the 2nd. Dividing by zero will cause an error.\n"
	printf "\t2. Search function requires 2 arguments (1st is directory, 2nd file pattern) and recursively searching files with this pattern and outputting data of this files.\n"
	printf "\t3. Reverse function requires 2 arguments (file names). Function will record reversed by lines text from the 1st file to the 2nd.\n"
	printf "\t4. Strlen function requires 1 string argument and output its length.\n"
	printf "\t5. Log function is taking X.log file from /var/log/anaconda/X.log, searching for WW and II strings, replace it with Warning and Information and outputting this.\n"
	printf "\t6. Exit function is terminating programm with integer code written by user. If the code was not written the programm will be terminated with the code 0.\n"
	printf "\t7. Help function causes this file.\n"
}
