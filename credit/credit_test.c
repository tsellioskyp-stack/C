#include<stdio.h>
#include<cs50.h>
#include<math.h>

int total_digits(long long card_number)
{
    int count = 0;
    while (card_number != 0)
    {
        card_number /= 10;
        count++;
    }
    return count;
}

bool luhns_algorithm(long long card_number)
{
    int sum = 0;
    int loop_count = total_digits(card_number) / 2;
    for (int i = 0; i < loop_count; i ++)
    {
        int second_digit = card_number % 100 / 10; // Get the second-to-last digit
        int first_digit = card_number % 10; // Get the last digit
        printf("Second Digit: %d\n", second_digit);
        printf("First Digit: %d\n", first_digit);
        card_number /= 100; // Remove the last two digits
        second_digit = second_digit * 2; // Multiply it by 2
        if (second_digit > 9)
        {
            second_digit = second_digit - 9; // If the result is greater than 9, subtract 9 from it
        }
        sum = second_digit + first_digit; // Add the result to the sum
    }
    if (sum % 10 == 0)
    {
        return true; // Valid card number
    }
    else
    {
        return false; // Invalid card number
    }
}
int main(void)
{
    long card_number = get_long("Number: ");
    //if it is not a numeric input, it reprompts the user for a valid input
    luhns_algorithm(card_number);
    printf("Total Digits: %d\n", digits_count(card_number));
}