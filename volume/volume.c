// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
short TWOBYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); //atof will convert the string argv[3] into a float. If the argv[3] is a non-numeric value, it returns 0.00
    if (factor == 0)
    {
        printf("Invalid factor. Must be a numeric element!\n");
        return 1;
    }
    //Copy the header from source (input) to destination file (output)
    int count = 0;
    while (fread(&TWOBYTE, sizeof(TWOBYTE), 1, input) != 0)
    // Will read the contents of size: FOURBYTE, one τετράδα at a time, from output, and will store in the FOURBYTE. Θα το εκτελέσει έως ώτου να γίνει το count = 11, άρα 11 φορές ξεκινώντας από το 0, οπότε θα διαβάσει/γράψει 11 φορές από 4 bytes == 44 bytes
    {
        if (count != 22)
        {
            fwrite(&TWOBYTE, sizeof(TWOBYTE), 1, output);
            count++;
        }
        else
        {
            TWOBYTE *= factor;
            fwrite(&TWOBYTE, sizeof(TWOBYTE), 1, output);
        }
        
    }
    // Close files
    fclose(input);
    fclose(output);
}
