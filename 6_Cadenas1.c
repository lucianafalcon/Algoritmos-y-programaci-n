/* guia 6 - cadenas
1. Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de dígitos numéricos que hay en la cadena.
*/

#include <stdio.h>


int cantidad_digitos(char cadena[]){
    int cantidad =0; 


    while (cadena[cantidad] != '\0'){
        cantidad ++;
    }

    return cantidad;
}

int main(){
    int x;

    char cadena[] = "hola como estas";

    x = cantidad_digitos(cadena);

    printf("resultado: %d", x);

    return 0;
}