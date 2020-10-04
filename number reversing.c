#include<stdio.h>
 static int sum=0;
    int y;
int main()
{   int n,x=0;
    printf("Enter ur number\n");
    scanf("%d",&n);
    printf("Reverse of number %d is \n",n);
    number_reverse(n);
    
   // printf("Sum of digit of number %d is\n%d",n,x);
    return 0;
}

int number_reverse(int n)
{
   
    if(n==0)
      {
        return 0;
    }
    else
    {
        y=n%10;
        printf("%d",y);
        n=n/10;
        number_reverse(n);
    }
}
