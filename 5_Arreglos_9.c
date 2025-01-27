/*
9) Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado.*/

#include <stdio.h>
#include <stdbool.h>
#define MF 10

typedef int Tvector[MF];

bool agregar_num(Tvector vector, int *ML, int numero){
    bool se_puede = true;
    bool insertado = false;
    int aux, i;  

    if(*ML == MF){
        se_puede = false;
        }else{
            (*ML)++;
        }

    i=*ML-2;
    while(!insertado && i>=0){
        if(numero < vector[i]){              // 1 2 3 5 6 7 8 ->  
            aux = vector[i];
            vector[i+1]= vector[i];
            vector[i]= aux;
            i--;
        }else{
                vector[i+1]=numero;
                insertado = true;
            }
        }
    if(!insertado){
        vector[0]=numero;
    }

    return se_puede;
} 


int main(){
    Tvector vector={1,2,3,5,6,7,8,9,10}; 
    int ML=9, p=-7, i;
    bool x;

    x = agregar_num(vector, &ML, p); 

    if(x){
        printf("el vector es: ");
        for(i=0; i<ML; i++){
        printf("%d ", vector[i]);
        }
    }else{
        printf("No se pudo insertar.");
    }

    return 0;
}