#include<stdio.h>

int main()
{ char c;
    printf("ENTER YOUR CHARACTER\N");
   scanf("%c",&c);
    
    if(c>=65&&c<=90)
     printf("Capital letters");
    if(c>=97&&c<=122)
     printf("small");
    if(c>=48&&c<=57)
    printf("digits");
    if(c>=0&&c<=47||c>=58&&c<=64||c>=91&&c<=96)
     printf("special symbol");
    
    return 0;
}
