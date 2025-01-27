/*
4) Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa.*/

#include <stdio.h>
#include <stdbool.h>
#define MF 100

typedef float Tvector[MF];
typedef int Tvector_pos[MF];

void valor_maximo(Tvector v, int ML){
    int i;
    int j = 0; 
    int contador = 1;
    float maximo= v[0];
    Tvector_pos v_posiciones;

    for(j=0;j<ML;j++){
        v_posiciones[j] = 0;
    }

    for(i=1; i<ML; i++){
        if(v[i] > maximo){
            contador = 1;
            maximo = v[i];
            for(j=0;j<ML;j++){
                 v_posiciones[j] = 0;
            }
            j=0;
            v_posiciones[j] = i;
        }else if(v[i] == maximo){
            contador++;
            j++;
            v_posiciones[j]=i;
        }
    }

    printf("El maximo valor es: %f y se se encuentra: %d veces\n", maximo, contador);
    printf("Las posiciones son: ");
    for(j=0; j<contador; j++){
        printf("%d ", v_posiciones[j]);
    }
}

int main(){
    Tvector v = {0,3,8,8,4,8,90,2,9,5};
    int ML;
    float numero;
    char rta = 's';
    /*
    ML=0;    
    while(ML<=100 && rta == 's'){
        printf("Ingrese numero real: ");
        scanf("%f", &numero);
        fflush(stdin);
        v[ML]=numero;
        ML++;
        printf("Desea ingresar otro numero? s/n: ");
        scanf("%c", &rta);
        fflush(stdin);
    }
    */

    ML = 10;
   valor_maximo(v, ML);

    return 0;
}