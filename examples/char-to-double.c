
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  double number;
  char number_string[100];

  printf("Enter a number: ");
  scanf("%s", number_string);
  number = atof(number_string);
  //number = sscanf(number_string, "%lf", &number);
  printf("You entered: %s\n", number_string);
  printf("The number is %lf\n", number);

  return 0;
}