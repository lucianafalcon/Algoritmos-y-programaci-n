/*
2) Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada. Informar la
cantidad de números y el contenido del vector indicando la posición ocupada
por cada número a partir de la primera posición.*/

#include <stdio.h>
#define MAX 50

typedef int Tvector[MAX];

void vector(int numero){
    int i, j;
    int digito = numero%10;
    int contador = 0;
    Tvector vector;

    i=0;
    while( numero != 0){
        vector[i] = digito;
        numero = numero/10;
        digito = numero%10;
        contador++;
        i++;
    }

   

    printf("EL contenido del vector es: \n", numero);
    for(i=0; i<contador;i++){
        j=contador-i-1;
        printf("posicion: %d, numero: %d \n", i, vector[j]);
    }

}

int main(){
    int numero;

    printf("ingrese un numero: ");
    scanf("%d", &numero);

    vector(numero);

    return 0;
}