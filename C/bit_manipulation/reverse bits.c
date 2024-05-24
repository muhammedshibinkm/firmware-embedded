#include<stdio.h>

int reverse_bits(int num)
{
    int reverse = 0;
    int number_ofBits = sizeof(int) *8;
    int bit = 0;
    for(int i = 0;i<number_ofBits;i++)
    {
        if((num >> i) & 1)
            reverse = reverse | (1 << (number_ofBits - i - 1));
    } 
    return reverse;
}

int reverse_bits_logic_2(int num)
{
    int i=0;
    int rev = 0;
    while(num>>=i)
    {
       if(num&1)
         rev|= 1<<31-i;
        i++;
    }
    return rev;
}

int main()
{
    int num = 40;
    for(int i =31;i>=0;i--)
    {
        if((num>>i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    
    int reverse = reverse_bits(num);
    for(int i =31;i>=0;i--)
    {
        if((reverse>>i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    int rev = reverse_bits_logic_2(num);
     for(int i =31;i>=0;i--)
    {
        if((reverse>>i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}
