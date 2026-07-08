#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float x = get_int("x: ");
    float y = get_int("y: ");
    printf("x / y = %0.5f\n", x / y);
}

// This program prompts the user to input two integers, x and y, and then calculates and prints the result of dividing x by y. The result is formatted to display 5 decimal places. The program uses the cs50 library for input functions.