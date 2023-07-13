#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("change owed: ");
    }
    while (n < 0);

    int a = n % 25./;
    int b = n / 25;
    int c = a % 10;
    int d = a / 10;
    int e = c % 5;
    int f = c / 5;
    int g = e / 1;

    printf("%i\n", b + d + f + g);
    printf("25c - %i\n", b);
    printf("10c - %i\n", d);
    printf("5c - %i\n", f);
    printf("1c - %i\n", g);
}