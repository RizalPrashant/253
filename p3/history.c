#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HIST 100
int begin = 0;

static struct{
	int index;
	struct cmd **cmdArray;
}history;


void init_history(){
	history.index = 0;
	history.cmdArray = (struct cmd **)malloc(sizeof(char *) * MAX_HIST); // cmdArray[99]
	int i = 0;
	for (i= 0 ; i < MAX_HIST; ++i){
	  history.cmdArray[i] = NULL;
	}
	
}

void add_history( char* tokVal){
	if (history.index >= MAX_HIST){
	 return; 
	}
	struct cmd* cmdStruct = (struct cmd*)malloc(sizeof(struct cmd));
	//cmdStruct->pid = pid;
	cmdStruct->cmd = (char *) malloc(strlen(tokVal) +1);
	strcpy(cmdStruct->cmd, tokVal);
	history.cmdArray[history.index] = cmdStruct;
	history.index++;
	
}

void clear_history(){
  struct cmd ** temp = history.cmdArray;
  while(*temp){
	struct cmd *cs = *temp;
	free(cs);
	free(*temp);
	temp++;
  }
   free(history.cmdArray);
}


void print_history(){
  int i;
	for(i=0;i<history.index;i++){
	  printf("%d",i+1);
	  printf(" ");
		printf("%s\n", history.cmdArray[i]->cmd);
	}
}
 

