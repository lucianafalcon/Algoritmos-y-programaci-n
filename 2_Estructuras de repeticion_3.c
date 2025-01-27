/******************************************************************************
3. Dado un número n, informar los n primeros términos de la sucesión
geométrica de razón 3 (1, 3, 9, 27, etc.).
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    char continuar = 's';
    int n;
    int i;
    int suma = 0;
    
    while(continuar == 's'){
        printf("Ingrese un nro: ");
        scanf("%d",&n);
        
        if (n > 0){
            for (i=0; i<=n-1; i++){
                suma = pow(3,i);
            printf("%d ",suma);
            }
        }else{
            printf("El nro ingresado no es valido");
        }
     
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    }

    return 0;
}
