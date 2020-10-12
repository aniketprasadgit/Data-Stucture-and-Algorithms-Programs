#include <bits/stdc++.h>

using namespace std;
int row,col,**matrix;
int countChells(int i,int j)
{
    if(i<0||j<0||i>=row||j>=col||matrix[i][j]==0)
    return 0;
    int count=matrix[i][j]--;
    count+=countChells(i,j-1);
    count+=countChells(i-1,j);
    count+=countChells(i,j+1);
    count+=countChells(i-1,j);
    count+=countChells(i+1,j);
    count+=countChells(i,j+1);
    count+=countChells(i+1,j+1);
    count+=countChells(i-1,j-1);
    return count;
}
int maxGrid()
{
    int max=-1,q;
    cout<<"in max grid\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==1)
            {
             cout<<"countShells\n";	
             q=countChells(i,j);	
			}
            if(q>max)
            max=q;
        }
    }
    return max;
}

int main()
{
    cin>>row>>col;
    matrix = new int*[row];
    for(int i=0;i<row;i++)
    matrix[i]=new int[col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        cin>>matrix[i][j];
    }
    cout<<maxGrid();
}

