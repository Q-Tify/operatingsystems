#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

  int integerVariable = INT_MAX;
  float floatVariable = FLT_MAX;
  double doubleVariable = DBL_MAX;

  printf("Int Size: %lu Value: %d \n",sizeof(integerVariable),integerVariable);
  printf("Float Size: %lu Value: %f \n",sizeof(floatVariable),floatVariable);
  printf("Double Size: %lu Value: %f \n",sizeof(doubleVariable),doubleVariable);

  return 0;

}