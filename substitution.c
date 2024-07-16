#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


string encrypt(string cypher,string message);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
        string key=argv[1];
    if(strlen(key)!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char curLetter='a';
    char previousLetters='a';
    for(int i = 0, n=strlen(key);i<n;i++)
    {
        curLetter=key[i];
        if(isalpha(curLetter)==0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else
        {
            for(int j = 0;j<i;j++)
            {
                previousLetters=key[j];
                if(toupper(curLetter)==toupper(previousLetters))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }
    string message=get_string("plaintext: ");
    printf("ciphertext: %s\n",encrypt(key, message));
}

string encrypt(string cypher,string message)
{
    string cyphertext=malloc(strlen(message)+1);
    int cypherPosition=0;
    char currentMessageLetter='a';

    for (int i = 0, n = strlen(message);i<n;i++)
    {
        currentMessageLetter=message[i];
        cypherPosition=((int)toupper(currentMessageLetter))-65;

        if(isupper(currentMessageLetter))
        {
            cyphertext[i]+=toupper(cypher[cypherPosition]);
        }else
        {
            cyphertext[i]+=tolower(cypher[cypherPosition]);
        }
    }
    return cyphertext;
}
