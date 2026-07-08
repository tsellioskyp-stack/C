#include<stdio.h>
#include<cs50.h>

int digits_count(long long card_number)
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
    int loop_count = digits_count(card_number) / 2;
    for (int i = 0; i < loop_count; i ++)
    {
        int second_digit = card_number % 100 / 10; // Get the second-to-last digit
        int first_digit = card_number % 10; // Get the last digit
        //printf("Second Digit: %d\n", second_digit);
        //printf("First Digit: %d\n", first_digit);
        card_number /= 100; // Remove the last two digits
        second_digit = second_digit * 2; // Multiply it by 2
        if (second_digit > 9)
        {
            second_digit -= 9; // If the result is greater than 9, subtract 9 from it
        }
        sum += second_digit + first_digit; // Add the result to the sum
    }
    if (card_number % 10 != 0)
    {
        sum += card_number % 10; // Add the last digit if the number of digits is odd
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
    
    long long card_number = get_long("Number: ");
    int total_digits = digits_count(card_number);
    //if it is not a numeric input, it reprompts the user for a valid input
    if (total_digits == 13 || total_digits == 15 || total_digits == 16)
    {
        // We are gonna check what bank the card belongs to
        //AMEX checking
        if ((total_digits == 15 && (card_number / 10000000000000LL == 34 || card_number / 10000000000000LL == 37)) && luhns_algorithm(card_number) == true)
        {
            printf("AMEX\n");
        }
        // VISA checking
        else if (((total_digits == 13 && card_number / 1000000000000LL == 4) || (total_digits == 16 && card_number / 1000000000000000LL == 4)) && luhns_algorithm(card_number) == true)
        {
            printf("VISA\n");
        }
        // MASTERCARD checking
        else if ((total_digits  == 16 && (card_number / 100000000000000LL >= 51 && card_number / 100000000000000LL <= 55)) && luhns_algorithm(card_number) == true)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}