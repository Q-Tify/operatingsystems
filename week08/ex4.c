#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>


//u.ru_maxrss is increasing, other parametrs of u are the same

int main(void){
  int N = 10*1024*1024;

  for(int i=0;i<10;i++){  
    char* arr = malloc(N);
    memset(arr, 0, N);
    int who = RUSAGE_SELF;
    struct rusage u;
    int r = getrusage(who, &u);
    printf("%lu %lu %lu %lu %lu\n ",u.ru_maxrss, u.ru_stime.tv_sec, u.ru_ixrss, u.ru_idrss, u.ru_isrss);
    sleep(1);
  }
  
  return 0;
}