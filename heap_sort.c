/* https://www.facebook.com/permalink.php?story_fbid=151732496593519&id=100052703091127
  Subscribed by joy roy */

#include<stdio.h>

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void max_heapfy ( int a[], int n, int i) {
    int max = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    if ( left<n && a[left]>a[max] ) {
        max = left;
    }
    if ( right<n && a[right]>a[max] ) {
        max = right;
    }
    if ( max!=i ) {
        swap ( &a[i], &a[max]);
        max_heapfy ( a, n, max);
    }
}

void heap_sort ( int a[], int n) {
    for ( int i=(n/2)-1;i>=0;i-- ) {
        max_heapfy( a, n, i);
    }
    for ( int j=n-1;j>=0;j-- ) {
        swap ( &a[0], &a[j]);
        max_heapfy( a, j, 0);
    }
}

int main() {
    int n;
    //printf("Entre size of array : ");
    scanf("%d",&n);
    if ( n<=0 ) {
        printf("Size of array must be within [1,10000]");
        exit (0);
    }
    int arr[n];
    //printf("Enter Array Elements :\n");
    for ( int i=0;i<n;i++ ) {
        scanf("%d",&arr[i]);
        if ( arr[i]<=0 ) {
            printf("Number must be within [1,1000000]");
            exit (0);
        }
    }
    heap_sort ( arr, n);
    for ( int i=0;i<n;i++ )
        printf("%d ",arr[i]);
}
