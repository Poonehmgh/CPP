
#include<stdio.h>

int *func()
{
    char local = 'W';
    int i= 1;
    return (&i);
}
int main()
{
    int *s = func();
    printf("hello %d", *s);
}