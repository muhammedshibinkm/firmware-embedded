#include<stdio.h>

int binary_search(int *arr,int size, int key)
{
    /*Do not do sizeof() in here to get size of array arr, sizeof() is an compile time operator,it returns the pointer size*/
    int low = 0;
    int high = size-1;
    while(low<=high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return -1;
}



int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
   int val = 5;
   int size =sizeof(arr)/sizeof(arr[0]);
    int pos = binary_search(arr, size, val);
    if(pos == -1) {
        printf("not present\n");
    } else {
        printf("%d present at the index %d\n",val,pos);
    }
    return 0;
}
