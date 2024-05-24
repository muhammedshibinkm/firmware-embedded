#include<stdio.h>
#include<string.h>



void reverse_array(char *arr)
{
 //   int size = strlen(arr);
      int size = 6;
    for(int i=0;i<size/2;i++)
    {
        char temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-i-1] = temp;
    }
    return ;
}

int main()
{
    char arr[] = {1,2,3,4,5,6};
    reverse_array(arr);
    for(int i=0;i<6;i++)
    {
        printf("reversed: %d\n",arr[i]);
    }
    return 0;
}
