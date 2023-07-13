#include<cs50.h>
#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string Text = get_string("Text: ");

    int N = strlen(Text);

    int letters = 0;
    for (int i=0; i<N; i++)
    {
        if (isalpha(Text[i]))
        {
            letters++;
        }
    }

    int words = 0;
    for(int j=0; j<N; j++)
    {
        if (isspace(Text[j]))
        {
            words++;
        }
    }
    words++;

    int sentences = 0;
    for(int k=0; k<N; k++)
    {
        if(Text[k]==46 || Text[k]==33 || Text[k]==63)
        {
            sentences++;
        }
    }

    float L = ((float)letters / words) * 100.0;
    float S = ((float)sentences / words) * 100.0;

    float G = 0.0588 * L - 0.296 * S - 15.8;

    G = round(G);

    if(G<1)
    {
        printf("Before Grade 1\n");
    }
    else if(G>=16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)G);
    }
}