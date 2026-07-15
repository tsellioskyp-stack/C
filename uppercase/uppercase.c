#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Before: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
    printf("After:  %s\n", s);
}

//or, using the ctype.h library, you can replace the if statement with the following line:
// if (islower(s[i])) { s[i] = toupper(s[i]); }