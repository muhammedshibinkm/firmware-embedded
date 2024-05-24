#include<stdio.h>
#include<stdlib.h>


void print_2d_fdss(int row,int column, int (*arr)[column])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int m = 5;
    int n = 4;
    int count =0;
    int (*arr)[n] = malloc(m*sizeof(int[n]));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            count++;
            arr[i][j] = count;
        }
    }

    print_2d_fdss(m,n, arr);
        free(arr);
        return 0;
    
}
