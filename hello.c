#include <cs50.h>
#include <stdio.h>

string askName(void);

int main(void)
{
    printf("hello, %s\n", askName());
}

string askName(void)
{
    string name = get_string("What's your name? ");
    return name;
}
