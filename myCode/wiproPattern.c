#include<stdio.h>
int main()
{
	int i,j,k=0,n=9,l,m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		printf("  ");
		
		for(j=1;j<=n-i;j++)
		printf("%d*",++k);
		
		m=n*5-k+1;
		for(l=1;l<j;l++)
		{
			if(l==j-1)
			printf("%d",m);
			else printf("%d*",m++);
		}
		printf("\n");
	}
	
	return 0;
	
}
