#include<stdio.h>
int main(){
    int arr[3][3];
    int (*ptr)[3]=arr;

    printf("Enter 9 values for the 3x3 matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nOriginal matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",*(*(ptr+i)+j));
        }
        printf("\n");
    }
    printf("\nRotated matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",*(*(ptr+2-j)+i));
        }
        printf("\n");
    }
    return 0;
}