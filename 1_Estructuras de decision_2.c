/******************************************************************************
2) Hallar la superficie de un triangulo conociendo la base y la altura.
*******************************************************************************/

#include <stdio.h>

int main()
{
    float b;
    float a;
    char continuar = 's';
    
    while(continuar == 's'){
        printf("Ingrese base: ");
        scanf("%f",&b);
        printf("Ingrese altura: ");
        scanf("%f",&a);
    printf("La superficie es =  %f\n",(b*a)/2);
       
    printf("desdea continuar? s/n: \n");
    scanf("%c",&continuar);
    scanf("%c",&continuar);    
    }

    return 0;
}
