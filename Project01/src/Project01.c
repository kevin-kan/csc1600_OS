/*
 ============================================================================
 Name        : Project01.c
 Author      : Kevin Kan
 Version     :
 Copyright   : 2016
 Description : Project 1 - Shell
 ============================================================================
 */

#include "Project01.h"

void type_prompt();
void read_command();
int status;
pid_t pid;

int main(void) {
	char command[50];
	char *params[50];
	setbuf (stdout, NULL);
//	printf("hello world!\n");
	while (1){
		type_prompt();
		read_command(command, params);
//		printf("returned\n");
//		printf("%s\n", command);
//		printf("message %s\n", params[0]);
		pid = fork();
//		printf("pid is: %d \n", pid);
		if(pid<0){
			printf("Unable to fork");
			continue;
		}
		if (pid != 0){
			waitpid(pid, &status, 0);
		}else{
//			printf("executing command %s \n", command);
//			printf("executing param %s \n", params[0]);
//			printf("executing param %s \n", params[1]);
//			printf("executing param %s \n", params[2]);
			if (strncmp(command, "quit", 100)== 0){
				return 0;
			}
			execvp(command, params);
		}
	}
	return 0;
}
