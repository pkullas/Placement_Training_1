#include<stdio.h>
int main(){
    int n=10;
    int *ptr=&n;
    printf("Value of n: %d\n",n);
    printf("Address of n: %p\n",&n);
    printf("%p\n",(void*)&n);
}