#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            if(average==27||average==126||average==136||average==146||average==156||average==250)
            {
                average++;
            }
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int tempR = 0;
    int tempB = 0;
    int tempG = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue=image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen=image[i][j].rgbtGreen;
            copy[i][j].rgbtRed=image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = copy[i][width - j+1].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][width - j+1].rgbtGreen;
            image[i][j].rgbtRed = copy[i][width - j+1].rgbtRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int averageR = 0;
    int averageB = 0;
    int averageG = 0;
    int surroundingPixels = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            averageR = 0;
            averageB = 0;
            averageG = 0;
            surroundingPixels = 1;
            if (i != 0)
            {
                averageR += image[i - 1][j].rgbtRed;
                averageR += image[i - 1][j - 1].rgbtRed;
                averageR += image[i - 1][j + 1].rgbtRed;
                averageB += image[i - 1][j].rgbtBlue;
                averageB += image[i - 1][j - 1].rgbtBlue;
                averageB += image[i - 1][j + 1].rgbtBlue;
                averageG += image[i - 1][j].rgbtGreen;
                averageG += image[i - 1][j - 1].rgbtGreen;
                averageG += image[i - 1][j + 1].rgbtGreen;
                surroundingPixels += 3;
            }
            if (i != height)
            {
                averageR += image[i + 1][j].rgbtRed;
                averageR += image[i + 1][j - 1].rgbtRed;
                averageR += image[i + 1][j + 1].rgbtRed;
                averageB += image[i + 1][j].rgbtBlue;
                averageB += image[i + 1][j - 1].rgbtBlue;
                averageB += image[i + 1][j + 1].rgbtBlue;
                averageG += image[i + 1][j].rgbtGreen;
                averageG += image[i + 1][j - 1].rgbtGreen;
                averageG += image[i + 1][j + 1].rgbtGreen;
                surroundingPixels += 3;
            }
            if (j != 0)
            {
                averageR += image[i][j - 1].rgbtRed;
                averageB += image[i][j - 1].rgbtBlue;
                averageG += image[i][j - 1].rgbtGreen;
                surroundingPixels += 1;
            }
            if (j != width)
            {
                averageR += image[i][j + 1].rgbtRed;
                averageB += image[i][j + 1].rgbtBlue;
                averageG += image[i][j + 1].rgbtGreen;
                surroundingPixels += 1;
            }
            averageR += image[i][j].rgbtRed;
            averageB += image[i][j].rgbtBlue;
            averageG += image[i][j].rgbtGreen;
            image[i][j].rgbtRed = round((averageR / surroundingPixels));
            image[i][j].rgbtBlue = round((averageB / surroundingPixels));
            image[i][j].rgbtGreen = round((averageG / surroundingPixels));
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gxR = 0;
    int gxB = 0;
    int gxG = 0;
    int gyR = 0;
    int gyB = 0;
    int gyG = 0;
    int gR = 0;
    int gB = 0;
    int gG = 0;
    int surroundingPixels = 9;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gxR = 0;
            gxB = 0;
            gxG = 0;
            gyR = 0;
            gyB = 0;
            gyG = 0;
            gR = 0;
            gB = 0;
            gG = 0;
            if (i != 0)
            {
                gyR += image[i - 1][j].rgbtRed * (-2);
                gyG += image[i - 1][j].rgbtGreen * (-2);
                gyB += image[i - 1][j].rgbtBlue * (-2);
            }
            if (i != 0 && j != 0)
            {
                gxR += image[i - 1][j - 1].rgbtRed * (-1);
                gxG += image[i - 1][j - 1].rgbtGreen * (-1);
                gxB += image[i - 1][j - 1].rgbtBlue * (-1);

                gyR += image[i - 1][j - 1].rgbtRed * (-1);
                gyG += image[i - 1][j - 1].rgbtGreen * (-1);
                gyB += image[i - 1][j - 1].rgbtBlue * (-1);
            }
            if (i != 0 && j != width)
            {
                gxR += image[i - 1][j + 1].rgbtRed;
                gxG += image[i - 1][j + 1].rgbtGreen;
                gxB += image[i - 1][j + 1].rgbtBlue;

                gyR += image[i - 1][j + 1].rgbtRed * (-1);
                gyG += image[i - 1][j + 1].rgbtGreen * (-1);
                gyB += image[i - 1][j + 1].rgbtBlue * (-1);
            }

            if (i != height)
            {
                gyR += image[i + 1][j].rgbtRed * 2;
                gyG += image[i + 1][j].rgbtGreen * 2;
                gyB += image[i + 1][j].rgbtBlue * 2;
            }

            if (i != height && j != width)
            {
                gxR += image[i + 1][j + 1].rgbtRed;
                gxG += image[i + 1][j + 1].rgbtGreen;
                gxB += image[i + 1][j + 1].rgbtBlue;

                gyR += image[i + 1][j + 1].rgbtRed;
                gyG += image[i + 1][j + 1].rgbtGreen;
                gyB += image[i + 1][j + 1].rgbtBlue;
            }

            if (i != height && j != 0)
            {
                gxR += image[i + 1][j - 1].rgbtRed * (-1);
                gxG += image[i + 1][j - 1].rgbtGreen * (-1);
                gxB += image[i + 1][j - 1].rgbtBlue * (-1);

                gyR += image[i + 1][j - 1].rgbtRed;
                gyG += image[i + 1][j - 1].rgbtGreen;
                gyB += image[i + 1][j - 1].rgbtBlue;
            }
            if (j != 0)
            {
                gxR += image[i][j - 1].rgbtRed * (-2);
                gxG += image[i][j - 1].rgbtGreen * (-2);
                gxB += image[i][j - 1].rgbtBlue * (-2);
            }
            if (j != width)
            {
                gxR += image[i][j + 1].rgbtRed * (2);
                gxG += image[i][j + 1].rgbtGreen * (2);
                gxB += image[i][j + 1].rgbtBlue * (2);
            }
            gyR = gyR / surroundingPixels;
            gyR *= gyR;

            gxR = gxR / surroundingPixels;
            gxR *= gxR;

            gyB = gyB / surroundingPixels;
            gyB *= gyB;

            gxB = gxB / surroundingPixels;
            gxB *= gxB;

            gyG = gyG / surroundingPixels;
            gyG *= gyG;

            gxG = gxG / surroundingPixels;
            gxG *= gxG;

            gR = gyR + gxR;
            gB = gyB + gxB;
            gG = gyG + gxG;
            image[i][j].rgbtRed = (int) sqrt(gR);
            image[i][j].rgbtBlue = (int) sqrt(gB);
            image[i][j].rgbtGreen = (int) sqrt(gG);
            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
        }
    }
    return;
}
