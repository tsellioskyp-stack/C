#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; // Declare n outside the loop to use it in the for loop
    do
    {
        n = get_int("Please enter a positive integer: ");
    }
    while (n < 1); //do while loops keeps repeating as long as the condition is true, in this case, n < 1. The loop will continue to prompt the user for input until a positive integer is entered. Do while loops are useful when you want to ensure that the loop body is executed at least once, regardless of the initial condition. In this case, it guarantees that the user will be prompted for input at least once before checking if the input is valid.
    for (int i = 0; i < n; i++)
    {
        printf("I looped %i!\n", i + 1);
    }
}