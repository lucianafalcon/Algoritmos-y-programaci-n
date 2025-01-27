/* guia 6 - ej 4
4. Escribir una función en C que reciba como primer parámetro, una cadena de tipo
t_cadena, y devuelva como segundo parámetro, la misma cadena pero invertida,
sin considerar los blancos.
Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas
posiciones potenciales a ser utilizadas pero que podrían contener caracteres
inciertos.
Recorrer la cadena a lo sumo una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes casos y las impresiones para comprobar que devuelven lo correcto.
Casos:
invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena(" ", cad_invertida) ==> cad_invertida: ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida: "somosoNsomoS"
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

typedef char t_cadena[MAX];

void invertir_cadena(t_cadena cadena, t_cadena cad_invertida){
    int i, j, largo;

    largo = strlen(cadena);
       
    i=largo-1;
    j=0;
    while(i >= 0){
        if(cadena[i] != ' '){
            cad_invertida[j] = cadena[i];
            j++;
        }
        i--;
    }
    cad_invertida[j] = '\0';
/*
    for(i=largo-1; i>=0; i--){
        if(cadena[i] != ' '){
            cad_invertida[j] = cadena[i];
            j++;
        }
    }
    */
}


int main(){
    
    t_cadena cad_invertida;
    
    invertir_cadena("Hola, me llamo Ana.", cad_invertida);
    printf("Resultado 1: %s \n", cad_invertida);    // ==> cad_invertida: ".anAomallem,aloH"

    strcpy(cad_invertida, "");  
    invertir_cadena("234561", cad_invertida);
    printf("Resultado 2: %s \n", cad_invertida);    // ==> cad_invertida: "165432"

    strcpy(cad_invertida, "");
    invertir_cadena(" ", cad_invertida);
    printf("Resultado 3: %s \n", cad_invertida);   // ==> cad_invertida: ""

    strcpy(cad_invertida, "");
    invertir_cadena("Somos o No somos", cad_invertida);
    printf("Resultado 4: %s \n", cad_invertida);   // ==> cad_invertida: "somosoNsomoS"

    return 0;
}
