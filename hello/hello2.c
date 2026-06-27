#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What is your name? ");
    printf("Hello, %s\n", answer);
// %s is a format specifier used in C to print a string. It tells the printf function to expect a string argument and to print it accordingly. In this case, it will print the value of the variable 'answer', which is the name entered by the user.//

}