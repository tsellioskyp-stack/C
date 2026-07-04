#include<stdio.h>
#include<cs50.h>
//Prototypes
int get_positive_int(void);
void funct(int x)
//void means that the function does not return any value. The function takes an integer parameter x and prints its value to the console using printf. I could write the fucntion below the main function, but I would have to declare the function prototype above the main function. The function prototype is a declaration of the function that tells the compiler about the function's name, return type, and parameters. It allows the compiler to check for correct usage of the function in the code before it is defined. In this case, since the funct function is defined before the main function, there is no need for a function prototype.
{
    printf("The value of x is: %i\n", x);
}

int main(void)
{
    printf("Hello, World!\n");
    funct(get_positive_int());
    return 0;
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Please enter a positive integer: ");
    }
    while (n < 1);
    return n;
}