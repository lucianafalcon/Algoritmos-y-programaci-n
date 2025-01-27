/******************************************************************************
4. Dados a y b enteros, informar el producto de ambos por sumas
sucesivas.
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    char continuar = 's';
    int a;
    int b;
    int i;
    int suma;
    
    while(continuar == 's'){
        printf("Ingrese un nro entero: ");
        scanf("%d",&a);
        printf("Ingrese un nro entero: ");
        scanf("%d",&b);
        
        suma = 0;
        
        if ((a>0 && b>0) || (a<0 && b>0)){
            for (i=0; i<b; i++){
                suma = suma +a;
            }
        printf("El producto por sumas sucesivas es: %d",suma);  
        }
        if (a<0 && b<0){
            a = a*-1;
            b = b*-1;
            for (i=0; i<b; i++){
                suma = suma +a;
            }
            printf("El producto por sumas sucesivas es: %d",suma);  
        }
        if(a==0 || b==0){
            printf("El producto es 0.");
        }
        if (a>0 && b<0){
            a = a*-1;
            for (i=b; i<0; i++){
                suma = suma +a;
            }
        printf("El producto por sumas sucesivas es: %d",suma);  
        }
       
        
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);

    }

    return 0;
}
