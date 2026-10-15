#include<stdio.h>
#include<stdlib.h>
int main(){
    int nums=1202105;
    int *freq=(int*)malloc(10*sizeof(int));
    while(nums>0){
        int digit=nums%10;
        freq[digit]++;
        nums/=10;
    }
    printf("Frequency of each digit:\n");
    for(int i=0;i<10;i++){
        printf("Digit %d: %d\n", i, freq[i]);
    }
    free(freq);
    return 0;
}
