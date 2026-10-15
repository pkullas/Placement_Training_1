#include<stdio.h>

int main(){
    int arr[2][3]={{10,20,30},{40,50,60}};
    int (*ptr)[3]=arr;
    printf("%d",ptr[1][2]);
    printf("%d\n",*(*(arr)));
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",*(*(ptr+i)+j));
        }
        printf("\n");
    }

    return 0;
}