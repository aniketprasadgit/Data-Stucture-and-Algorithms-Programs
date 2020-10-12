#include<stdio.h>
#include<stdlib.h>
int heap_size;
void heap_sort(int *arr);
void max_heapify(int *arr,int i);
void build_max_heap(int *arr);
int main()
{
	int n,*arr,i;
	printf("Enter the size of an array : ");
	scanf("%d",&n);
	arr=(int*)calloc(n,sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
    scanf("%d",(arr+i));
    heap_size=n-1;
    heap_sort(arr);
    printf("Array elements are : ");
    for(i=0;i<n;i++)
    printf("%d  ",*(arr+i));
}
void build_max_heap(int *arr)
{
	int i;
	for(i=(heap_size)/2;i>=0;i--)
	max_heapify(arr,i);
}
void max_heapify(int *arr,int i)
{
	int l=2*i+1,r=2*i+2,largest,temp;
	if(l<=heap_size&&arr[l]>arr[i])
	largest=l;
	else largest=i;
	if(r<=heap_size&&arr[r]>arr[largest])
	largest=r;
	if(largest!=i)
	{
	   temp=arr[largest];
	   arr[largest]=arr[i];
	   arr[i]=temp;
	   max_heapify(arr,largest);
	}
}
void heap_sort(int *arr)
{
	int temp,i,n;
	n=heap_size;
	build_max_heap(arr);
	for(i=n;i>=1;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heap_size--;
		max_heapify(arr,0);
	}
}
