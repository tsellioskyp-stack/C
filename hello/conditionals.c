#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int answer = get_int("What is your age? ");
    if (answer < 18)
    {
        printf("You are a minor.\n");
    }
    else
    {
        printf("You are an adult.\n");
    }
}
//In the case I try to input a string instead of an integer, the program will not accept it and will prompt the user to enter a valid integer. The get_int function is designed to only accept integer inputs, so if a string or any other non-integer input is provided, it will result in an error message and the user will be asked to try again until a valid integer is entered.