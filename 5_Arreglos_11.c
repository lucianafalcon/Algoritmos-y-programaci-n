/*
11) Escribir un subprograma que dada una matriz de números reales, de n x m,
devuelva un vector que en cada posición i almacene el elemento mínimo de
cada fila i de la matriz.*/

#include <stdio.h>
#define MLF 20
#define MLC 20

typedef int Tvector[MLF];
typedef Tvector Tmatriz[MLC];

void vector_(Tmatriz matriz, int n, int m, Tvector vector){
    int i,j=0;
    int minimo;

    for(i=0; i<n; i++){
        minimo = matriz[i][j];
        for(j=0; j<m; j++){
            if(matriz[i][j] < minimo){
                minimo = matriz[i][j];
            }    
        }
        vector[i] = minimo;
        j=0;
    }
}


int main(){
    Tmatriz matriz1={{1,2,3},{4,5,6},{7,8,9},{6,6,2}};
    int n=4, m=3, i;
    Tvector vector;

    vector_(matriz1, n, m, vector);

    printf("EL vector de los minimos de cada fila es: ");
    for(i=0; i<n; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}