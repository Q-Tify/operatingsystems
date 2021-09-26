#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
  int processId;
  int arrivalTime;
  int burstTime;
  int completionTime;
  int waitingTime;
  int turnAroundTime;
  bool done;
} process;


void swap(process *a, process *b){
  process temp = *a;
  *a=*b;
  *b=temp;
}


void sortByArrivalTime(process *schedule,int N){
  for(int i=0;i<N-1;i++){
    for(int j=0;j<N-i-1;j++){
      if(schedule[j].arrivalTime > schedule[j+1].arrivalTime){
        swap(&schedule[j],&schedule[j+1]);
      }
    }
  }
}


void sortByArrivalAndBurstTime(process *schedule, int N){
  for(int i=0;i<N-1;i++){
    for(int j=0;j<N-i-1;j++){
      if(schedule[j].arrivalTime == schedule[j+1].arrivalTime && schedule[j].burstTime > schedule[j+1].burstTime){
        swap(&schedule[j],&schedule[j+1]);
      }
    }
  }
}


void calculateWaitingTurnaroundCompletionTime(process *schedule,int *processFlow, int N){
  
  schedule[0].waitingTime = 0;
  schedule[0].turnAroundTime = schedule[0].burstTime + schedule[0].waitingTime;
  schedule[0].completionTime = schedule[0].turnAroundTime + schedule[0].arrivalTime; 
  schedule[0].done = true;
  
  processFlow[0] = 0;
  
  //finding processFlow
  for(int i=1;i<N;i++){
    bool firstP=false;
    //finding next process to execute
    for(int j=0;j<N;j++){
      if(schedule[j].arrivalTime<=schedule[processFlow[i-1]].completionTime && !schedule[j].done && (!firstP || schedule[j].burstTime<=schedule[processFlow[i]].burstTime)){
        processFlow[i]=j;
        firstP=true;
      }
    }
    //calculating for process k waiting time
    int k = processFlow[i];
    schedule[k].done=true;
    schedule[k].waitingTime = schedule[processFlow[0]].arrivalTime-schedule[k].arrivalTime;
    for(int t=0; t<i;t++){
      schedule[k].waitingTime = schedule[k].waitingTime + schedule[processFlow[t]].burstTime;  
    }
    if(schedule[k].waitingTime<0){
      schedule[k].waitingTime=0;
    }

    //calculating for process k turnaroundTime and completionTime
    schedule[k].turnAroundTime = schedule[k].burstTime + schedule[k].waitingTime;
    schedule[k].completionTime = schedule[k].turnAroundTime + schedule[k].arrivalTime;
  }
}


void sortByProcessNumber(process *schedule, int N){
  for(int i=0;i<N-1;i++){
    for(int j=0;j<N-i-1;j++){
      if(schedule[j].processId > schedule[j+1].processId){
        swap(&schedule[j],&schedule[j+1]);
      }
    }
  }
}


int main(void) {
  
  int N;
  
  //Reading number of processes
  printf("N = ");
  scanf("%d",&N);
  
  
  process *schedule = (process*)malloc(N*sizeof(process));
  int *processFlow = (int*)malloc(N*sizeof(int));
  

  //Reading the input
  printf("========================");
  for(int i=0;i<N;i++){
    printf("\nProcess #%d",i+1);
    schedule[i].processId=i+1;

    schedule[i].done =false;

    printf("\nArrival time = ");
    scanf("%d",&schedule[i].arrivalTime);
    
    printf("Burst time = ");
    scanf("%d",&schedule[i].burstTime);
    printf("========================");
  }
  

  //Sorting by arrival time
  sortByArrivalTime(schedule, N);


  //Sorting by arrival and burst time
  sortByArrivalAndBurstTime(schedule,N);
  

  //Calculating waiting, turnaround and burst time
  calculateWaitingTurnaroundCompletionTime(schedule, processFlow, N);


  //Calculating average
  double avg_tat=0;
  double avg_wt=0;
  for(int i=0;i<N;i++){
    avg_tat=avg_tat+schedule[i].turnAroundTime;
    avg_wt=avg_wt+schedule[i].waitingTime;
  }
  avg_tat=avg_tat/N;
  avg_wt=avg_wt/N;


  //Sorting processes back
  sortByProcessNumber(schedule,N);
  

  //Printing statistics
  printf("\n\nStatistics\n");
  printf("===============================================================================================\n");
  printf("Process #\tArrival Time\tBurst Time\t\tCompletion Time\t\tWaiting time\tTurnaround Time\n");
  for(int i=0;i<N;i++){
    printf("%9d\t%12d\t%10d\t\t%15d\t\t%12d\t%15d\n",schedule[i].processId,schedule[i].arrivalTime,schedule[i].burstTime,schedule[i].completionTime,schedule[i].waitingTime,schedule[i].turnAroundTime);
  }
  printf("===============================================================================================\n");
  printf("Average\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%f\t\t  %f\n",avg_wt,avg_tat);
  
  return 0;
}