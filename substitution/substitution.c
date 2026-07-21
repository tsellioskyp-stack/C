#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool length_checker(string argv);
bool unique_checker(string argv);
string converter(string input, string argv);

int main(int argc, string argv[])
{
    if (argc <  2 || argc >= 3) // failure code 2: wrong number of arguments in command line
    {
        printf("Usage: ./substitution [key]\n");
        return 1;
    }
    bool alpha = true;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        //Uppercasing
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] = toupper(argv[1][i]);
            }
            else
            {
                continue;
            }
        }
        //Second Check: is it all letters? (code: 4)
        else
        {
            alpha = false;
            break;
            
        }
    }  
    if (length_checker(argv[1]) == false)
    {
        printf("Key is not 26 characters long\n");
    }
    if (alpha == false)
    {
        printf("Non-alphabetic characters in the key is INVALID!\n");
    }
    if (unique_checker(argv[1]) == false)
    {
        printf("Non-unique characters in the key is INVALID!\n");

    }
    //Exit flag
    if ((length_checker(argv[1]) == false) || (alpha == false) || (unique_checker(argv[1]) == false))
    {
        return 1;
    }

    string input = get_string("plaintext: ");
    printf("ciphertext: %s\n", converter(input, argv[1]));
    return 0;

}


bool length_checker(string argv)
{
    return strlen(argv) == 26;
}

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

string converter(string input, string argv)
{
    int n = strlen(input);
    char table[26];
    for (int i = 0; i < 26; i++)
    {
        table[i] = argv[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (islower(input[i]))
        {
            int index = input[i] - 'a';
            input[i] = tolower(table[index]);
        }
        else if (isupper(input[i]))
        {
            int index = input[i] - 'A';
            input[i] = table[index];
        }
        else
        {
            continue;
        }
        
    }
    return input;
}
