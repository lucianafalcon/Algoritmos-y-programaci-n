/******************************************************************************
1. Escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas.
Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.
Tener en cuenta que el usuario puede ingresar valores negativos.
*******************************************************************************/
 
#include <stdio.h>

int sumassucesivas(int x, int y){    // 4*3=12 ->4+4+4 
    int i;
    int suma = 0;
    
    if(y>0){                       //  (x>0 y>0) (x<0 y>0)
        for(i=0 ; i<y ; i++){    
                suma = suma + x;   
            }
    }else if(y<0){                //   (y<0 x<0)  (y<0 x>0)
        for(i=y ; i<0 ; i++){   
                suma = suma - x;   
            }
        }
    
    return suma; 
}

int main()
{
    int x;
    int y;
    int suma;
    
    printf("1er numero:");
    scanf("%d",&x);
    printf("2do numero:");
    scanf("%d",&y);
  
    suma = sumassucesivas(x,y);
    
        printf("%d * %d mediante sumas sucesivas es: %d",x,y,suma);
    
    return 0;
}
