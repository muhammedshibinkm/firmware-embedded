#include<stdio.h>

//time complexity is O(n2) in worst case
// O(n) in best case , when the array is almost sorted

void insertionSort(int *arr, int size)
{
    for(int i=0;i<size;i++) {
        int key = arr[i];//considering ith element is sorted
        int j = i-1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    } 


}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
