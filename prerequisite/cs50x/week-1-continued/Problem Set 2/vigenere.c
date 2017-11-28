#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //return error if there's no sequence of keys
    if (argc != 2)
    {
        return 1;
    }
    else
    {
        //extract the integer from each key
        int keyCodes[strlen(argv[1])];

        for (int i = 0; i < strlen(argv[1]); i++ )
        {
            if (isupper(argv[1][i]))
            {
                if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                {
                    keyCodes[i] = argv[1][i] - 'A';
                }
                //return error for non letter keys
                else
                {
                    return 1;
                }
            }
            else
            {
                if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                    keyCodes[i] = argv[1][i] - 'a';
                }
                else
                {
                    return 1;
                }
            }
        }

        //ask for plaintext
        string plaintxt;
        do
        {
            plaintxt = get_string("plaintext: ");
        }
        while (strlen(plaintxt) == 0);

        //encrypt each character
        for (int i = 0, j = 0; i < strlen(plaintxt); i++, j++)
        {
            if ((plaintxt[i] >= 'A' && plaintxt[i] <= 'Z') || (plaintxt[i] >= 'a' && plaintxt[i] <= 'z'))
            {
                //if all keys are used, start from index 0 again
                if (j >= strlen(argv[1]))
                {
                    j = 0;
                }

                if (isupper(plaintxt[i]))
                {
                    int newLetter = plaintxt[i] + keyCodes[j];

                    //only shift characters within a - z
                    while (newLetter > 'Z')
                    {
                        newLetter =  '@' + newLetter - 'Z';
                    }

                    plaintxt[i] = newLetter;
                }
                else
                {
                    int newLetter = plaintxt[i] + keyCodes[j];

                    while (newLetter > 'z')
                    {
                        newLetter =  '`' + newLetter - 'z';
                    }

                    plaintxt[i] = newLetter;
                }
            }
        }
        //print the ciphertext
        printf("ciphertext: %s\n", plaintxt);
    }

    return 0;
}