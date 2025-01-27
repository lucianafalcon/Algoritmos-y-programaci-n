/******************************************************************************
6. Escribir una función que reciba dos valores enteros, y devuelva el máximo
común divisor entre ambos números.
Recordemos que se define el máximo común divisor (MCD) de dos o más
números enteros al mayor número entero que los divide sin dejar resto alguno.
Te sugerimos que antes de programar la solución te hagas preguntas del tipo a
las planteadas en en el ejercicio anterior
*******************************************************************************/
 
#include <stdio.h>
#include <stdbool.h>

int mcd(int x, int y){     // ej: 4 = 2.2   6 = 2.3 -> mcd: 2  
    int mcd;
    int i;
    int minimo = x;
    
    if (y<x){
        minimo = y;
    }
    
    for(i=1 ; i<=minimo ; i++){    
        if(x%i==0 && y%i==0){
           mcd=i; 
        }
    }    
    
    return mcd; 
}

int main()
{
    int x;
    int y;
    int z;
    
    printf("1er numero:");
    scanf("%d",&x);
    printf("2do numero:");
    scanf("%d",&y);
  
    z = mcd(x,y);

        printf("El MCD entre %d y %d es: %d",x,y,z);
    
    return 0;
}
