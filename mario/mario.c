#include <stdio.h>
#include <cs50.h>

int rows(void);
int columns(void);
int main(void)
{
    int r = rows();
    int c = columns();
    for (int i = 0; i < r; i++)
    { 
        for (int j = 0; j < c; j++)
        {
            printf("#");   
        }
        printf("\n");
    }
}

int rows(void)
{
    return get_int("Height: ");
}

int columns(void)
{
    return get_int("Width: ");
}