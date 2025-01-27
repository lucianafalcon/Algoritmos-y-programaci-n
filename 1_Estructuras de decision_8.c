/******************************************************************************
8) Dado un mes escribir la cantidad de días de dicho mes.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    int mes;
    int suma;
    
    while(continuar == 's'){
        printf("Ingresar numero del mes:  ");
        scanf("%d",&mes);
        
       switch(mes){
        case 1:
            printf("Enero tiene 31 dias");
            break;
        case 2:
            printf("Febrero tiene 28 dias");
            break;
        case 3:
            printf("Marzo tiene 31 dias");
            break;
        case 4:
            printf("Abril tiene 30 dias");
            break;
        case 5:
            printf("Mayo tiene 30 dias");
            break;
        case 6:
            printf("Junio tiene 30 dias");
            break;   
        case 7:
            printf("Julio tiene 31 dias");
            break; 
        case 8:
            printf("Agosto tiene 31 dias");
            break;  
        case 9:
            printf("Septiembre tiene 30 dias");
            break;  
        case 10:
            printf("Octubre tiene 31 dias");
        case 11:
            printf("Noviembre tiene 30 dias");
            break; 
        case 12:
            printf("Diciembre tiene 31 dias");
            break;  
        default:
            printf("El nro ingresado no corresponde a un mes");
       }
 
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    
    }

    return 0;
}
