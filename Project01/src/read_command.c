/*
 * read_command.c
 *
 *  Created on: Sep 13, 2016
 *      Author: Kevin
 */

#include "Project01.h"

//#define MAXCMDS 255 //Max commands
//#define MAXARGS 100 //Max arguments

//static char cmd[MAXCMDS];

void read_command(char* cmd, char* params[]){
	char * commandcopy;
	char * token;
	const char delimiters[] = " \n\r";
	int num_args = 0;

	setbuf(stdout, NULL);
//	printf("hello from read_command 1\n");
	//clear old params
	for( int i=0; i< i+1; ++i){
		if(params[i] == (char *)0) break;
		//free(params[i]);
		params[i] = (char *)0;
		if (i>100){
			printf("inf loop");
			exit(-1);
		}
	}
//	printf("hello from read_command 2\n");
	//reads entire input
	fgets(cmd, MAXCMDS, stdin);
	int cmdLen = (int) strlen(cmd)-1;

	//check for quit
	if ((cmdLen==4) && (strncmp(cmd, "quit", 10) == 0)){
		printf("\nExiting Program...\n");
		exit(-1);
		return;
	}

	//Prepare command to be tokenized
	commandcopy = (char *)malloc(strlen(cmd) +2);
	strcpy(commandcopy, cmd);
	token = strtok(commandcopy, delimiters);
	strcpy(cmd, token);
	params[0] = token;
	//tokenization
	token = strtok(NULL, delimiters);
	while((num_args < MAXARGS) && (token != NULL)){
//		printf("%s", token);
		num_args++;
		params[num_args] = token;
		token = strtok(NULL, delimiters);
	}
	num_args++;
	params[num_args] = NULL;

	return;
}



