#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argCount, string argVector[])
{

    if (argCount == 2)
    {
        int key = atoi(argVector[1]);
        string mssg;
        do
        {
            mssg = get_string("plaintext: ");
        }
        while (strlen(mssg) == 0);

        for (int i = 0; i < strlen(mssg); i++ )
        {
            //Change letters only
            if ((mssg[i] >= 'A' && mssg[i] <= 'Z') || (mssg[i] >= 'a' && mssg[i] <= 'z'))
            {
                int newLetter = mssg[i] + key;

                //Make sure to change to a letter only
                if (isupper(mssg[i]))
                {
                    while (newLetter > 'Z')
                    {
                        newLetter = '@' + newLetter - 'Z';
                    }
                    mssg[i] = newLetter;
                }
                else
                {
                    while (newLetter > 'z')
                    {
                        newLetter = '`' + newLetter - 'z';
                    }
                    mssg[i] = newLetter;
                }
            }
        }

        printf("ciphertext: %s\n", mssg);

    }
    else if (argCount == 1)
    {
        return 1;
    }
    else
    {
        printf("Usage: ./caesar key(int)\n");
    }

    return 0;
}