// This program will calculate the dimensions of a triangle and display them to the user.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  // Declare variables
  float side1, side2, side3, perimeter, area;

  // Get user input
  printf("Enter the length of side 1: ");
  scanf("%f", &side1);
  printf("Enter the length of side 2: ");
  scanf("%f", &side2);
  printf("Enter the length of side 3: ");
  scanf("%f", &side3);

  // Calculate perimeter and area
  perimeter = side1 + side2 + side3;
  area = sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3));

  // Display results to user
  printf("The perimeter of the triangle is %.2f\n", perimeter);
  printf("The area of the triangle is %.2f\n", area);

  // Display triangle to user
  if (side1 > 1 && side1 == side2 && side1 == side3){
    printf("Here is an approximate visual representation of an equilateral triangle:\n");
    for (int i = 1; i <= side1; i++) {
      for (int j = 1; j <= side1 - i; j++) {
        printf(" ");
      }
      for (int k = 1; k <= i; k++) {
        printf("* ");
      }
      printf("\n");
    }
  }
  return 0;
}