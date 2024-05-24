#include<stdio.h>
#include<stdbool.h>

bool is_bits_alternate(unsigned int num)
{
  //  unsigned int n = num^(num>>1);
  //  if(((n+1) & n)==0)
    if(!(num&(num>>1)))
    {
     return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    unsigned int num = 682;
    bool ret = is_bits_alternate(num);
    if(ret){
        printf("it's alternative\n");
    }
    else {
        printf("not alternative\n");
    }
    return 0;
}
