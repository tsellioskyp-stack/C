#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //initializing dynamic stack
    int n = 0;
    char c;
    int q;
    int *list = malloc(sizeof(int));
    if (list == NULL)
        return 1;
    printf("Want to add a contact? (Y/N): ");
    scanf(" %c", &c);
    while (c != 'N' && c != 'n' && c != 'y' && c != 'Y')
    {
        printf("Invalid selection, try again: ");
        scanf(" %c", &c);
    }
    if (c == 'n' || c == 'N')
    {
        free(list);
        return 0;
    }
    while (c == 'y' || c == 'Y')
    {
        //start of looping inputs on stack
        n++;
        printf("New number to add: ");
        scanf("%i", &q);
        int *tmp = malloc(n * sizeof(int));
        if (tmp == NULL)
        {
            free(list);
            return 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            tmp[i] = list[i];
        }
        tmp[n-1] = q;
        free(list);
        list = malloc(n * sizeof(int));
        if (list == NULL)
        {
            free(tmp);
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            list[i] = tmp[i];
            printf("i = %i  num = %i", i, list[i]);
        }
        free(tmp);
        printf("Want to add a contact? (Y/N): ");
        scanf(" %c", &c);

    }
    free(list);
    return 0;
    
    
}