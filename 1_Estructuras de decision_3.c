/******************************************************************************
3) Calcular el sueldo de un operario ingresando por teclado la cantidad de
horas que trabajó en el mes y el valor de la hora.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    float horas;
    float valor;
    
    while(continuar == 's'){
        printf("Ingresar cantidad de horas: ");
        scanf("%f",&horas);
        printf("Ingresar el valor de la hora: ");
        scanf("%f",&valor);
    printf("El sueldo del operario es =  %f\n", horas*valor);
       
    printf("desdea continuar? s/n: \n");
    scanf("%c",&continuar);
    scanf("%c",&continuar);    
    }

    return 0;
}
