#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "history.h"
#include "history.c"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 4096


//static void smash_exec(int , char **);
static void smash_parse_args(const char*, int *, char **);
void changeSuccess(char*);
void printToken(char*);
char  bufCopy[MAXLINE];
char **argv;
int MAXARGS;
int count = 0;
pid_t pid;
int status;


void err_sys(const char* x) 
{ 
	perror(x); 
	exit(1); 
}

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
		add_history(buf);
		char *token = strtok(buf, " ");

		if(strcmp("", token)==0){

		}
		if(strcmp("exit", token) == 0){
			exit(0);
		}
		if (strcmp("cd", token) == 0) {
			changeSuccess(token);
		}
		if(strcmp("history",token) == 0) {
			print_history();
		}
		else{

			argv = (char**) malloc (sizeof(char *) * MAXARGS);
			smash_parse_args(bufCopy, &count, argv);
			if ((pid = fork()) < 0) {
				perror("fork");
				exit(EXIT_FAILURE);
			} else if (pid == 0) { /* child */
				execvp(argv[0],argv);
				// free(argv);
				//  free(argc);
				exit(EXIT_SUCCESS);
			}
			else{
				int randNum = rand() % 4;
				if(randNum == 0)
				{
					kill(pid, 9);
					printf("Child killed\n");

				}

			}
			if ((pid = waitpid(pid,&status,0)<0))
			{
				err_sys("waitpid error");
				printf("%%");

			}

		}
		//if strcmp = history then printhistory();
		//else {
		//	printToken(token);
		//}
		fprintf(stderr,"$");	
	}
	clear_history();	
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

static void smash_parse_args(const char *line, int *argc, char **argv){
	char *copy;
	char *token;

	copy = malloc(sizeof(char)* 4096);
	strcpy(copy,line);
	*argc = 0;
	//tokenize args and copy to argv array.
	token = strtok(copy, " ");
	while(token != NULL){
		argv[*argc] = malloc(sizeof(char) * (strlen(token) +1));
		strcpy(argv[*argc], token);
		token = strtok(NULL, " ");
		(*argc)++;
	}
	argv[*argc] = NULL;
	free(copy);
}


