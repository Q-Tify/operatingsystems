#include <stdio.h>
#include <string.h>

#define N 100

int main(void) {
  
  char stringVariable[N];
  char reverseStringVariable[N];
  
  printf("Enter string:\n");
  scanf("%[^\n]s", stringVariable);
  
  for(int i=0;i<strlen(stringVariable);i++){
    reverseStringVariable[i]=stringVariable[strlen(stringVariable)-i-1];
  }
  
  printf("Your string is %s.\n", stringVariable);
  printf("Your reversed string is %s.\n", reverseStringVariable);

  return 0;

}