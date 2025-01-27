/*
7) Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.*/

#include <stdio.h>
#include <stdbool.h>

#define MF 10

typedef int Tvector[MF];

int buscador(Tvector a, int lon, int p){
    int x=-1;
    int i;
    bool encontrado = false;

    i=0;
    while(i<lon && !encontrado){
        if( p == a[i]){
            x = i;
            encontrado = true;
        }
        i++;
    }

    return x;
}  

int main(){
    Tvector a = {2 , 5, 4, 8, 6, 0};
    int lon = 6;
    int p = 6;
    int x;

    x = buscador(a, lon, p);

    if(x == -1){
        printf("El numero %d no se encuentra en el vector.", p);
    }else{
        printf("La posicion que ocupa %d es: %d", p ,x);
    }

    return 0;
}