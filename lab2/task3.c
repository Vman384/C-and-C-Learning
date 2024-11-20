#include <stdio.h>
#include <string.h>



typedef struct  
{
    char *FacID;
    int UnitID;
}UnitCode;

int main(void){
    char unitFIT[3] = "FIT";
    char unitENG[3] = "ENG";

    UnitCode eng = {unitENG,2100};
    UnitCode fit = {unitFIT,1047};


    if(strcmp(fit.FacID,eng.FacID) == 0 && fit.UnitID == eng.UnitID){
        printf("The units are the same\n");
    }else{
        printf("The units are different\n");
    }

    return 0;
};
