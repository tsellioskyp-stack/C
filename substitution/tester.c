#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool unique_checker(string argv)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[i] == argv[j])
            {
                return false;
            }
        }
    }

    return true;
}