#include<stdio.h>
int main(){
    char text[]="REVA";
    char *ptr=text;
    printf("Text is %s\n",text);
    while(*ptr!='\0'){
        printf("%c\n",*ptr);
        ptr++;
    }
}