#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512
typedef uint8_t BYTE;

int checkSignature(BYTE block[BLOCKSIZE]);

int main(int argc, char *argv[])
{
    int serial=0;
    char stringifiedSerial[8];

    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    BYTE b;
    FILE *card= fopen(argv[1], "r");
    FILE *img;
    BYTE block[BLOCKSIZE];
    while(fread(block, 1, BLOCKSIZE,card)==512)
    {
        printf("%d, %d, %d, %d\n", block[0], block[1], block[2],block[3]);
    //detect slack space when more than a byte is filled with zeroes.
        if(checkSignature(block)==0)
        {

            if(serial>1)//CHECK IF THERE IS A DESTINATION FILE ALREADY OPEN AND CLOSE IT BEFORE OPENING A NEW ONE
            {
                fclose(img);
            }

            serial++;

            if(serial<10)
            {
                sprintf(stringifiedSerial, "00%d.jpg", serial);
            }else
            {
                sprintf(stringifiedSerial, "0%d.jpg", serial);
            }
        img=fopen(stringifiedSerial, "w");

        }
        fwrite(block, 1, BLOCKSIZE, img);
    }

    fclose(card);
    fclose(img);

}

int checkSignature(BYTE block[BLOCKSIZE])
{
    if(block[0]==block[2]&&block[1]==0xd8&&((block[3] & 0xf0) == 0xe0))
    {
        return 0;
    }
    return 1;
}