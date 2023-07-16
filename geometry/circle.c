// This program will calculate the dimensions of a circle and display them to the user.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  float radius, diameter, circumference, area;
  int choice;

  // Get user input
  // Ask the user if they know the radius, diameter, circumference, or area of the circle
  // If they do, ask them to enter the value
  // If they don't, ask them to enter the radius
  // Calculate the other values
  // Display the results to the user
  // Display a visual representation of the circle to the user

  printf("Do you know the radius, diameter, circumference, or area of the circle?\n");

  printf("1. radius\n");
  printf("2. diameter\n");
  printf("3. circumference\n");
  printf("4. area\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the radius of the circle: ");
      scanf("%f", &radius);
      diameter = 2 * radius;
      circumference = 2 * M_PI * radius;
      area = M_PI * pow(radius, 2);
      break;
    case 2:
      printf("Enter the diameter of the circle: ");
      scanf("%f", &diameter);
      radius = diameter / 2;
      circumference = M_PI * diameter;
      area = M_PI * pow(radius, 2);
      break;
    case 3:
      printf("Enter the circumference of the circle: ");
      scanf("%f", &circumference);
      radius = circumference / (2 * M_PI);
      diameter = 2 * radius;
      area = M_PI * pow(radius, 2);
      break;
    case 4:
      printf("Enter the area of the circle: ");
      scanf("%f", &area);
      radius = sqrt(area / M_PI);
      diameter = 2 * radius;
      circumference = 2 * M_PI * radius;
      break;
    default:
      printf("Wrong answer, pal. Try again.");
      return 0;
  }

  printf("The radius of the circle is %.2f\n", radius);
  printf("The diameter of the circle is %.2f\n", diameter);
  printf("The circumference of the circle is %.2f\n", circumference);
  printf("The area of the circle is %.2f\n", area);

  printf("Here is an approximate visual representation of the circle:\n");

  for (int i = 0; i <= 2 * radius; i++)
  {
    for (int j = 0; j <= 2 * radius; j++)
    {
      if (pow(i - radius, 2) + pow(j - radius, 2) <= pow(radius, 2))
        printf(" * ");
      else
        printf("   ");
    }
    printf("\n");
  }

  return 0;
}