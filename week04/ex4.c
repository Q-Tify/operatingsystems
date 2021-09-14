#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Command length <= 100 chars.\n\n");

  char commandVariable[100];
  
  while(1){
    
    printf("Write your command:\n");
    fgets(commandVariable, 100, stdin);

    commandVariable[strcspn(commandVariable, "\n")] = 0;
    
    if(fork()==0){  
    
      char *arguments_list[100];
      char *token = strtok(commandVariable, " ");

      int i=0;

      while(token!=NULL){
        arguments_list[i] = token;
        token = strtok(NULL, " ");
        i++;
      }
      arguments_list[i] = NULL;
      
      execvp(arguments_list[0],arguments_list);

      break;
    }
    
  }

  return EXIT_SUCCESS;
}
