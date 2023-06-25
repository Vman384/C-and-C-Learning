#include <stdio.h>
int main() {
    int n;
    printf("how tall would you like the block to be: ");
    scanf("%d",&n);
    int x;
    x=n+1;
    do{
        int k;
        for(k=0;k<n;k++){
            int i;
            for (i=0;i<n-1;++i){
                printf(" ");
            }
            int j;
            int h;
            for(h=0;h<2;++h){
                for (j=0;j<x-n;++j){
                    printf("#");
                }
                printf("  ");
            }
            n=n-1;
            printf("\n");
        }
    }
    while (n > 0 and n<9);
    return 0;
}
