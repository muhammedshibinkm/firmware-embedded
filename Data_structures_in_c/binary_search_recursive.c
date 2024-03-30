#include<stdio.h>

int binary_search(int *arr, int low,int high, int key)
{
    if(low<=high)
    {
        int mid = low+ (high-low)/2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
           return binary_search(arr, low=mid+1, high, key);
        } else {
           return binary_search(arr, low, high = mid-1, key);
        }
    }
    return -1;//Element not found
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
   int val = 5;
   int size =sizeof(arr)/sizeof(arr[0]);
    int pos = binary_search(arr, 0, size-1, val);
    if(pos == -1) {
        printf("not present\n");
    } else {
        printf("%d present at the index %d\n",val,pos);
    }
    return 0;
}
