#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Input: ");
    int count = 0;
if (s != NULL)
    {
        while (s[count] != '\0')
        {
            count++;
        }
    }
    printf("Length: %i\n", count);
}