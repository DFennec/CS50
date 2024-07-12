#include <cs50.h>
#include <stdio.h>
#include <math.h>


string detectIssuer(long code);

int main(void)
{
    long number=get_long("Number: ");
    printf("\n%s",detectIssuer(number));
}

string detectIssuer(long code)
{
    int length=0;
    while((code%(long)(pow(10,length)))!=code){
        length++;
    }
    long start=((code%(long)(pow(10,length)))-(code%(long)(pow(10,length-2))))/(long)(pow(10,length-2));
    long startFirst=(start-(start%10))/10;

    if((length==15)&&(start==34||start==37))
    {
        return "AMEX\n";
    }else if((length==13||length==16)&&(startFirst==4)){
        return "VISA\n";
    }
    else if((length==16)&&(start==51||start==52||start==53||start==54||start==55)){
        return "MASTERCARD\n";
    }else{
        return "INVALID\n";
    }
}
