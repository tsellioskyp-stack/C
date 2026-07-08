#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //int width = 2 * height + 2;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height + 2 + i; j++)
        {
            if (j < height - i + 1 || (height < j && j <= 2 + height))
            {
                printf("_");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
