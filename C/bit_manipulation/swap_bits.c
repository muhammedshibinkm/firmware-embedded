#include<stdio.h>


void swap(int *num,, int bit1, int bit2)
{
  int b1 = (*num >> bit1) & 1;
  int b2 = (*num >> bit2) & 1;
  if( bi != b2)
  {
    *num = *num ^ ( (1<<bit1) | (1<<bit2));
  }
}
  

int main()
{
  int num = 10;
  int bit1 = 1;
  int bit2 = 3;
  swap(num, bit1, bit2);
}
