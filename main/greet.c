#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./greet name\n");
        return 1;
    }
    string name = argv[1];
    printf("hello, %s\n", name);
    return 0;
}