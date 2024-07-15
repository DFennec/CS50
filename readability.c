#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double gradeText(string text);
int main(void)
{
    string text= get_string("Text: ");
    int grade=gradeText(text);
    if(grade>16.0){
        printf("Grade 16+\n");
    }else if(grade<1.0){
        printf("Before grade 1\n");
    }else{
        printf("Grade %i\n",grade);
    }
}

double countLetters(string text)/*Average number of letters per 100 words*/
{
    double letters=0.0;
    double totalLetters=0.0;
    double words=0.0;
    for (int i=0, n=strlen(text); i<n; i++)
    {
        if(((ispunct(text[i])!=0)||(isblank(text[i])!=0)||(isspace(text[i])!=0))&&letters!=0)
        {
            words++;
            totalLetters+=letters;
            letters=0;
        } else if(((ispunct(text[i])!=0)||(isblank(text[i])!=0)||(isspace(text[i])!=0))&&letters==0)
        {
            letters=0;
        }else{
            letters++;
        }
    }
    return (totalLetters/words)*100;
}

double countSentences(string text)/*Average sentences per 100 words*/
{
    double sentences=0.0;
    double words=0.0;
    char prevChar='a';
    char currChar='a';
    for (int i=0, n=strlen(text); i<n; i++)
    {
        currChar=text[i];
        if(((ispunct(text[i])!=0)||(isblank(text[i])!=0)||(isspace(text[i])!=0))&&(isalpha(prevChar)!=0))
        {
            words++;
        }
        if((ispunct(text[i])!=0)&&(currChar!=',')&&(currChar!='\''))
        {
            sentences++;
        }
        prevChar=text[i];
    }
    return (sentences/words)*100;
}

double gradeText(string text)
{
    double L=countLetters(text);
    double S=countSentences(text);
    double grade=0.0588 * L - 0.296 * S - 15.8;
    return round(grade);
}