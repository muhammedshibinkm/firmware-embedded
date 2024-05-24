#include<stdio.h>


int binary_to_decimal(int num)
{
    int mpow=1;
    int ret = 0;
    while(num !=0)
    {
        ret =ret + (mpow*(num%10));
        mpow*=2;
        num = num/10;
    }
    return ret;
}

int main()
{
    int num = 10100;
    int result = binary_to_decimal(num);
    printf("%d\n",result);
}
