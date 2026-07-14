#include <stdio.h>
#include <cs50.h>

float averages(int scores[], int length);
int main(void)
{
   const int N = 3;
   int scores[N];
   for (int i = 0; i < N; i++)
   {
       scores[i] = get_int("Enter score %d: ", i);
   }
   printf("Avergae Scores: %f\n", averages(scores, N));
}

float averages(int scores[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += scores[i];
    }
    return (float) sum / length;
}

// alternatively, i can create an ARRAY to store the scores and calculate the average using a loop. This would make it easier to handle a variable number of scores in the future.
//for example, I could declare an array like this:
//int scores[3] = {85, 90, 78};
//or
//int scores[3];
//scores[0] = 85;
//scores[1] = 90;
//scores[2] = 78;

//or 

//I could use a loop to input the scores from the user and store them in the array, then calculate the average using another loop. This would make the program more flexible and user-friendly.
//for example, I could use a for loop to input the scores like this:
//for (int i = 0; i < 3; i++)
//{
    //printf("Enter score %d: ", i);
    //scanf("%d", &scores[i]);
    //}

//or suing cs50 library, I could use the get_int function to input the scores like this:
//for (int i = 0; i < 3; i++)
//{
    //scores[i] = get_int("Enter score %d: ", i);
    //}