#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int count;
	int capacity;
	int *items;
} storage;

storage S;

int i=0;

bool consumerIsSleeping = true;
bool producerIsSleeping = false;

void* producer(void *args){
  while(1){
    
    if(producerIsSleeping) continue;
    
	S.items[S.count] = S.count;	
	S.count++;

    consumerIsSleeping = false;
    producerIsSleeping = true;
    
    //if we dont print each time the program breaks instantaniously
    //(both processes are sleeping) 
    printf("Iteration - %d\n", i++);
    
  }
}

void* consumer(void *args) {
  while (1){
    if(consumerIsSleeping) continue;
		
	S.items[S.count] = 0;
	S.count--;

    consumerIsSleeping = 1;
    producerIsSleeping = 0;
  }
}

int main() {
	
	pthread_t prod, cons;
	
	S.capacity = 5;
	S.count = 0;
	S.items = (int*)malloc(S.capacity * sizeof(int));

	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);
  
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);

	return 0;
}