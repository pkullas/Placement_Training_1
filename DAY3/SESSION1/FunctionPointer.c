#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int main(){
    int (*ptr)(int,int)=add;
    printf("Addition is %d\n",ptr(10,20));
}