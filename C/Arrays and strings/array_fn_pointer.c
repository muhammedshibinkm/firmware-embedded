#include<stdio.h>

//typedef int (*Operations[2])(int, int);

int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}

int print_data()
{
    printf("hi all\n");
    return 0;
}
void call_fn(int (*print)())
{
    print();

}

int main()
{
    int (*Operation[])(int,int) = {add, sub};
    printf("%d + %d = %d\n", 2, 3, Operation[0](2, 3));
    printf("%d - %d = %d\n", 2, 3, (Operation[1])(2, 3));
    call_fn(print_data);
    int (*optn)(int,int) = &add;
    printf("%d\n",optn(10,20));
    return 0;
}
    
