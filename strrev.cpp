#include<stdio.h>
char * strrev(char* str)
{
     int length=0;
     char* str1=str;

     while(*str++)
        ++length;

     str=str1;
     char  temp;

     for ( int i=0; i< length/2; ++i)
     {
           temp= *(str +i);
           *(str +i) = *(str+length -1-i);
           *(str+length -1-i)= temp;
     }

     return str1;
}
int main()
{
    char str[]="Hello World!";
    strrev(str);
    printf("Reversed str:%s", str);

    return 0;

}
