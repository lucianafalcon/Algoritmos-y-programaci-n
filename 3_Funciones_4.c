/******************************************************************************
4. Escribir una función que reciba un número y devuelva un valor booleano
indicando si el número recibido es ó no primo. Si desconoce como devolver un
valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool primo(int numero){    //(numero-1)! +1 = rta; rta % numero = 0 ->es primo 
    bool esprimo=false;
    int x;
    int z;
    int division;
    int factorial =1;
    int i;

    x = numero-1;
    for(i=x; i>=1; i--){
        factorial = factorial*i;
    }

    z = factorial + 1;
    division = z % numero;

    if(division == 0){
        esprimo=true;
    }
    
    return esprimo; 
}

int main()
{
    int numero;
    bool x;
    
    printf("Numero:");
    scanf("%d",&numero);
  
    x = primo(numero);

    if (x){
        printf("En numero %d: es primo",numero);
    }else{
        printf("El numero %d no es primo", numero);
    }
    
    return 0;
}
