/*
Linking other files through libraries
for the compiling process
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Name: ");
    printf("hello, %s\n", name);
    return 0;
}
