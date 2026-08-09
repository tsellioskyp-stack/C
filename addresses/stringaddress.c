#include <cs50.h>
#include <stdio.h>

int main(void)
{
string s = "HI!";
printf("%p\n", s);// this prints the ADDRESS of the whole string! it does not need a '&'
printf("%p\n", &s[0]); //prints the address of the char s[0]. i.e. 0x561748003
printf("%p\n", &s[1]); //prints the address of the char s[1], i.e. 0x561748004

// without the CS50 library:
char *q = "hiaaa!";
printf("%s\n", q); //q is the address of the first char in the string. This will print "hiaaa!"
printf("%c\n", *(q + 1));
printf("%c\n", *(q + 2)); // print the char inside the address of s + 2

//now i will do this:
printf("%s\n", (q + 1)); // It will print the string q, starting from the q[1] onwards
printf("%s\n", (q + 2)); // it will print the string q, starting from the q[2] onwards character, up until the /0 null


}