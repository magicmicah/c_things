// This program will calculate the dimensions of a circle and display them to the user.

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

float get_radius_from_diameter(float diameter)
{
  float radius = diameter / 2;
  return radius;
}

float get_circumference_from_radius(float radius)
{
  float circumference = 2 * M_PI * radius;
  return circumference;
}

float get_area_from_radius(float radius)
{
  float area = M_PI * pow(radius, 2);
  return area;
}

float get_diameter_from_radius(float radius)
{
  float diameter = 2 * radius;
  return diameter;
}

float get_radius_from_circumference(float circumference)
{
  float radius = circumference / (2 * M_PI);
  return radius;
}

float get_radius_from_area(float area)
{
  float radius = sqrt(area / M_PI);
  return radius;
}

int main()
{
  float radius, diameter, circumference, area;
  int choice;

  // Get user input

  printf("Do you know the radius, diameter, circumference, or area of the circle?\n");

  printf("1. radius\n");
  printf("2. diameter\n");
  printf("3. circumference\n");
  printf("4. area\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the radius of the circle: ");
      if (scanf("%f", &radius) != 1) {
        printf("Not a valid number.");
        return 1;
      }
      diameter = get_diameter_from_radius(radius);
      circumference = get_circumference_from_radius(radius);
      area = get_area_from_radius(radius);
      break;
    case 2:
      printf("Enter the diameter of the circle: ");
      if (scanf("%f", &diameter) != 1) {
        printf("Not a valid number.");
        return 1;
      }
      radius = get_radius_from_diameter(diameter);
      circumference = get_circumference_from_radius(radius);
      area = get_area_from_radius(radius);
      break;
    case 3:
      printf("Enter the circumference of the circle: ");
      if (scanf("%f", &circumference) != 1) {
        printf("Not a valid number.");
        return 1;
      }
      radius = get_radius_from_circumference(circumference);
      diameter = get_diameter_from_radius(radius);
      area = get_area_from_radius(radius);
      break;
    case 4:
      printf("Enter the area of the circle: ");
      if (scanf("%f", &area) != 1){
        printf("Not a valid number.");
        return 1;
      }
      radius = get_radius_from_area(area);
      diameter = get_diameter_from_radius(radius);
      circumference = get_circumference_from_radius(radius);
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