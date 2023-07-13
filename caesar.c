#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool only_digits(string s);

int main (int argc, string argv[])
{
    if(argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]);

        string pt = get_string("Plaintext:  ");

        int M = strlen(pt);

        int x[M];

        for (int j=0; j < M; j++)
        {
            if(isupper(pt[j]))
            {
                pt[j] -= 65;
                x[j] = (pt[j] + k) % 26;
                x[j] += 65;
            }
            else if(islower(pt[j]))
            {
                pt[j]-=97;
                x[j]= (pt[j] + k) % 26;
                x[j] += 97;
            }
            else
            {
                x[j]=pt[j];
            }
        }

        printf("Ciphertext: ");

        for(int l=0; l < M; l++)
        {
            printf("%c", x[l]);
        }

        printf("\n");
    }
}

bool only_digits(string s)
{
    int N = strlen(s);

    for(int i=0; i < N; i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}