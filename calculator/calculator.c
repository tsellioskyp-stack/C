#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long dollars = 1;
    while (true)
    {
        char c = get_char("Here is $%li, do you want to double it and give it to the next person? ", dollars);
        if (c == 'y' || c == 'Y')
        {
            dollars *= 2;
        }
        else if (c == 'n' || c == 'N')
        {
            printf("You chose not to double the money. The final amount is $%li.\n", dollars);
            break;
        }
        else
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}