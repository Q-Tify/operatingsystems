#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Command length <= 100 chars.\n\n");
  char commandVariable[100];
  while(1){
    printf("Write your command:\n");
    scanf("%100s", commandVariable);
    system(commandVariable);
  }
  return EXIT_SUCCESS;
}
