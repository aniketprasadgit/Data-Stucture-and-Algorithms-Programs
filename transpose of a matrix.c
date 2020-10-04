#include<stdio.h>
int a[3][3],b[3][3];
int main()
{
    int i,j;
    
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       scanf("%d",&a[i][j]);
    

    int temp;
    printf("\nArray 1st\n");
    for(i=0;i<3;i++)
     { for(j=0;j<3;j++)
         if(i==j)
         continue;
        else{
        if(b[i][j]==1||b[j][i]==1)
        continue;
        else
        {
          temp=a[i][j];
          a[i][j]=a[j][i];
          a[j][i]=temp;
          
          b[i][j]=b[j][i]=1;
        
        }
        
       }
    }
    
    printf("\nTrnaspose\n");
    for(i=0;i<3;i++)
     { for(j=0;j<3;j++)
       {printf("%d\t",a[i][j]);}
      printf("\n");
     }
    
   /*  printf("\nSum is\n");
    for(i=0;i<3;i++)
      {for(j=0;j<3;j++)
        {
          c[i][j]=a[i][j]-b[i][j];
          printf("%d\t",c[i][j]);
        }
        printf("\n");
       }*/
    return 0;
}
