#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512
typedef uint8_t BYTE;

int checkSignature(BYTE block[BLOCKSIZE]);

int main(int argc, char *argv[])
{
    int serial = 0;
    char stringifiedSerial[16]; // Larger buffer for serial number

    if (argc != 2) {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    BYTE block[BLOCKSIZE];
    FILE *card = fopen(argv[1], "r");
    if (card == NULL) {
        fprintf(stderr, "Error opening card file\n");
        return 1;
    }

    FILE *img = NULL;

    while (fread(block, 1, BLOCKSIZE, card) == BLOCKSIZE) {
        if (checkSignature(block) == 0) {
            if (img != NULL) {
                fclose(img);
            }

            sprintf(stringifiedSerial, "%03i.jpg", serial);
            img = fopen(stringifiedSerial, "w");
            if (img == NULL) {
                fprintf(stderr, "Error creating image file\n");
                return 1;
            }
            serial++;
        }

        if (img != NULL) {
            fwrite(block, 1, BLOCKSIZE, img);
        }
    }

    if (img != NULL) {
        fclose(img);
    }
    fclose(card);

    return 0;
}

int checkSignature(BYTE block[BLOCKSIZE])
{
    // Consider improving the signature check as needed
    if (block[0] == block[2] && block[1] == 0xd8 && ((block[3] & 0xf0) == 0xe0)) {
        return 0;
    }
    return 1;
}
