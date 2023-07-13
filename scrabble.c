#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int x = compute_score(word1);
    int y = compute_score(word2);

    if (x > y)
    {
        printf("Player 1 wins!\n");
    }
    else if (x < y)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}



int compute_score(string word)
{
    int sum = 0;

    for(int i=0; i < strlen(word) ; i++)
    {
        if(isupper(word[i]))
        {
            sum += Points[word[i]-'A'];
        }
        else if(islower(word[i]))
        {
            sum += Points[word[i]-'a'];
        }
    }

    return sum;
}