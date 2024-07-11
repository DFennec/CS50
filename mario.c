#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int blockHeight=get_int("Set the height of the pyramid: \n");
    while(blockHeight>8||blockHeight<1)
    {
        printf("Invalid input: Height must be between 1 and 8 \n");
        blockHeight=get_int("Set the height of the pyramid: \n");
    }

    for(int i=0;i<blockHeight;i++)
    {
        for(int j=0;j<blockHeight-i;j++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("#");
        }
        printf("  ");
        for(int j=0;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
}
