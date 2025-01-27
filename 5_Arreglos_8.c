/*
7) Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.
EL VECTOR ESTA ORDENADO ASCENDENTE.*/

#include <stdio.h>
#include <stdbool.h>

#define MF 10

typedef int Tvector[MF];

int buscador(Tvector a, int ML, int p){
    int posicion;
    int i;
    bool finalizar = false;
    int inf, sup, mitad;
    

    // if (encontrado)   ==   if (encontrado == true)
    // if (!encontrado)  ==   if (encontrado == false)

    inf=0;
    sup=ML-1;
    while (!finalizar){                         // 2 , 5, 6, 8, 10, 15
            if(p < a[inf] || p> a[sup]){                
                finalizar = true;
                posicion = -1;
                }else{
                    mitad=(sup-inf)/2;                     
                    if(p == a[mitad]){              
                        finalizar = true;
                        posicion = mitad;
                    }else if(p < a[mitad]){          
                        sup = mitad -1;
                    }else{                           
                        inf = mitad +1;              
                    } 
                }
    }
    return posicion;
}  

int main(){
    Tvector a = {2 , 5, 6, 8, 10, 15};
    int ML = 6;
    int p = 6;
    int x;

    x = buscador(a, ML, p);

    if(x == -1){
        printf("El numero %d no se encuentra en el vector.", p);
    }else{
        printf("La posicion que ocupa %d es: %d", p ,x);
    }

    return 0;
}