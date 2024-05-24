#include<stdio.h>


void sort_array(int row, int col, int (*arr)[col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            for(int k=0;k<col-j-1;k++)
            {
                if(arr[i][k] > arr[i][k+1]) {
                    arr[i][k] = arr[i][k] ^arr[i][k+1];
                    arr[i][k+1] = arr[i][k] ^arr[i][k+1];
                    arr[i][k] = arr[i][k] ^arr[i][k+1];
                }
        
            }
        }
    }

}

int main()
{
    int arr[2][3] = {
        {10,5,7},{7,6,20}
    };
    sort_array(2,3, arr);

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

}
