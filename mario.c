#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int blockHeight=0;
    do{
        blockHeight=get_int("Height: ");
    }
    while(blockHeight>8||blockHeight<1);

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
