#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string decideWinner(string word1, string word2);
int main(void)
{
    string p1word=get_string("Write your word, player 1: ");
    string p2word=get_string("Write your word, player 2: ");
    printf("%s", decideWinner(p1word,p2word));
}

string decideWinner(string word1, string word2){
int points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int p1score=0;
int p2score=0;
int letter=0;

for(int i=0, n=strlen(word1);i<n;i++){
    letter=((int)toupper(word1[i]))-65;
    p1score+=points[letter];
}

for(int i=0, n=strlen(word2);i<n;i++){
    letter=((int)toupper(word2[i]))-65;
    p2score+=points[letter];
}
if(p1score>p2score)
{
return "Player 1 wins!\n";
}else if(p1score<p2score){
return "Player 2 wins!\n";
}else{
return "Tie!\n";
}

}
