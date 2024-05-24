#include<stdio.h>

void max_min(int arr[],int n, int *min, int *max){
    *min =arr[0];
    *max = arr[0];
    int j=0;
    for(int i=0;i<n;i++){
        if(*max <arr[i])
        {
          *max = arr[i];
        }
        else if(*min >arr[i] )
        {
            *min = arr[i];
        }
    }
    return;

}

int main()
{
    int arr[] = {10,5,23,4,45,3,44,54,66,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int min = 0;
    int max = 0;
    max_min(arr,n,  &min, &max);
    printf("min:%d, max:%d\n",min,max);
}
