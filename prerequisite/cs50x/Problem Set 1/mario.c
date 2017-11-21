#include <stdio.h>
#include <cs50.h>

void printRow(int spaces, int blocks);

int main(void)
{
    //ask for the pyramid height
    int rows = get_int("Height: ");
    while (rows < 0 || rows > 23)
    {
        rows = get_int("Retry: ");
    }

    //now print row by row
    for (int i = 1; i <= rows; i++)
    {
        printRow(rows - i, i);
        printf("  ");
        printRow(0, i);
        printf("\n");
    }
}

void printRow(int spaces, int blocks)
{
    //print spaces in the row
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    //print blocks in the row
    for (int j = 0; j < blocks; j++)
    {
        printf("#");
    }
}
