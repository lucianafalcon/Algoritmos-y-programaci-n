/*
3) Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y x un real, almacenar x en la posición i de un vector. El listado no se ingresa
ordenado por posición. Informar la cantidad de números y el contenido del
vector indicando la posición ocupada por cada número a partir de la primera
posición.*/

#include <stdio.h>
#include <stdbool.h>
#define MF 100

typedef int Tvector[MF];

void ejercicio(Tvector v1, Tvector v2, int ML){
    int i, aux,aux2;
    bool intercambio = true;
    int j=0;

    while(intercambio && j<ML){
        intercambio = false;
        for(i=0; i<ML-1; i++){
            if(v1[i] > v1[i+1]){
                aux=v1[i+1];
                aux2=v2[i+1];
                v1[i+1]=v1[i];
                v2[i+1]=v1[i];
                v1[i]=aux;
                v2[i]=aux2;
                intercambio =true;
            }
        }
        j++;
    }

/*for(i=0;i<ML;i++){
    printf("vector-- %d\n", v1[i]);
    }

*/
    printf("La cantidad de nros es: %d\n", ML);
    printf("El vector es: \n");
    for(i=0; i<ML; i++){
        printf("Posicion: %d, numero: %d \n", v1[i], v2[i]);
    }

}

int main(){
    int ML=0, i=0;
    bool validar = true;
    Tvector v1, v2;
    int valor;
    while(validar){
        printf("Ingrese listado (termina con 0): ");
        //scanf("%d", v1[i]);
        scanf("%d",&valor);
            v1[i] = valor;
        if(v1[i] >0){
            printf("Ingrese valor: ");
            //scanf("%d", v2[i]);
            scanf("%d",&valor);
            v2[i]=valor;
            ML +=1;
            i++;
        }else{
            (validar = false);
        }
    }
    
    ejercicio(v1, v2, ML);
    return 0;

}









