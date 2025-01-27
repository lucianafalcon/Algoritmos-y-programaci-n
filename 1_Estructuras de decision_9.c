/******************************************************************************
9) Dada una fecha año, mes y día, informar si es correcta o no.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    int año;
    int mes;
    int dia;
    int fechavalida = 1;
    
    while(continuar == 's'){
        printf("Ingresar año: ");
        scanf("%d",&año);
        printf("Ingresar mes: ");
        scanf("%d",&mes);
        printf("Ingresar dia:");
        scanf("%d",&dia);
        
        if ((mes==4 || mes==6|| mes==9 || mes==11) && (dia ==31)){
           fechavalida = 0;
        }  
        if (mes > 12 || mes<1){
            fechavalida = 0;
            } 
        if (año<0000 || año>9999){
            fechavalida = 0;
            }
        if (dia>31 || dia<1){
            fechavalida = 0;
            }
        if ((mes==2) && (dia>28)){
            fechavalida = 0;
        }
        if (fechavalida == 1){
            printf("La fecha ingresada es correcta.");
        }else{
            printf("La fecha ingresada es invalida.");
        }
     
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    }

    return 0;
}
