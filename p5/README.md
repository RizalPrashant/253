# Project 5: Programming Assignment Five

* Author: Prashant Rizal
* Class: CS253 Section 3
* Semester: Spring 2017

## Overview
This project is about using ring buffer, and setting up signals and alarms for a multithreaded code for
checkpointing the ring buffer.

## Compiling and Using
It is good to start fresh by using make clean in the terminal. After that,
use the command make.


## Discussion

This project was really interesting for me. I had to create alarm and signal for a ring buffer. 
When I created the signal, I called the dump_buffer function on it. Also, I learnt about what a
multithreaded code is. A sequential program is divided into many threads which is then processed and joined
later. This makes the program faster than normal.

## Testing

For testing, use the code ./backpack.sh "filename to store your test" . Then use cat "filename
you stored your data in" and see if you get a Passing message or not.

## Extra Credit

None

## Sources used

None
----------
This README template is using Markdown. To preview your README output, you can copy your file contents to a Markdown editor/previewer such as [https://stackedit.io/editor](https://stackedit.io/editor).
