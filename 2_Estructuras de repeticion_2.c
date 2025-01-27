/******************************************************************************
2. Se tiene un listado de pares ordenados (x,y) de puntos de un plano, con
-99< x <+99, -99< y <+99. Informar por cada par, si pertenece, si es
exterior o interior al rectángulo de coordenadas 3 <+x <+5, 2<+y <+3.
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    char continuar = 's';
    int x;
    int y;
    int random;
    char datos = 'n';


    while(continuar == 's'){
        
        while(datos == 'n'){
            printf("ingrese coordenada x entre -99 y 99: ");
            scanf("%d",&x);
            printf("ingrese coordenada y entre -99 y 99: ");
            scanf("%d",&y);
    
            if ((-99<x && x<99) && (-99<y && y<99)){
                datos = 's';
            }
        }
            
        if ((3<= x && x <=5) && (2<= y && y<=3)){
            printf("El par (%d,%d) pertenece al interior del rectangulo",x,y);
        }else{
            printf("El par (%d,%d) pertenece al exterior del rectangulo",x,y);
        }   
    
        printf("\ndesea continuar? s/n: ");
        scanf("%c",&continuar);
        scanf("%c",&continuar);
    }

    return 0;
}
