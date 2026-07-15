#include <string.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    //Initializing i to 0, n to the length of the string s, and iterating through each character in the string until i is less than n
    {
        printf("%c", s[i]);
    }
    printf("\n");
}