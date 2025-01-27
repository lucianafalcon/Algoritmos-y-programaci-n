/******************************************************************************
1. Escribir una función que reciba un mes y un año; y devuelva la cantidad de días
del mes, considerando los años bisiestos.
Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int diasdelmes(int mes, int año){
    int dias = 0;
    
    switch(mes){
        case 1:
            dias = 31;
            break;
        case 2:
            if (año %4 == 0 || (año %100==0 && año %400==0)){
                dias = 29;
            }else{ 
                dias = 28;
            }
            break;
        case 3:
            dias = 31;
            break;
        case 4:
            dias = 30;
            break;
        case 5:
            dias = 31;
            break;
        case 6:
            dias = 30;
            break;
        case 7:
            dias = 31;
            break;
        case 8:
            dias = 31;
            break;
        case 9:
            dias = 30;
            break;
        case 10:
            dias = 31;
            break;
        case 11:
            dias = 30;
            break;
        case 12:
            dias = 31;
            break;
        default:
            printf("Dato ingresado invalido");
            break;
    } 
    return dias; 

}


int main()
{
    int mes;
    int anio;
    int x = 0;
    
    printf("Mes:");
    scanf("%d",&mes);
    printf("Año");
    scanf("%d",&anio);
    
    x = diasdelmes(mes, anio);
    
    if (x!=0){
        printf("El mes %d de %d tiene %d dias",mes,anio,x);
    }
    return 0;
}
