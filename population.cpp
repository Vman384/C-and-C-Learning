#include <stdio.h>
#include <math.h>
int main() {
    int start;
    int end;
    do{
    printf("what is the start population ");
    scanf("%d",&start);
    }
    while(start<9);
    do{
    printf("what is the end population ");
    scanf("%d",&end);
    }
    while(end>start);
    int current;
    current=start;
    float gain;
    float loss;
    int years;
    years=0;
    while(current<=end){
        gain = current/3;
        printf("%d",gain);
        gain=floor(gain);
        loss = current/4;
        loss=floor(loss);
        current=current+gain-loss;
        ++years;
    }    
    printf("%d\n", years);
    
    return 0;
}