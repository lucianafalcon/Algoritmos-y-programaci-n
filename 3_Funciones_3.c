/******************************************************************************
3. Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n.
*******************************************************************************/

#include <stdio.h>

int suma(int valor){
    int suma = 0;
    int i;
    
    if(valor > 0){
        for(i=valor; i>=0; i--){
            suma = suma + i;
        }
    }else if(valor<0){
        for(i=valor; i<=0; i++){
        suma = suma  + i;  
        }
    }
    
    return suma; 
}

int main()
{
    int valor;
    int x = 0;
    
    printf("Valor:");
    scanf("%d",&valor);
  
    x = suma(valor);

        printf("La suma de los %d valores es: %d",valor,x);
        
    return 0;
}
