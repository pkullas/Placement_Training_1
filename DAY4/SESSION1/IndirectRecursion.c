#include<stdio.h>
void funB(int n);
void funA(int n){
    if(n>10){
        return ;
    }
    printf("%d",n);
    funB(n+1);
}
void funB(int n){
    if(n>10){
        return ;
    }
    printf("%d",n);
    funA(n+1);
}
int main(){
    funB(0);

}