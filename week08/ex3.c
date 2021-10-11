#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

//VIRT and RES are increasing during the process execution
int main(void){
	
  int N = 10*1024*1024;

  for(int i=0;i<10;i++){  
    char* arr = malloc(N);
    memset(arr, 0, N);
    sleep(1);
  }
  
  return 0;
}