#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; // Declare n outside the loop to use it in the for loop
    while (true)
    {
        n = get_int("Please enter a positive integer: ");
        if (n > 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("I looped %i!\n", i + 1);
    }
}