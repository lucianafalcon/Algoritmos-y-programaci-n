/******************************************************************************
5) Ingresar el radio de una esfera y calcular el volumen.
*******************************************************************************/

#include <stdio.h>

int main()
{
    char continuar = 's';
    float r;
    float volumen;
    
    while(continuar == 's'){
        printf("Ingresar radio de la esfera: ");
        scanf("%f",&r);
        
        volumen = (4/3)*3.14*r;
        printf("El volumenvde la esfera es =  %f\n", volumen);
        
        printf("desdea continuar? s/n: \n");
  
        scanf("%c",&continuar);
        scanf("%c",&continuar);    
    }

    return 0;
}
