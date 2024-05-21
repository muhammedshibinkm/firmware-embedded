#include<stdio.h>

void swap(int *el1, int *el2)
{
    int temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}

void selection_sort(int *arr, int n)
{
    int min_id;
    for(int i = 0; i< n - 1; i++) {
        min_id = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_id]) {
                min_id = j;
            }
        }
        if(i != min_id) {
            swap(&arr[min_id], &arr[i]);
        }
    }
}

int main()
{
    int arr[8] = {10,2,35,40,100,3,14,8};
    int size = 8;
    selection_sort(arr, size);
    for(int i = 0;i < size; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
