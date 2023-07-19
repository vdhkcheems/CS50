#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define Block_Size 512

FILE *image;

int main(int argc, char *argv[])
{
    char filename[8];

    int count=0;


    if(argc != 2)
    {
        printf("USAGE: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if(card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    uint8_t buffer [Block_Size];

    while(fread(buffer, 1, 512, card)==512)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
        {
            if(count!=0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", count);
            count++;
            image = fopen(filename, "w");
        }
        if(image != NULL)
        {
            fwrite(buffer, 1, Block_Size, image);
        }
    }
    fclose(image);
    fclose(card);


}
