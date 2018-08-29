#ifndef __MYHEADER_H
#define __MYHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cmd{
	void * pid; // Not complete or correctly typed for this part of the project
	char * cmd; // malloc'd bit of memory that will store your data
};

void init_history();
void add_history(char *);
void clear_history();
void print_history();

#endif /* __MYHEADER_H */
