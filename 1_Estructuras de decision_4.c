/******************************************************************************
4) Ingresar tres números y hallar el mayor.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    float nro1;
    float nro2;
    float nro3;
    float mayor = nro1;
    
    while(continuar == 's'){
        printf("Ingresar 1er nro: ");
        scanf("%f",&nro1);
        printf("Ingresar 2do nro: ");
        scanf("%f",&nro2);
        printf("Ingresar 3er nro: ");
        scanf("%f",&nro3);
        
        mayor = nro1;
        if (nro2 > nro1){
            mayor = nro2;
        }if (nro3 > nro1){
            mayor = nro3;
        }
        printf("El mayor de los nros ingresados es =  %f\n", mayor);
        
    printf("desdea continuar? s/n: \n");
  
    scanf("%c",&continuar);
    scanf("%c",&continuar);    
    }

    return 0;
}
