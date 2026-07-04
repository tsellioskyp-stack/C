#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n; // Declare n outside the loop to use it in the for loop
    while (true)
    {
        n = get_int("How many times do you wanna loop? ");
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                printf("I looped %i!\n", i + 1);
            }
            break;
        }
        else
        {
            printf("Please enter a positive integer.\n");
        }
    }
}