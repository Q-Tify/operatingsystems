#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
  printf("Main program id = %d\n", getpid());
  for(int i=0;i<3;i++){
    fork();
    sleep(5);
  }
  return EXIT_SUCCESS;
}

//When we call fork() 3 times in a loop we will get 4 processes 
//because we have (main process + 3 fork processes) -> (1+3=4)
//The same if we call fork() 5 times we will get 6 processes  