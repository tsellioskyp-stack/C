#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float indexed(string text);

int main(void)
{
    string text = get_string("Text Input: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
    }
    int result = (int)round(indexed(text));
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 1 && result <= 16)
    {
        printf("Grade %i\n", result);
    }
    else
    {
        printf("Grade 16+\n");
    }
    //printf("%i", result);
}

float indexed(string text)
{
    int word_count = 0;
    int letter_count = 0;
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
            //count the sentences + ending word:
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
            word_count++;
        }
        //letter count
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter_count++;
        }
        //word counter
        else if (i != 0)
        {
            if ((text[i] == ' ' || text[i] == ',' || text[i] == ':') && (text[i-1] >= 'A' && text[i] <= 'Z' ))
            {
                word_count++;
            }
        else
            {
                continue;
            }
        }
    }
    float l = (100 * ((float)letter_count / word_count));
    float s = (100 * ((float)sentence_count / word_count));
    float cli = (0.0588f * l  - 0.296f * s - 15.8f);
    return cli;
    //printf("Sentence count: %i\nLetter COunt: %i\nWord Count: %i\n", sentence_count, letter_count, word_count);
}