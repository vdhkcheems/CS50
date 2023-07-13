#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int N;
    do
    {
        N = get_int("How many numbers do you want to average out: ");
    }
    while(N < 0);

    int Number[N];
    for (int i=0; i<N; i++)
    {
        Number[i] = get_int("Number %i = ", i+1);
    }

    int sum=0;
    for(int j=0; j<N; j++)
    {
        sum += Number[j];
    }

    printf("Average = %.3f\n", sum / (float) N);
}