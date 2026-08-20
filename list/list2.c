#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{

    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node)); // size is: 4 bytes of in + 8 bytes for pointer = 12 bytes
        if (n == NULL)
        {
        return 1;
        }
        (*n).number = get_int("Number: ");
        //or n->number
        (*n).next = NULL;

        //Prepend node to list
        n->next = list;
        list = n;
    }

    //Print numbers
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    //for loop:
    // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    //{
    //    printf("i%\n", ptr->number);
    //}
    return 0;
}