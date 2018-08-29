# Project 2: Programming Assignment Two

* Author: Prashant Rizal
* Class: CS253 Section 3
* Semester: Spring 2017

## Overview
This program deals with processing strings using functions like string tokenizer and string compares. It also show about proper C library calls as well as accessing arrays.

## Compiling and Using
It is good to start fresh by using make clean in the terminal. After that,
use the command make to create a smash executable. Then, use smash to run the smash shell.
In the smash shell you can type anything you want and press enter. Or to change the directory 
type cd /pathname. And to exit smash, type exit and enter.

## Discussion

First thing I learnt was to read through the test scripts and see what is required 
from our code. Then I learnt how to use string tokenizer, string compare, fgets, etc
for different purposes like string processor, scanning user input from keyboard, etc. 
I also learnt how to add functions in my smash shell like cd and exit using functions like chdir() 
and exit(). One of the problems I had was when I tokenized user input so that when they type exit the token would 
store exit. Then, I used strcmp to compare the token with "exit". But when I did that, the compiler said the two 
strings are not equal so I realized that the token still had a new line behind the exit. So, I had to 
add a null pointer "\0" at the end of the token to denote that there is no return key there. That was also 
the most challenging part of the project for me. I think this concept of string processes and basic commands is 
going to help me in my future projects where I add more basic commands to my smash shell.

## Testing

Using the backpack.sh file given to us. To test for part 1, you type in the command:
backpack.sh 1 "filetostoreresultin"
And for part 2 you type in the command:
backpack.sh 2 "filetostoreresultin"
Then you can simply do cat "fileyoustoredresultin" to see if you get a Pass or some error.

## Extra Credit

None

## Sources used

None
----------
This README template is using Markdown. To preview your README output, you can copy your file contents to a Markdown editor/previewer such as [https://stackedit.io/editor](https://stackedit.io/editor).
