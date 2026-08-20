#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

struct node *n;

void main(void)
{
    printf("haha");
    search(n, 50);
}

bool search(node *tree, int number)
{

    if (tree == NULL)
        return false;
    else if (number < tree->number)
        return search(tree->left, number);
    else if (number > tree->number)
        return search(tree->right, number);
    else if (number == tree->number)
        return true;
}