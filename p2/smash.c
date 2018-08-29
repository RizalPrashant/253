#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 4096


int main ()
{
	char    buf[MAXLINE];
	char    bufCopy[MAXLINE];
	fprintf(stderr,"$");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
	  int end = strlen(buf);
	  end--;
	  buf[end] = '\0';
	  strncpy(bufCopy, buf, MAXLINE);
	  char *token = strtok(bufCopy, " ");
	  if(strcmp("exit", token) == 0){
	    exit(0);
	  }
	  if (strcmp("cd", token) == 0) {
		  token = strtok(NULL," ");
		  int change_success = chdir(token);// if chdir <0 then print error, else print directory name
		  if (change_success == 0){
		  char* cur_dir = getcwd(NULL, 0);
		  printf("%s\n", cur_dir);  
		  }
		  else{
		  printf("error: ");
		  printf(token);
		  printf(" does not exist\n");
		  }
	  }
	     else {
		char* token = strtok(buf," ");
		int num = 0;
		while (token != NULL){
			printf ("[%d] %s\n",num, token);
			token = strtok (NULL, " ");
			num++;
		}
	  }
		fprintf(stderr,"$");
	}


return EXIT_SUCCESS;
}
