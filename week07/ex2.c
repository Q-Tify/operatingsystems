#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N;
  printf("N = ");
  scanf("%d",&N);

  int *intArray = (int*)malloc(N * sizeof(int));
	
	if(intArray == NULL)
	{
		printf("Error with memory allocation!\n");
		return 0;
	}
	
	for(int i=0; i<N; i++){
    intArray[i] = i;
  }
		
	
	printf("Array:\n");
	for(int i=0; i<N; i++){
    printf("%d ", intArray[i]);
  }
		
	free(intArray);

  return 0;
}