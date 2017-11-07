#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompt the user for the change owed
    int change;
    do
    {
        change = round(get_float("Change: ") * 100);
    }
    while ( change < 0 ); //reprompt until it meets the condition

    //available coins
    int quarter = 25,
        dime    = 10,
        nickle  = 5,
        pennie  = 1;

    //give least amount of coins for that change
    int coins = 0;
    while (change > 0)
    {
        if (change >= quarter)
        {
            change -= quarter;
            coins++;
        }
        else if (change >= dime)
        {
            change -= dime;
            coins++;
        }
        else if (change >= nickle)
        {
            change -= nickle;
            coins++;
        }
        else if (change >= pennie)
        {
            change -= pennie;
            coins++;
        }
        else
        {
            break;
        }
    }
    //return the number of coins
    printf("%i\n", coins);
    return 0;
}
