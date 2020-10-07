# https://www.facebook.com/Mritunjay70/posts/1445812775628125
# Subscribed by Mritunjay Kumar

#include<stdio.h>
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
    int lb,ub,a[8]={75,-56,-21,32,25,54,9,8};
    int n = 8,i;
    lb = 0;ub = 7 ;
    mergeSort(a,lb,ub);
    printf("\nSorted Array : ");
    for(i = 0;i<8;i++)
    printf("%d ",a[i]);
    return 0;
}

void mergeSort(int a[],int lb,int ub)
{
  if(lb < ub)
  {
      int mid = (lb + ub)/2;
      mergeSort(a,lb,mid);
      mergeSort(a,mid+1,ub);
      merge(a,lb,mid,ub);
  }

}s

void merge(int a[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k = lb;
    int b [ lb + ub + 1];
    while(i<=mid &&j<=ub)
    {
        if(a[i]<a[j])
        {
            b[k] = a[i];i++;k++;
        }
        else
        {  b[k] = a[j];j++;k++;
        }
    }

    if(i>mid)
    {

        while(j<=ub)
        {
            b[k] = a[j];
            j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];i++;k++;
        }

    }
for(k=lb;k<=ub;k++)
a[k]=b[k];
}


