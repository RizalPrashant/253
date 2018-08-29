# Project 3: Programming Assignment Three

* Author: Prashant Rizal
* Class: CS253 Section 3
* Semester: Spring 2017

## Overview
This program deals with creating your program in a modular form, using C functions ad to understand the
use of pointers in the context of C strings.

## Compiling and Using
It is good to start fresh by using make clean in the terminal. After that,
use the command make to create a smash executable. Then, use smash to run the smash shell.
In the smash shell you can type anything you want and press enter. Or to change the directory 
type cd /pathname. To see the history, type history in the smash shell. And to exit smash, type exit and enter.

## Discussion

The very first thing I learnt was modular design of programming and using functions. For the code in main to look
simpler, I specific tasks as functions and called the functions in the main. The function comprised of both
return type and the parameters. Then, I learnt about data structures and how to create it using the struct keyword.
I created a data structure of the history of inputs in my bash shell in a different history.c file. It consisted of
functions like init_history(), add_history(), clear_history() and print_history(). One major problem I had was to
clear history. Because I had a struct inside another struct, I had to start clearing the allocated spaces from the
innermost part of the code and then finally clean the array which was really confusing. I think the concept of data
structures is really important in my future too because I will need to arrange my data in some form of list or 
struct in future for sure.

## Testing

You should manually provide some smash commands and then provide command history to check if it prints the
history correctly or not. Also, you can use valgrind to check for any memory leaks. To check with valgrind input,
valgrind --leak-check=yes smash
## Extra Credit

None

## Sources used

None
----------
This README template is using Markdown. To preview your README output, you can copy your file contents to a Markdown editor/previewer such as [https://stackedit.io/editor](https://stackedit.io/editor).
