#include<stdio.h>
#include<string.h>

void reverse_word(char *start, char *end)
{
    int i=0;
    while(start<end)
    {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
        i++;
      
    }

}



void reverse_string(char *arr)
{
    char *startPoint = arr;
    char *endPoint = arr;
    while(*endPoint !='\0')
    {
        if( *endPoint == ' ')
        {
            reverse_word(startPoint,(endPoint-1) );
            startPoint = endPoint+1;
        }
        endPoint++;
    }
    reverse_word(startPoint, (endPoint-1));

    reverse_word(arr,endPoint-1);
}




int main()
{
    char arr[] = "Hello world";
    printf("String: %s\n",arr);
    reverse_string(arr);
    printf("reversed_string: %s\n",arr);
}
