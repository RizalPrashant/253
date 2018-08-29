#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "history.h"
#include "history.c"
#include <stdbool.h>

#define MAXLINE 4096

void changeSuccess(char*);
void printToken(char*);
char  bufCopy[MAXLINE];
bool done = false;

int main(void)
{
	init_history();

	  	char    buf[MAXLINE];
		fprintf(stderr,"$");
		
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		int end = strlen(buf);
		end--;
		buf[end] = '\0';
		strncpy(bufCopy, buf, MAXLINE);
		char *token = strtok(bufCopy, " ");

		add_history(buf);
		if(strcmp("", token)==0){
		
		}
		if(strcmp("exit", token) == 0){
			exit(0);
		}
		if (strcmp("cd", token) == 0) {
			char* token = strtok(buf," ");		  
			changeSuccess(token);
		}
		if(strcmp("history",token) == 0) {
			print_history();
		}
		//if strcmp = history then printhistory();
		else {
			printToken(token);
		}
		fprintf(stderr,"$");	
	  }
	clear_history();

	    // printf("what"); test purpose 
	
	return EXIT_SUCCESS;
  
}

void changeSuccess(char* token){
	token = strtok(NULL," ");
	int change_success = chdir(token);// if chdir <0 then print error, else print directory name
	if (change_success == 0)
	{
		char* cur_dir = getcwd(NULL, 0);
		printf("%s\n", cur_dir);  
		free(cur_dir);
	}
	else
	{
		printf("error: ");
		printf(token);
		printf(" does not exist\n");
	}

}

void printToken(char* token){
	int num = 0;
	while (token != NULL){
		printf ("[%d] %s\n",num, token);
		token = strtok (NULL, " ");
		num++;
	}
	num = 0;

}
