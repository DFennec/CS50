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
    char stringifiedSerial[16];

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

        if(checkSignature(block)==0)
        {

            if(serial>0)
            {
                fclose(img);
            }

             sprintf(stringifiedSerial, "%03i.jpg", serial);
             img=fopen(stringifiedSerial, "w");
             serial++;

        }
        if (img != NULL) {
            fwrite(block, 1, BLOCKSIZE, img);
        }
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
