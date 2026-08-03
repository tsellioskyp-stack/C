//this script swaps data between two variables, using pointers & de-referencing

#include <stdio.h>

void swap(int *a, int *b);
void main(void)
{
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("x is now %i and y is now %i", x, y);
}

void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }