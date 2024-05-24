#include<stdio.h>
#include<stdlib.h>



void print_2d_fdsd(int row,int column, int **arr)
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
    int count = 0;
    int *arr[m];
    for(int i = 0; i<m;i++) {
        arr[i] = (int *)malloc(n*sizeof(int));
    } 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            count++;
            arr[i][j] = count;
        }
    }

    print_2d_fdsd(m,n, arr);

    for(int i=0;i<n;i++)
    {
        free(arr[i]);
    }
    

    return 0;
}
