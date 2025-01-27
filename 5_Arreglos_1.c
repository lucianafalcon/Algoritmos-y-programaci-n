/*
1) Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición.*/

#include <stdio.h>


void vector(int ML, int listado){
    int i,j;
    int digito = listado%10;
    int vector[ML];

    for(i=0;i<ML;i++){
        vector[i]=0;
    }

    for(i=0; i<ML;i++){
        vector[i]= digito;
        listado = listado/10;
        digito = listado%10;
    }
    
    printf("El contenido del vector es: \n");
    /*for(j=0; j<ML; j++){
            i= ML-i-1;   
            printf("posicion: %d", j);
            printf("digito: %d \n", vector[i]);
    }*/
    
    i = 0;
    for (j=ML-1; j>=0; j--){
        printf("posicion: %d", i);
        printf("digito: %d \n", vector[j]);
        i++;
    }

}

int main(){
    int numero;
    int listado;

    printf("Ingrese un numero:");
    scanf("%d", &numero);
    
    printf("Ingrese un listado con %d numeros: ");
    scanf("%d", &listado);

    vector(numero, listado);

    return 0;
}