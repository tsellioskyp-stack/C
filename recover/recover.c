#include <stdio.h>
#include <stdlib.h>

#define FAT 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    BYTE b[FAT];
    FILE *output = NULL;
    int file_counter = 0;

    if (argc != 2)
    {
        printf("Usage: ./recover [image dir]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");

    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    while (fread(b, 1, FAT, input) == FAT)
    {
        if (b[0] == 0xFF &&
            b[1] == 0xD8 &&
            b[2] == 0xFF &&
            (b[3] & 0xF0) == 0xE0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            char filename[9];
            sprintf(filename, "%04i.jpg", file_counter);

            output = fopen(filename, "wb");

            if (output == NULL)
            {
                printf("Could not open file.\n");
                fclose(input);
                return 2;
            }

            file_counter++;
        }

        if (output != NULL)
        {
            fwrite(b, 1, FAT, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);

    return 0;
}