#include <stdio.h>

int main(void){
  
  int n;

  printf("Enter n:\n");
  scanf("%d", &n);

  for(int i=n;i>0;i--){

    for(int j=2*n-1;j>0;j--){
      
      if(j==i){
        printf("*");
      }else if(j<i || j>2*n-i){
        printf(" ");
      }else{
        printf("*");
      }

    }
    
    printf("\n\n");   
  
  }

  return 0;

}