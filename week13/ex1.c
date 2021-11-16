#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *inputFile = "input.txt";

	FILE *input = fopen(inputFile, "r");
	
    int maxProcesses=256;
    int maxResources=256;
    int maxLength=256; 
	char buff[maxLength];
	
	int processes[maxProcesses]; 
    int E[maxResources]; 
    int A[maxResources];
	int C[maxProcesses][maxResources];
    int R[maxProcesses][maxResources];
	
	
	//E
    char *pointer = buff;
	fgets(buff, maxLength, input);
	int diffResources=0;
	while(*pointer!='\n'){
		int temp = strtol(pointer, &pointer, 10);
		E[diffResources++] = temp;
	}

    //A
	int aDiffResources=0;
  
    fgets(buff, maxLength, input);
	pointer = buff;
  
	while(*pointer != '\n'){
		int temp = strtol(pointer, &pointer, 10);
		A[aDiffResources++] = temp;
	}
	int temp;

	
	//C
	int numOfProcesses=0;
	while(strcmp(fgets(buff, maxLength, input), "\n") != 0){
		pointer=buff;
		for(int i=0; i<diffResources; i++){
			temp = strtol(pointer, &pointer, 10);
			C[numOfProcesses][i] = temp;
		}
		numOfProcesses++;
	}
	
	//R
	for(int i=0; i<numOfProcesses; i++){
		fgets(buff, maxLength, input);
		pointer=buff;
		for(int j=0; j<diffResources; j++){
			temp = strtol(pointer, &pointer, 10);
			R[i][j] = temp;
		}
	}
	
	
	
	
    //maxProcesses
	int pExecuted[256] = {};
	
	while(1){
		
    int processChanged = 0;
		
    for(int i=0; i<numOfProcesses; i++){
			
      int j;
      
      if(pExecuted[i])
				continue;
			
      for(j=0; j<aDiffResources; j++){
				if(R[i][j] > A[j]){
					break;
				}	
			}

      //if no resources -> continue
			if(j != aDiffResources)
				continue;

			// process terminated -> free resources
			for(j=0; j<aDiffResources; j++){
				A[j] += R[i][j] + C[i][j];
			}

			processChanged = 1;
			
        pExecuted[i] = 1;
		}

		if(processChanged == 0)
			break;
	}
	
	int deadlock = 0;

	for(int i=0; i<numOfProcesses; i++){
		if(!pExecuted[i]){
			deadlock = 1;
			break;
		}
	}
	
	if(deadlock){
		printf("Deadlocked processes: ");
		for(int i=0; i<numOfProcesses; i++){
			if(!pExecuted[i]){
				printf("%d ", i);
			}
		}
		printf("\n");
	}else{
		printf("No deadlocked processes\n");
	}

	return 0;
}