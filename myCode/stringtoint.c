#include<stdio.h>
#include<stdlib.h>
int main()
{
	//from one to ninenty nine lakh nine hundred ninety nine
	int n;
	char *ones[]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	char *tens[]={"","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	scanf("%d",&n);
	if(n<0)
	{
		printf("Please enter positive value!");
	    exit(0);
	}
	else if(n<=20)
	printf("%s ",ones[n]);
	else if(n<100)
	printf("%s %s",tens[n/10-1],ones[n%10]);
	else if(n<1000)
	{
		printf("%s hundred ",ones[n/100]);
		if(n%100<=20)
		printf("%s",ones[n%100]);
		else printf("%s %s",tens[(n/10)%10-1],ones[n%10]);
	}
	else if(n<10000)
	{
	        printf("%s thousand ",ones[n/1000]);
		    if((n/100)%10!=0)
		    printf("%s hundred ",ones[(n/100)%10]);	
	        if(n%100<=20)
			printf("%s",ones[n%100]);
			else  printf("%s %s",tens[(n/10)%10-1],ones[n%10]);
	}
	else if(n<100000)
	{
			if(n/1000<=20)
			printf("%s thousand ",ones[n/1000]);
			else printf("%s %s thousand ",tens[n/10000-1],ones[(n/1000)%10]);
			if((n/100)%10!=0)
		    printf("%s hundred ",ones[(n/100)%10]);	
	        if(n%100<=20)
			printf("%s",ones[n%100]);
			else  printf("%s %s",tens[(n/10)%10-1],ones[n%10]);
	}
	else if(n<1000000)
	{
		    printf("%s lakh ",ones[n/100000]);
			if((n/1000)%100<=20&&(n/1000)%100!=0)
			printf("%s thousand ",ones[(n/1000)%100]);
			else if((n/1000)%100>20) printf("%s %s thousand ",tens[(n/10000)%10-1],ones[(n/1000)%10]);
			if((n/100)%10!=0)
		    printf("%s hundred ",ones[(n/100)%10]);	
	        if(n%100<=20)
			printf("%s",ones[n%100]);
			else  printf("%s %s",tens[(n/10)%10-1],ones[n%10]);
	}
	else if(n<10000000)
	{
			if(n/100000<=20)
			printf("%s lakh ",ones[n/100000]);
			else printf("%s %s lakh ",tens[n/1000000-1],ones[(n/100000)%10]);
			if((n/1000)%100<=20&&(n/1000)%100!=0)
			printf("%s thousand ",ones[(n/1000)%100]);
			else if((n/1000)%100>20) printf("%s %s thousand ",tens[(n/10000)%10-1],ones[(n/1000)%10]);
			if((n/100)%10!=0)
		    printf("%s hundred ",ones[(n/100)%10]);	
	        if(n%100<=20)
			printf("%s",ones[n%100]);
			else  printf("%s %s",tens[(n/10)%10-1],ones[n%10]);
	}
	
}
