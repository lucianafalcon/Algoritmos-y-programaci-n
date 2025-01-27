/******************************************************************************
5. Dados a y n enteros, informar la potencia enésima de a por productos
sucesivos.
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    char continuar = 's';
    int a;
    int n;
    int i;
    int producto;
    
    while(continuar == 's'){
        printf("Ingrese un nro entero: ");
        scanf("%d",&a);
        printf("Ingrese la potencia: ");
        scanf("%d",&n);
        
        producto = 1;
        
        if (n>0){
            for (i=0; i<n; i++){
                producto = producto*a;
            }
        printf("La potencia por producto sucesivo es: %d",producto);  
        }
        if (n<0){
            for (i=n; i<0; i++){
                producto = producto*a;
            }
            printf("El producto por sumas sucesivas es: %d",(1/producto));  
        }
        
        if(n==0){
            printf("La potencia es 1.");
        }
        
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);

    }

    return 0;
}
