# Project 4: Programming Assignment Four

* Author: Prashant Rizal
* Class: CS253 Section 3
* Semester: Spring 2017

## Overview
This program deals with parsing out the arguments and using fork(), exec() and wait() to create and manage
processes.

## Compiling and Using
It is good to start fresh by using make clean in the terminal. After that,
use the command make to create a smash executable. Then, use smash to run the smash shell.
to change the directory type cd /pathname. To see the history, type
history in the smash shell. And to exit smash, type exit and enter. Also, to run other commands supported 
by execvp(), just enter the commands and enter.

## Discussion

The first important thing i learnt in this project is processes. Using fork() it was possible to clone a process.
The clone is also referred as the child process. Then, it was possible to use exec() on the child process which 
would use the environment PATH variables to locate the commands. Also, wait() is used so that the parent process 
is waiting until the child process in executed. Also, using a random number generator, I made a random selection
from 0 to 3 so and used kill() every time 0 is randomed. This made a 1 out of  4 chances to kill the child process.

## Testing

Debugging can be done using gdb. You should manually provide some smash commands and then provide
command history to check if it prints the
history correctly or not. Also, you can use valgrind to check for any memory leaks. To check with valgrind input,
valgrind --leak-check=yes smash
## Extra Credit

None

## Sources used

None
----------
This README template is using Markdown. To preview your README output, you can copy your file contents to a Markdown editor/previewer such as [https://stackedit.io/editor](https://stackedit.io/editor).
