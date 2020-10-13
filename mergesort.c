#include<stdio.h>
#include<stdlib.h>
void merge_sort(int *arr,int p,int r);
void merger(int *arr,int p,int q,int r);
int main()
{
	int *arr,n,i;
	printf("Enter the array size : ");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
	scanf("%d",arr+i);
		for(i=0;i<n;i++)
	printf("%d ",*(arr+i));

	merge_sort(arr,0,n-1);
	printf("array elements after sort : \n");
	for(i=0;i<n;i++)
	printf("%d ",*(arr+i));
}

void merge_sort(int *arr,int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
   // Divide and Conquer
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
   // Combine
    merger(arr,low,mid,high);
  }
  
  return;
}/*
void merge_sort(int *arr,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+q)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merger(arr,p,q,r);
	}
	return;
}

*/
void merger(int *arr,int p,int q,int r)
{
	int n1=q-p+1,n2=r-q,i,j,k;
	int a1[n1+1],a2[n2+1];
	a1[n1]=9999,a2[n2]=9999;
	for(i=0;i<n1;i++)
	a1[i]=arr[p+i];
	for(i=0;i<n2;i++)
	a2[i]=arr[q+i+1];
/*	while(i+j<n1+n2)
	{
		if(a1[i]<a2[j])
		{
			arr[k]=a1[i];
			i++;
			k++;
		}
		if(a1[i]>a2[j])
		{
			arr[k]=a2[j];
			j++;
			k++;
		}
		if(a1[i]==a2[j])
		{
			arr[k]=a1[i];
			k++;
			arr[k]=a2[j];
			i++;
			j++;
		}
	}*/
	k=0;
	j=0;
	for(i=p;i<=r;i++)
	{
		if(a1[k]<=a2[j])
		{
		   arr[i]=a1[k];
		   k++;
	    }
	    else {
	    	arr[i]=a2[j];
	    	j++;
		}
	}
}
/*
void merger(int *arr,int l,int m,int h)
{
  int arr1[10],arr2[10];  // Two temporary arrays to
                             //hold the two arrays to be merged
  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=9999;  // To mark the end of each temporary array
  arr2[j]=9999;

  i=0;j=0;
  for(k=l;k<=h;k++)  //process of combining two sorted arrays
  {
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }
  
  //return;
}*/
