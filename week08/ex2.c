#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

//si and so parametrs are the same, during execution the amount of free memory is decreasing
//after finishing, the program clears the occupied memory and the amount of the 
//free memory becomes the same as at the beginning
int main(void){
	
  int N = 10*1024*1024;

  for(int i=0;i<10;i++){  
    char* arr = malloc(N);
    memset(arr, 0, N);
    sleep(1);
  }
  
  return 0;
}