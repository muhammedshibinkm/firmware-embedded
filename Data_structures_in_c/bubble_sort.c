/*
Bubble Sort repeatedly steps through the list, compares adjacent elements, 
and swaps them if they are in the wrong order. The process is repeated until the array is sorted.
advantages:
 =>easy to implement.
 =>Space requirement is minimum
Disadvantages:
 =>Requires n-squired  processing steps for every n number of elements to be sorted
Average and worst case complexity O(n^2)
*/

#include<stdio.h>
#include<stdbool.h>
void bubble_sort(int *arr, int size)
{
    bool swapped = false;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) {
        break;//// If no two elements were swapped in the inner loop, array is already sorted
        }
    }
}


int main()
{
    int arr[] = {10, 95, 34, 100, 67, 1, 39, 80};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("array before sorting\n");
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    bubble_sort(arr, size);
    printf("array after sorting\n");
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
