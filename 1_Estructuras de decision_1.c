/******************************************************************************
1) Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero.
*******************************************************************************/

#include <stdio.h>

int main()
{
    int x;
    char continuar = 's';
    
    while(continuar == 's'){
        printf("Ingrese un número, finaliza con salir: ");
        scanf("%d",&x);
        if (x>0){
           printf("El nro ingresado es mayor a cero \n");
        }else if (x<0){
            printf("el nro ingresado es menor a cero \n");
        }else{
        printf("El nro ingresado es igual a cero \n");
        }
    printf("desdea continuar? s/n: \n");
    scanf("%c",&continuar);
    scanf("%c",&continuar);    
    }

    return 0;
}
