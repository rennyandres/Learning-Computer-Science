#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("string: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        toupper(s[i]));
    }

    printf("\n");
}