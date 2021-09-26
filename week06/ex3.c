#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
  int processId;
  int arrivalTime;
  int burstTime;
  int remainingBurstTime;
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


void calculateWaitingTime(process *schedule, int N, int quantum){
  int T=0;
  schedule[0].waitingTime = 0;
  bool undoneProcesses=true;
  
  while(undoneProcesses){
    bool somethingChanged=false;
    undoneProcesses = false;

    for(int i=0;i<N;i++){
      if(schedule[i].arrivalTime<=T && schedule[i].remainingBurstTime>0){
        
        somethingChanged=true;

        if(schedule[i].remainingBurstTime>quantum){
          T=T+quantum;
          schedule[i].remainingBurstTime=schedule[i].remainingBurstTime-quantum;
        }else{
          T=T+schedule[i].remainingBurstTime;
          schedule[i].waitingTime=T-schedule[i].burstTime-schedule[i].arrivalTime;
          schedule[i].remainingBurstTime=0;
          schedule[i].done=true;
        }

      }
      
    }
    if(!somethingChanged) T=T+1;
    
    for(int j=0;j<N;j++){
      if(schedule[j].done==false){
        undoneProcesses = true;
      }
    }
  } 

}

void calculateTurnAroundTime(process *schedule, int N){
  for(int i=0;i<N;i++){
    schedule[i].turnAroundTime=schedule[i].burstTime+schedule[i].waitingTime;
  }
}


void calculateCompletionTime(process *schedule, int N){
  for(int i=0;i<N;i++){
    schedule[i].completionTime=schedule[i].turnAroundTime+schedule[i].arrivalTime;
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
  int quantum;

  
  //Reading number of processes
  printf("N = ");
  scanf("%d",&N);
  
  //Reading quantum
  printf("quantum = ");
  scanf("%d",&quantum);
  
  
  process *schedule = (process*)malloc(N*sizeof(process));
  

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
    schedule[i].remainingBurstTime = schedule[i].burstTime;
    printf("========================");
  }
  

  //Sorting by arrival time
  sortByArrivalTime(schedule, N);


  //Calculating waiting time
  calculateWaitingTime(schedule, N, quantum); 
  

  //Calculating turnaround time
  calculateTurnAroundTime(schedule,N);


  //Calculating completion time
  calculateCompletionTime(schedule,N);


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