/******************************************************************************
7) Ingresar un número que representa un mes, escribir el nombre del mes
correspondiente. Puede haber error en el número dado.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    int mes;
    int suma;
    
    while(continuar == 's'){
        printf("Ingresar numero del mes: ");
        scanf("%d",&mes);
        
       switch(mes){
        case 1:
            printf("enero");
            break;
        case 2:
            printf("febrero");
            break;
        case 3:
            printf("marzo");
            break;
        case 4:
            printf("abril");
            break;
        case 5:
            printf("mayo");
            break;
        case 6:
            printf("junio");
            break;
        case 7:
            printf("julio");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("septiembre");
            break;
        case 10:
            printf("octubre");
            break;
        case 11:
            printf("noviembre");
            break;
        case 12:
            printf("diciembre");
            break;
        default:
            printf("El nro ingresaso no corresponde a un mes");
       }
 
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    
    }

    return 0;
}
