#include <stdio.h>
#include <cs50.h>

void main(void)
{
    int series[8] = {4, 1, 6, 10, 5, 2, 11, 7};
    for (int i = 0; i < 7; i++)
    {
        int min = series[i];
        for (int j = i + 1; j < 8; j++)
        {
            if (series[j] < min)
            {
                min = series[j];
                int temp = series[i];
                series[i] = series[j];
                series[j] = temp; 
            }
                
        }
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%i ", series[i]);
    }

    printf("\n");
}