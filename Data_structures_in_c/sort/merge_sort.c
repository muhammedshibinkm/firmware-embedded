#include<stdio.h>
#include<stdlib.h>

void print_array(int *arr, int size)
{
    for(int i=0;i < size; i++) {
        printf("%dth[%d]\n",i,arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int size, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;
    while( i < left_size && j < right_size) {
        if(left[i] < right [j]) {
            arr[k] = left[i];
            k++; i++;
        } else {
            arr[k] = right[j];
            k++;j++;

        }
        
    }
    while(i < left_size) {
        arr[k] = left[i];
        k++; i++;
    }
    while(j<right_size) {
        arr[k] = right[j];
        k++; j++;
    }
    free(left);
    free(right);

}



void merge_sort(int *arr, int size)
{
    if(size <= 1) {
        return;
    }
    int mid = size/2;
    int *left = malloc(sizeof(int) * mid);
    if(left == NULL) {
        perror("for left, malloc failed\n");
        exit(1);
    }
    int *right = malloc(sizeof(int) * (size - mid));
    if(right == NULL) {
        perror("for right, malloc failed\n");
        exit(1);
    }
    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for(int i = 0; i < (size-mid); i++) {
        right[i] = arr[mid+i];
    }
    merge_sort(left, mid);
    merge_sort(right, (size - mid));
    merge(arr,size,left,mid, right, size - mid);
}

int main()
{
    int arr[] =  {48, 54, 92, 36, 13, 8, 92, 91, 53, 100, 39, 64, 58, 5, 95, 70, 21, 64, 16, 60, 7, 97, 66, 91, 43, 62, 59, 59, 13, 60, 31, 69, 15, 41, 54, 57, 71, 63, 57, 55, 95, 59, 1, 16, 92, 33, 12, 33, 67, 3, 89, 91, 62, 43, 62, 66, 11, 46, 59, 82, 72, 90, 65, 24, 18, 78, 45, 77, 58, 96, 78, 51, 64, 28, 89, 23, 4, 18, 66, 32, 39, 9, 67, 54, 98, 42, 19, 43, 42, 87, 13, 12, 57, 82, 39, 30, 8, 21, 60, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\n, size = %d\n",size);
    merge_sort(arr, size);
    print_array(arr, size);
}
 
