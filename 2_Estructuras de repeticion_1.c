/******************************************************************************
1. Se realiza una encuesta para estimar el grado de aceptación de los
productos x e y en el mercado. A cada encuestado se le pregunta si
consume el producto x y si consume el producto y. La respuesta puede
ser sí o no. Se pide calcular e informar el porcentaje de consumidores
de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    char x;
    char y;
    int sumax = 0;
    int sumay = 0;
    int ambosxy = 0;
    int algunxy = 0;
    int ningunxy = 0;
    int total = 0;
    char random;
    
    while(continuar == 's'){
        printf("Consume el producto x? s/n: ");
        scanf("%c",&x);
        scanf("%c",&random);
        printf("Consume el producto y? s/n: ");
        scanf("%c",&y);
        scanf("%c",&random);
        
        
        total = total +1;
        if (x=='s'){
           sumax = sumax +1;
        }  
        if (y=='s'){
            sumay = sumay +1;
            } 
        if (x=='s' && y=='s'){
            ambosxy = ambosxy +1;
        }
        if (x=='s' || y=='s'){
            algunxy = algunxy +1;
        }else{
            ningunxy = ningunxy + 1;
        }
     
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&random);
    }  
    
    if (continuar == 'n'){
        printf("El porcentaje de consumidores del producto x es: %d\n", ((sumax*100)/total));
        printf("El porcentaje de consumidores del producto y es: %d\n", ((sumay*100)/total));
        printf("El porcentaje de consumidores de alguno de los productos es: %d\n", ((algunxy*100)/total));
        printf("El porcentaje de consumidores de ambos productos es: %d\n", ((ambosxy*100)/total));
        printf("El porcentaje de consumidores de ningun producto es: %d\n", ((ningunxy*100)/total));
    }

    return 0;
}
