#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("height of pyramid: ");
    }
    while (n < 1);
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
        m++;
        printf("\n");
    }
}