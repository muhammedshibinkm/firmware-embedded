#include<stdio.h>


void swap(int *el1, int *el2)
{
    *el1 = *el1 ^ *el2;
    *el2 = *el1 ^ *el2;
    *el1 =  *el1 ^ *el2;
}
/*This function takes the last element as pivot, places the pivot element at its correct position in sorted array, 
and places all smaller elements (smaller than pivot) to the left of the pivot and all greater elements to the right of the pivot.*/
int partition(int *arr, int low, int high)
{
    int pivot = high;
    int i = (low - 1);
    for(int j = low; j <= high; j++) {
        if(arr[j] < arr[pivot]) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[pivot]);
    return (i+1);

}


void quick_sort(int *arr, int low, int high)
{
    if(low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, pi+1, high);
        quick_sort(arr, low, pi-1 );
    }

}
int main()
{
    int arr[] = {10,30,2,14,54,4,70,12,43,60,100,16};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    for(int i = 0; i < size; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
