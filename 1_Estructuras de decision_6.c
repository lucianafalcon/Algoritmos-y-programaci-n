/******************************************************************************
6) Calcular la suma de los n primeros números naturales.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    int nro;
    int suma;
    
    while(continuar == 's'){
        printf("Ingresar numero: ");
        scanf("%d",&nro);
        
        while(nro != 0){
            suma = suma + nro;
            nro--;            
        }
        
        printf("la suma de los primeros naturales es = %d\n", suma);
        suma = 0;
        printf("desea continuar? s/n: \n");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    
    }

    return 0;
}
