#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    #define FAT 512
    typedef unsigned char BYTE;
    BYTE b[FAT];
    FILE *output = NULL;
    int file_counter = 0;
    // First error: Incorrect call of command in the terminal. Return code 1
    if (argc != 2)
    {
        printf("Usage: ./recover [image dir]\n");
        return 1;
    }
    //Second error-catching would be when trying to read the input file. Return code 1 also
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // Writing on new file/files will take place inside the for loop, because we do not know how many output files we'll have
    while (fread(b, 1, FAT, input) == FAT) //Read 512 chunks of the size of 1 byte, at a time
    {
        if  (*b == 0xFF &&
            *(b + 1) == 0xD8 &&
            *(b + 2) == 0xFF &&
            (*(b + 3) & 0xF0) == 0xE0)
        {
            if (output != NULL)
            {
                fclose(output);
            }
            //We found the array of 3bytes(FFD8FF) + half byte(E) that gives away a JPEG file is being plotted up ahead.
            char filename[9];
            sprintf(filename, "%04i.jpg", file_counter);
            output = fopen(filename, "wb");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 2;
            }
            file_counter++;
            // If a JPEG has been found, write this block
        }
        if (output != NULL)
            {
                fwrite(b, 1, FAT, output); //Write the array we found on the raw first, then start scanning the rest of the file, until we hit the start of the next jpeg file
            }
        else
            continue;
    }
}