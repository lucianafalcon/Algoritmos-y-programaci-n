/*
10) Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse.*/

#include <stdio.h>
#include <stdbool.h>

#define MF 10
#define MC 10

typedef int Tvector[MF];
typedef Tvector Tmatriz[MC];

bool matriz(Tmatriz matriz1, Tmatriz matriz2, int dimf1, int dimc1, int dimf2, int dimc2){
    int i,j;
    bool se_puede = true;
    int suma = 0;
    Tvector matrizk;

    if(dimc1 == dimf2){
        for(i=0; i<dimf1; i++){
            for(j=0; j<dimc2; j++){

                matrizk[i][j] = matriz1[i][j] + matriz2[j][j]; 
            }    
        }
    }else{
        se_puede = false;
    }

    return se_puede;
} 

int main(){
    Tmatriz matriz1={{1,2,3},{4,5,6},{7,8,9},{6,6,6}};
    Tmatriz matriz2={{4,5,6},{4,5,6},{7,8,9}};
    int dimf1=4, dimc1=3; 
    int dimf2=3, dimc2=3;
    bool x;

    x = matriz(matriz1, matriz2, dimf1, dimc1, dimf2, dimc2);

    if(x){
        printf("se puede");
    }else{
        printf("no se pudo realizar el proceso.");
    }

    return 0;
}