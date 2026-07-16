#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int point(char c);

int main(void)
{
    int scores[2];
    int total = 0;
    string word1 = get_string("Player 1: ");
        //Uppercasing
    for (int i = 0, n = strlen(word1); i < n; i++)
        {
            word1[i] = toupper(word1[i]);
            if (word1[i] >= 'A' && word1[i] <= 'Z')
            {
                total = total + point(word1[i]);
            }
            else
            {
                continue;
            }
        }
    scores[0] = total;

    total = 0;
    word1 = get_string("Player 2: ");
    //Uppercasing
    for (int i = 0, n = strlen(word1); i < n; i++)
        {
            word1[i] = toupper(word1[i]);
            if (word1[i] >= 'A' && word1[i] <= 'Z')
            {
                total = total + point(word1[i]);
            }
            else
            {
                continue;
            }
        }
    scores[1] = total;

    //Printing result (Win/Lose/Tie)
    if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (scores[0] < scores[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int point(char c)
{
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
         'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
          'T', 'U', 'V', 'Y', 'X', 'Y', 'Z'};
    int point[26] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
    1, 4, 4, 8, 4, 10};
    int index = c - 'A';
    return point[index];
}