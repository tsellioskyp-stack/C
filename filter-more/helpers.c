#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) //RGBTRIPLE: 

//typedef struct
//{
//    BYTE rgbtBlue;
//    BYTE rgbtGreen;
//    BYTE rgbtRed;
//}
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int mean = round(((image[i][j]).rgbtBlue + (image[i][j]).rgbtRed + (image[i][j]).rgbtGreen) / 3.0); //I opened bmp.h for reference
            image[i][j].rgbtBlue = mean;
            image[i][j].rgbtRed = mean;
            image[i][j].rgbtGreen = mean;
            
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
//if the bitmap image has an even width (divisible by 2, %2 = 0) all the pixels will be shifted. If it odd (%2 != 0)), the dead center column of pixels, will not be shifted.
//for even width:
{
    RGBTRIPLE temp;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width / 2); j++)
            {
                temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
            }
        }    
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = 0;
            int green = 0;
            int red = 0;
            int count = 0;

            if (i == 0 && j == 0)
            {
                // Top-left
                for (int x = 0; x <= 1; x++)
                {
                    for (int y = 0; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (i == 0 && j == width - 1)
            {
                // Top-right
                for (int x = 0; x <= 1; x++)
                {
                    for (int y = -1; y <= 0; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (i == height - 1 && j == 0)
            {
                // Bottom-left
                for (int x = -1; x <= 0; x++)
                {
                    for (int y = 0; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (i == height - 1 && j == width - 1)
            {
                // Bottom-right
                for (int x = -1; x <= 0; x++)
                {
                    for (int y = -1; y <= 0; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (i == 0)
            {
                // Top edge
                for (int x = 0; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (i == height - 1)
            {
                // Bottom edge
                for (int x = -1; x <= 0; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (j == 0)
            {
                // Left edge
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = 0; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else if (j == width - 1)
            {
                // Right edge
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 0; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }
            else
            {
                // Center
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        blue += image[i+x][j+y].rgbtBlue;
                        green += image[i+x][j+y].rgbtGreen;
                        red += image[i+x][j+y].rgbtRed;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtBlue = round(blue / (float) count);
            temp[i][j].rgbtGreen = round(green / (float) count);
            temp[i][j].rgbtRed = round(red / (float) count);
        }
    }

    // Copy blurred image back
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int kgx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int kgy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    typedef struct
    {
        int red;
        int green;
        int blue;
    } g;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            g sumgx = {0, 0, 0};
            g sumgy = {0, 0, 0};

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int ni = i + x;
                    int nj = j + y;

                    // Ignore pixels outside image boundaries
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumgx.red += image[ni][nj].rgbtRed * kgx[x + 1][y + 1];
                        sumgx.green += image[ni][nj].rgbtGreen * kgx[x + 1][y + 1];
                        sumgx.blue += image[ni][nj].rgbtBlue * kgx[x + 1][y + 1];

                        sumgy.red += image[ni][nj].rgbtRed * kgy[x + 1][y + 1];
                        sumgy.green += image[ni][nj].rgbtGreen * kgy[x + 1][y + 1];
                        sumgy.blue += image[ni][nj].rgbtBlue * kgy[x + 1][y + 1];
                    }
                }
            }
            int red = round(sqrt(sumgx.red * sumgx.red + sumgy.red * sumgy.red));
            int green = round(sqrt(sumgx.green * sumgx.green + sumgy.green * sumgy.green));
            int blue = round(sqrt(sumgx.blue * sumgx.blue + sumgy.blue * sumgy.blue));
            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }
    //copy edged image from temp, to the OG:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
