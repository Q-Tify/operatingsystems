#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  char **s = malloc(sizeof(char*));//allocating memory
  char foo [] = "Hello World";
  *s = foo;
  printf("s is %s\n", *s);//error fixed
  s[0] = foo;
  printf("s[0] is %c\n", *s[0]);//error fixed
  free(s);//freeing memory
  return (0);
}