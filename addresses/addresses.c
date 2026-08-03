#include <stdio.h>

int main(void)
{

int n = 50;
int *p = &n;
// I will now see the memory address of n
printf("%p\n", &n); //p: pointer
// or
printf("%p\n", p);

//Printing the value inside variable n, using it pointer p:
printf("%i\n", *p); //de-reference operator
}
