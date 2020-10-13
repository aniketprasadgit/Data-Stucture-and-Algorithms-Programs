#include<stdio.h>
int main()
{
	int n=5,i,j,k,l,side_space,count=0;
	count=0;
	printf("Enter the odd value of n : ");
	scanf("%d",&n);
	system("cls");
	if(n%2!=0)
     {	side_space=n/2+1;
	for(i=1;i<=n;i++)
	{
		if(i==n)
		{
			printf("*");
			for(j=1;j<=side_space-1;j++)
			printf(" ");
			for(j=1;j<=n;j++)
			printf("@");
			for(j=1;j<=n;j++)
			printf("*");
			for(j=1;j<=n;j++)
			printf("@");
			for(j=1;j<=side_space-1;j++)
			printf(" ");
			printf("*");
		}
		else{
			
		for(j=1;j<=n*2+side_space;j++)
		    printf(" ");
	    for(j=1;j<=n;j++)
	        printf("@");
	    if(i<=side_space)
		{
			for(j=i;j<side_space;j++)
		    printf(" ");    
			for(j=1;j<=i;j++)
			printf("*");
	    }
	   if(i>side_space)
	   {
		   	for(j=1;j<=i-side_space;j++)
		   	printf(" ");	   	
		   	for(j=1;j<=n-i+1;j++)
		   	printf("*");
	   }
   }
	   printf("\n");
	}
for(i=1;i<n;i++)
{
	if(i<side_space)
	{
		for(j=1;j<=i+1;j++)
		printf("*");
		for(j=i+1;j<side_space;j++)
		printf(" ");	
	}
	if(i>=side_space)
	{
		for(j=1;j<=n-i;j++)
		printf("*");
		for(j=1;j<=i-side_space+1;j++)
        printf(" ");
	}
	for(j=1;j<=n;j++)
	printf("@");
	for(j=1;j<=n+i-1;j++)
	printf(" ");
	if(i<=side_space)
	{	
		for(j=1;j<=n-count;j++)
		printf("*");
	    count+=2;
	}
	printf("\n");
}
count=0;
for(i=1;i<=side_space;i++)
{
	for(j=1;j<side_space+i;j++)
	printf(" ");
	for(j=1;j<=n-count;j++)
		printf("*");
        count+=2;
   printf("\n");
}}
else printf("Please Enter odd no !!!");
}
