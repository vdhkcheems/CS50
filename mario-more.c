#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (n < 1 || n > 8);

    int m = 1;
    int l = n - 1;
    for (int i = 0 ; i < n; i++)
    {
        for (int k = 0; k < l; k++)
        {
            printf(" ");
        }
        l--;
        for (int j = 0; j < m; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int o =0; o < m; o++)
        {
            printf("#");
        }
        m++;
        printf("\n");
    }
}