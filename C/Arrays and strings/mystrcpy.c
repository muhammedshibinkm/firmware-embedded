#include<stdio.h>

void myStrcoy(char *dest, const char *src)
{
    char *temp = dest;
    while(src != '\0')
    {
        *dest++ = *src++;
    }
    return temp;
}

int main()
{
    char *src = "Test: copy";
    char dest[20];
    myStrcpy(dest, src);
}
