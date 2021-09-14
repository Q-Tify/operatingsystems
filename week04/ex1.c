#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define n 100

int main(void){

pid_t x = fork();

if(x<0){

return EXIT_FAILURE;

}else if(x==0){

printf("Hello from child %d - %d\n", getpid(), n);

}else{

printf("Hello from parent %d - %d\n", getpid(), n);

}

return EXIT_SUCCESS;

}
