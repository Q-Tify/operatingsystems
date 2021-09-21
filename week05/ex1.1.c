#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 4

typedef struct{
  pthread_t thread_id;//defined by operating system //unsigned long
  int thread_number;//defined by us
  char *string;
}thread_info;

void* job(void* args){
  thread_info *t= (thread_info*)args;
  unsigned long x = pthread_self();
  printf("hello from thread system id: %lu | user id: %d\n", x, t->thread_number);
  return NULL;
}


int main(void){
  thread_info *tinfo;

  tinfo = calloc(N, sizeof(thread_info));
  
  for(int i=0;i<N;i++){
    tinfo[i].thread_number=i;
    pthread_create(&(tinfo[i].thread_id),NULL, job, &tinfo[i]);
    printf("Created thread number: %lu\n ",tinfo[i].thread_id);
    
  }

  exit(EXIT_SUCCESS);
}