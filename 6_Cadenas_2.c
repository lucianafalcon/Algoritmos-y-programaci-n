/* guia 6 - ej 2
2. Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
No tener en cuenta la ñ, ni las vocales acentuadas.
*/

#include <stdio.h>

int carac_no_alfabeticos(char cadena[]){
    int i, cantidad = 0;

    i=0;
    while(cadena[i] != '\0'){
        if((cadena[i] < 'A' || cadena[i] >'Z')  && (cadena[i] < 'a' || cadena[i]> 'z')){
        cantidad ++;
        }   
        i++;
    }

    return cantidad;
}

int main(){
    int x; 
    char cadena[]= "hola 1 COMO 2 estas 3";

    x = carac_no_alfabeticos(cadena);

    printf("resultado: %d", x);


    return 0;
}