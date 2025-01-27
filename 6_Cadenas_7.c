/*guia 6 - ej 7
7. Escribir una función en C, que reciba una cadena que representa una palabra y
devuelva si la misma es o no un palíndromo.
Una palabra es un palíndromo, si se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- algoritmos (No es palíndromo)
- programas (No es palíndromo)
Evitar realizar ciclos innecesarios.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool espalindromo(char palabra[]){
    bool palindromo = true;
    int largo, i;

    largo = strlen(palabra);

    i=0;
    while(i < largo/2 && palindromo){
        if(palabra[i] != palabra[(largo-1)-i]){
            palindromo = false;
        }
        i++;
    }

    return palindromo;
}


int main(){

    
    int rta;
    char palabra[] = "ana";

    rta = espalindromo(palabra); // (Es palíndromo)
    printf("%s ", palabra );
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }
    
    rta = espalindromo("ojos"); // (Es palíndromo)
    printf("ojos ");
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }

    strcpy(palabra, "radar");
    rta = espalindromo(palabra);   //(Es palíndromo)
    printf("%s ", palabra );
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }

    strcpy(palabra, "reconocer");
    rta= espalindromo(palabra);  // (Es palíndromo)
    printf("%s ", palabra );
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }

    strcpy(palabra, "algoritmos");
    rta = espalindromo(palabra);   // (No es palíndromo)
    printf("%s ", palabra );
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }

    strcpy(palabra, "programas");
    rta = espalindromo(palabra);  // (No es palíndromo)
    printf("%s ", palabra );
    if(rta){
        printf("es palindromo\n");
    }else{
        printf("no es palindromo\n");
    }





    return 0;
}