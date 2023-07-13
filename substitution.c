#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

bool isvalid(string s);

bool checkrepeat(string S);

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else
    {
        if(!isvalid(argv[1]))
        {
            return 1;
        }
        else if(!checkrepeat(argv[1]))
        {
            return 1;
        }
        else
        {
            string pt = get_string("Plaintext:  ");

            for(int i=0; i<strlen(pt); i++)
            {
                if(isupper(pt[i]))
                {
                    for(int j=0; j < 26; j++)
                    {
                        if(pt[i]=='A'+j)
                        {
                            pt[i]=toupper(argv[1][j]);
                            break;
                        }
                    }
                }
                if(islower(pt[i]))
                {
                    for (int k=0; k < 26; k++)
                    {
                        if(pt[i]=='a'+k)
                        {
                            pt[i]=tolower(argv[1][k]);
                            break;
                        }
                    }
                }
            }

            printf("ciphertext: %s\n", pt);
        }
    }
}

bool isvalid(string s)
{

    if(strlen(s) != 26)
    {
        printf("Key must be 26 characters\n");
        return false;
    }
    else
    {
        for(int i=0; i<strlen(s); i++)
        {
            if(!isalpha(s[i]))
            {
                printf("key must only contain alphabets\n");
                return false;
            }
        }
    }
        return true;
}

bool checkrepeat(string S)
{
    char x[strlen(S)];
    for (int i=0; i<strlen(S); i++)
    {
        x[i]=tolower(S[i]);
    }

    for(int j=0; j<strlen(S)-1; j++)
    {
        for(int k=j+1; k<strlen(S); k++)
        {
            if(x[j]==x[k])
            {
                printf("key mustn't contain repeated characters\n");
                return false;
            }
        }
    }
    return true;
}

