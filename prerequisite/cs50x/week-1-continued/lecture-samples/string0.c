#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("input: ");

    printf("output: \n");

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n", s[i]);
    }

    return 0;
}