#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "Hi!";
    printf("%c %c %c\n", s[0], s[1], s[2]); //chars
    printf("%s\n", s); //string
    printf("%i %i %i\n", s[0], s[1], s[2]); //ASCII
//I will try now to look pas the s[2]
printf("What happens if I try to print s[3]?\n");
    printf("%c %c %c %c\n", s[0], s[1], s[2], s[3]); //chars
    printf("%s\n", s); //string
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]); //ASCII
}

//Thats actually how printf works, it will print the string until it finds a null terminator, which is the character with ASCII value 0. In this case, s[3] is the null terminator, so printf will stop printing at that point.
