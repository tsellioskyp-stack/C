#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("s: %s\n", t);

    //this will NOT make a copy of string s, that is capitalized! Both strings t & s, are pointers that point to the same address, originally created when string s was inputted
    //using malloc & free:
    char *q = malloc(strlen(s) + 1); // syntax: malloc(how many bytes of memory + 1). Requires stdlib
    for (int i = 0, n = strlen(s); i < n + 1; i++)//n + 1 so as to end with the /0 character
    {
        *(q + i) = *(s + i);
    }
    printf("%s\n", q);
    
    //Alternatively: using strcpy(dest, src):
    strcpy(s, t);

    //IMPORTANT: The get_string function could return NULL. NULL is memory address of 0x0000... To avoid such complications, we usually make an if statement:
    // if (s == NULL)
    //  return 1;
    //Επίσης, ελέγχω εάν το strlen(s) > 0, πριν προβώ σε ενέργειες.
    // Τέλος, κάνω ΠΑΝΤΑ free(q), έτσι ώστε να ελευθερώσω το allocated memory.
}