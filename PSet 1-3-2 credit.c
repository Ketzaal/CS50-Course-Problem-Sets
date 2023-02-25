#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt user for input
    long number;
    number = get_long("Number: ");

    //Check length of card number
    int length = floor(log10(number)) + 1;
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = number;
    long y = number;
    int total = 0;
    int digit1mod1 = 0;
    int digit1mod2 = 0;
    do
    {
        int digit1 = (x % 100 - x % 10) / 10;
        x = x / 100;
        digit1 = digit1 * 2;
        digit1mod1 = digit1 % 10;
        digit1mod2 = digit1 / 10;
        sum1 = sum1 + digit1mod1 + digit1mod2;
    }
    while (x > 0);
    do
    {
        int digit2 = y % 10;
        y = y / 100;
        sum2 = sum2 + digit2;
    }
    while (y > 0);
    total = sum1 + sum2;

    //Check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Get first two digits
    long start = number;
    do
    {
        start = start / 10;
    }
    while (start > 100);
     
    //American Express
    if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
        
    //Matercard
    else if (length == 16 && (50 < start && start < 56))
    {
        printf("MASTERCARD\n");
    }
    //Visa
    else if ((length == 13 || length) && ((start / 10) == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");  
    }
}
