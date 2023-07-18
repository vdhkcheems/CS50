#include "helpers.h"
#include <math.h>
int rgb_cap(int xp);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i < height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            float avg = sum / 3.0;
            int a = round(avg);
            image[i][j].rgbtBlue = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtRed = a;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[1][1];
    for(int i=0; i<height; i++)
    {
        for(int j=0, m=width/2; j<m; j++)
        {
            copy[0][0]=image[i][j];
            image[i][j]=image[i][width-(j+1)];
            image[i][width -(j+1)]=copy[0][0];
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float counter = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }

                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + r][j + c].rgbtBlue;
                    sumGreen += image[i + r][j + c].rgbtGreen;
                    sumRed += image[i + r][j + c].rgbtRed;
                    counter++;
                }
            }

            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }

    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int xsumblue =0;
            int xsumgreen =0;
            int xsumred =0;
            int ysumblue =0;
            int ysumred =0;
            int ysumgreen =0;
            for (int r=-1; r<2; r++)
            {
                for (int c=-1; c<2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }

                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    if(r==-1 && c==-1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* -1;
                        xsumred += image[i+r][j+c].rgbtRed* -1;
                        xsumgreen += image[i+r][j+c].rgbtGreen* -1;
                        ysumblue += image[i+r][j+c].rgbtBlue* -1;
                        ysumred += image[i+r][j+c].rgbtRed* -1;
                        ysumgreen += image[i+r][j+c].rgbtGreen* -1;
                    }

                    if(r==0 && c==-1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* -2;
                        xsumred += image[i+r][j+c].rgbtRed* -2;
                        xsumgreen += image[i+r][j+c].rgbtGreen* -2;
                    }

                    if(r==1 && c==-1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* -1;
                        xsumred += image[i+r][j+c].rgbtRed* -1;
                        xsumgreen += image[i+r][j+c].rgbtGreen* -1;
                        ysumblue += image[i+r][j+c].rgbtBlue* 1;
                        ysumred += image[i+r][j+c].rgbtRed* 1;
                        ysumgreen += image[i+r][j+c].rgbtGreen* 1;
                    }

                    if(r==-1 && c==1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* 1;
                        xsumred += image[i+r][j+c].rgbtRed* 1;
                        xsumgreen += image[i+r][j+c].rgbtGreen* 1;
                        ysumblue += image[i+r][j+c].rgbtBlue* -1;
                        ysumred += image[i+r][j+c].rgbtRed* -1;
                        ysumgreen += image[i+r][j+c].rgbtGreen* -1;
                    }

                    if(r==0 && c==1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* 2;
                        xsumred += image[i+r][j+c].rgbtRed* 2;
                        xsumgreen += image[i+r][j+c].rgbtGreen* 2;
                    }

                    if(r==1 && c==1)
                    {
                        xsumblue += image[i+r][j+c].rgbtBlue* 1;
                        xsumred += image[i+r][j+c].rgbtRed* 1;
                        xsumgreen += image[i+r][j+c].rgbtGreen* 1;
                        ysumblue += image[i+r][j+c].rgbtBlue* 1;
                        ysumred += image[i+r][j+c].rgbtRed* 1;
                        ysumgreen += image[i+r][j+c].rgbtGreen* 1;
                    }
                    if(r==-1 && c==0)
                    {
                        ysumblue += image[i+r][j+c].rgbtBlue* -2;
                        ysumred += image[i+r][j+c].rgbtRed* -2;
                        ysumgreen += image[i+r][j+c].rgbtGreen* -2;
                    }
                    if(r==1 && c==0)
                    {
                        ysumblue += image[i+r][j+c].rgbtBlue* 2;
                        ysumred += image[i+r][j+c].rgbtRed* 2;
                        ysumgreen += image[i+r][j+c].rgbtGreen* 2;
                    }

                }
            }
            temp[i][j].rgbtBlue = round(sqrt(((float)xsumblue*xsumblue) + ((float)ysumblue*ysumblue)));
            temp[i][j].rgbtGreen = round(sqrt(((float)xsumgreen*xsumgreen) + ((float)ysumgreen*ysumgreen)));
            temp[i][j].rgbtRed = round(sqrt(((float)xsumred*xsumred) + ((float)ysumred*ysumred)));
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = rgb_cap(temp[i][j].rgbtBlue);
            image[i][j].rgbtGreen = rgb_cap(temp[i][j].rgbtGreen);
            image[i][j].rgbtRed = rgb_cap(temp[i][j].rgbtRed);
        }

    }

    return;
}

int rgb_cap(int xp)
{
    if (xp > 255)
    {
        xp = 255;
        return xp;

    }
    return xp;
}
