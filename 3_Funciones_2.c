/******************************************************************************
2. Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int factorial(int valor){
    int resultadofactorial = 1;
    int i;
    
    if(valor > 0){
        for(i=valor; i>=1; i--){
            resultadofactorial = resultadofactorial*i;
        }
    }else if(valor == 0){
            resultadofactorial = 1;
        }else{
            printf("El valor ingresado es invalido.");
            resultadofactorial=-1;
        }
    
    return resultadofactorial; 

}

int main()
{
    int valor;
    int x = 0;
    
    printf("Valor:");
    scanf("%d",&valor);
  
    x = factorial(valor);
    
    if (x > 0){
        printf("El factorial de %d es: %d",valor,x);
    }
    return 0;
}
