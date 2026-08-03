// Demonstrates memory errors via valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //I declare a pointer *x, that will allocate memory of the size of 3 integers
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
        return 1;
    x[0] = 72;  //or *x = 72;
    x[1] = 73;  // or *(x+1) = 72;
    x[2] = 33;
    printf("%p\n", x);
    printf("Has the value of: %i\n", *x);

    printf("%p\n", (x+1));
    printf("Has the value of %i\n", *(x+1));

    free(x);
    return 0;

}