#include <stdio.h>
//#include <cs50.h>

void print_column(int height);

int main(void)
{
    int height = 0;
    printf("Height: ");
    scanf("%d", &height);
    print_column(height);
}

void print_column(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }
}
