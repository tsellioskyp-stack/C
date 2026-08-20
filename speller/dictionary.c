// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <string.h>
#include <stdlib.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
#define N 676 //Taking in account the second letter of a word
int count = 0;      //count of individual words parsed from dictionary during the load()
bool loaded = false;    //Will change to true if load fucntion works

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int h = hash(word);
    for (node *ptr = table[h]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)       //Equality
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (word[1] == '\0')
    {
        return toupper(word[0]) - 'A';
    }

    return (toupper(word[0]) - 'A') * 26
         + (toupper(word[1]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    node *nod = NULL; //Initialize
    char c;
    char word[LENGTH + 1];
    int index = 0;
    int hash_index;
    FILE *dict= fopen(dictionary, "r");
    if (dict == NULL)
        return false;
    while (fread(&c, sizeof(char), 1, dict) != 0)   //start reading one character at a time
    {
        if (isalpha(c) || (c == '\'')) //if read character is indeed a letter a-z, A-Z
        {
            //add character to temp char holder word
            word[index] = c;
            index++;
        }
        else if (c == '\n')
        {
            word[index] = '\0';
            //word ended, will malloc space for a node *n that will hold the read word
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            // Create a node to house the word we just fread'ed

            strcpy(n->word, word);

            //Reset index for next word

            index = 0;

            //will prepend the node to the table of nodes

            hash_index = hash(word);
            n->next = table[hash_index];
            table[hash_index] = n;
            count++;
        }

    }
    loaded = true;
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        for (; ptr != NULL;)
        {
            node *n = ptr->next;
            free(ptr);
            ptr = n;
        }
        if (i == N - 1)
        {
            return true;
        }
    }
    return false;
}
