#include<stdio.h>

int removeDuplicates(int *arr,int size)
{
    int j=0;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i] != arr[i+1]){
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[size-1];
    return j;
}

int main()
{
    int arr[]= {1,2,3,4,5,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",size);
    size = removeDuplicates(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
