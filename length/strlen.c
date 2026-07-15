#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    int length = strlen(s);
    printf("Length: %i\n", length);
}