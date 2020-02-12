#include "stdio.h" 
//This #include line allows input/output (printf)
//Lines that start with # are handled by the preprocessor
//Lines that start with '//' are comments

/*  You can 
also have multi-line 
comments using '/*' and it's partner */

//There is always a "main" function which is what gets executed
// When declaring a function there is the basic format:
// RETURN TYPE function_name(INPUT_TYPE) 
// the braces {} surround the commands of the function
// int is a basic integer and 'void' is a way of saying no input
int main(void) {
  //'printf' is a formatted print function that is included in 'stdio'
  //The '\n' character is a newline character
  printf("Hello World\n");
  //all instructions are terminated with a semi-color ';'
  
  //return 0 is to satisfy the return type int, 0 is the standard
  // value for "success" and it let's the operating system know
  // everything came out just fine.
  return 0;
}
