/*
Description: This program will decide the validity using Luhn's algorithm, and also determine the type of credit card based on its card number.
*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sum = 0;
    // Get number from user
    long card = get_long("Card number: ");

    // Check number of digits
    long n = card;
    int digits = 0;
    while (n > 0)
    {
        (n /= 10);
        digits ++;
    }

    // Make sure number of digits could be valid card
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Check if Luhn's Algorithm works
    for (n = card, digits = 0; n > 0; n /= 10)
    {
        digits ++;
        int x = n % 10;
        if (digits % 2 == 0)
        {
            if ((x * 2) > 9)
            {
                sum += (x * 2) - 9;
            }
            else
            {
                sum += x * 2;
            }
        }
        else
        {
            sum += x;
        }
    }

    printf("SUM: %i\n", sum);
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Print card type
    if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if (card >= 5100000000000000 && card < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }
    else if ((card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000 && card < 5000000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
