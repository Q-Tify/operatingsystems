#include <stdio.h>

void swap(int *x, int *y){
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

int main(void){

  int x, y;

  printf("Enter x:\n");
  scanf("%d", &x);

  printf("Enter y:\n");
  scanf("%d", &y);

  printf("x = %d, y = %d\n", x, y);//Before

  swap(&x, &y);

  printf("x = %d, y = %d\n", x, y);//After

  return 0;
  
}