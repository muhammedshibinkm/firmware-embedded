/*best performance where the array is almost sorted*/

#include<stdio.h>

int insertion_sort(int *arr, int size)
{
  for(int i=0;i<size;i++)
  {
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
  }
  return 0;
}
  
  
int main()
{
  int arr[] = {1,10,5,56,3,5,20,45};
  int size = sizeof(arr)/ sizeof(arr[0]);
  insertion_sort(arr, size);
  for(int i=0;i<size;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;


}
