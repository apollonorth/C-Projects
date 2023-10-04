//Description: This program will decide  what arrangement of coins should be returned to a customer based on the change owed.
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("Quarters: %i\n", quarters);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    printf("Dimes: %i\n", dimes);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    printf("Nickels: %i\n", nickels);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    printf("Pennies: %i\n", pennies);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Total coins: %i\n", coins);
}

// Get cents owed, continue prompt until greater than 0
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("How many cents are owed? ");
    }
    while (cents < 0);
    return (cents);
}

// Calculate quarters necessary, while loop because it should not be executed at all unless cents is greater than or equal to 25
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters ++;
        cents -= 25;
    }
    return (quarters);
}

// Calculate dimes necessary, while loop because it should not be executed at all unless cents is greater than or equal to 10
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes ++;
        cents -= 10;
    }
    return (dimes);
}

//Calculate nickels necessary, while loop because it should not be executed at all unless cents is greater than or equal to 5
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels ++;
        cents -= 5;
    }
    return (nickels);
}

// Calculate pennies necessary, while loop because it should not be executed at all unless cents is greater than or equal to to 1
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies ++;
        cents -= 1;
    }
    return (pennies);
}
