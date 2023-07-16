// This program will calculate all the dimensions of a rectangle and display them to the user.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declare variables
    float length, width, area, perimeter, diagonal;

    // Get user input
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    // Calculate area, perimeter, and diagonal
    area = length * width;
    perimeter = 2 * (length + width);
    diagonal = sqrt(pow(length, 2) + pow(width, 2));

    // Display results to user
    printf("The area of the rectangle is %.2f\n", area);
    printf("The perimeter of the rectangle is %.2f\n", perimeter);
    printf("The diagonal of the rectangle is %.2f\n", diagonal);

    // Display rectangle to user
    printf("Here is an approximate visual representation of the rectangle:\n");

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
            printf(" * ");
        printf("\n");
    }

    return 0;
}