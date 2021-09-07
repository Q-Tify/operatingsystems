#include <stdio.h>

#define N 100

void bubble_sort(int a[], int n) {
  for(int i=0;i<n;i++){   
    for(int j=0;j<n-i-1;j++){       
      if(a[j]>a[j + 1]){
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  } 
}

int main() {

  int a[N];
  int n;
  
  printf("Number of elements in array:\n");
  scanf("%d", &n); 

  printf("Enter %d elements:\n", n);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  printf("Unsorted array:\n");
  for(int i=0;i<n;i++){
    printf("%d ", a[i]);
  }

  bubble_sort(a, n);
  
  printf("\nSorted array:\n");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
    
  return 0;
}
