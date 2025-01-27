/******************************************************************************
(6. Escribir una función que reciba dos valores enteros, y devuelva el máximo
común divisor entre ambos números.
Recordemos que se define el máximo común divisor (MCD) de dos o más
números enteros al mayor número entero que los divide sin dejar resto alguno.
Te sugerimos que antes de programar la solución te hagas preguntas del tipo a
las planteadas en en el ejercicio anterior)
7. Ahora toma el ejercicio anterior, pero intenta resolverlo aplicando el método de
Euclides.
*******************************************************************************/
 
#include <stdio.h>
#include <stdbool.h>

int mcdeuclides(int x, int y){     // ej: 4 = 2.2   6 = 2.3 -> mcd: 2  
    int mcd;
    int i;
    int menor = x;
    int mayor = y;
    bool residuoaux =false;   
    int residuo;
    int residuo2;
    
    if (y<x){
        menor = y;
        mayor = x;
    }
    
    residuo = (mayor%menor);
    if(residuo == 0){
        mcd = menor;
        residuoaux = true;
    }else{                               // ej: 45 y 25 => 45%25=20 25%20=5 20%5=0 ->mcd=5 
        while(residuoaux==false){
            residuo2 = menor%residuo;
            printf("res2%d", residuo2);
            if(residuo2 == 0){
                mcd = residuo;
                residuoaux = true;
            }else{
                menor = residuo;
                residuo = residuo2;
            }
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
  
    z = mcdeuclides(x,y);

        printf("El MCD EUCLIDES entre %d y %d es: %d",x,y,z);
    
    return 0;
}
