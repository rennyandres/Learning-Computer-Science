#include <stdio.h>
#include <cs50.h>
#include <math.h>

int divideInTwo(int num);

int main(void)
{
    //prompt the user for the CC number
    long long ccNum = get_long_long("Credit Card Number: ");

    if (ccNum < pow(10, 12))
    {
        printf("INVALID\n");
        return 0;
    }

    //get the length of the CC number
    long long length;

    if (ccNum > pow(10, 15))
    {
        length = 10000000000000000;
    }
    else if (ccNum > pow(10, 14))
    {
        length = 1000000000000000;
    }
    else if (ccNum > pow(10, 13))
    {
        length = 100000000000000;
    }
    else
    {
        length = 10000000000000;
    }

    long holder;
    int frst = 0;
    int scnd = 0;

    for (long long i = 1; i < length; i *= 10)
    {
        holder = ccNum / i;
        frst  += divideInTwo(holder % 10);

        if (i < length)
        {
            i *= 10;
            holder = ccNum / i;
            scnd += divideInTwo(holder % 10 * 2);
        }
        else
        {
            break;
        }
    }

    //find the CC provider
    if ((frst + scnd) % 10 == 0)
    {
        int frstDig = (ccNum / (length / 10)) % 10;
        int scnDig  = (ccNum / (length / 100)) % 10;

        if (frstDig == 4)
        {
            printf("VISA\n");
        }
        else if ( (frstDig == 3 && scnDig == 4) || (frstDig == 3 && scnDig == 7)   )
        {
            printf("AMEX\n");
        }
        else if ( (frstDig == 5 && scnDig == 1) ||
                  (frstDig == 5 && scnDig == 2) ||
                  (frstDig == 5 && scnDig == 3) ||
                  (frstDig == 5 && scnDig == 4) ||
                  (frstDig == 5 && scnDig == 5)   )
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int divideInTwo(int num)
{
    if (num > 9)
    {
        int left = num / 10;
        int right = num / 1;
        return (left % 10) + (right % 10);
    }
    else
    {
        return num;
    }
}
