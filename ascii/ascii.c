#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define SCALE 6

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s image.jpg\n", argv[0]);
        return 1;
    }

    int width;
    int height;
    int channels;

    unsigned char *image = stbi_load(
        argv[1],
        &width,
        &height,
        &channels,
        3
    );

    if (image == NULL)
    {
        printf("Could not load image.\n");
        return 1;
    }

    // Dark -> light
    const char *ascii = "@%#*+=-:. ";
    int ascii_levels = 10;

    for (int y = 0; y < height; y += SCALE)
    {
        for (int x = 0; x < width; x += SCALE)
        {
            int pixel = (y * width + x) * 3;

            int r = image[pixel];
            int g = image[pixel + 1];
            int b = image[pixel + 2];

            // RGB -> grayscale
            int gray = (r + g + b) / 3;

            // 0-255 -> 0-9
            int index = gray * (ascii_levels - 1) / 255;

            printf("%c", ascii[index]);
        }

        printf("\n");
    }

    stbi_image_free(image);

    return 0;
}