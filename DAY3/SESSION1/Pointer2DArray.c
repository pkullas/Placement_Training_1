#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int (*ptr)[n]=arr;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(*(ptr+i)+j));
        }
        printf("\n");
    }
    return 0;
}