#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Keep track of coins used
    int coins = 0;
    
    //Prompt for user input
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // Convert to cents
    int cents = round(dollars * 100);
    
    //Quarters
    while (cents > 24)
    {
        cents = cents - 25;
        coins++;
    }
    
    //Dimes
    while (cents > 9)
    {
        cents = cents - 10;
        coins++;
    }
    
    
    //Nickels
    while (cents > 4)
    {
        cents = cents - 5;
        coins++;
    }
    
    //Pennies
    while (cents > 0)
    {
        cents = cents - 1;
        coins++;
    }
    
    printf("%i\n", coins);
}