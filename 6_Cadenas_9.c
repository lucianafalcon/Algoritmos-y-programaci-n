/*guia 6 - ej 9
9. Escribir una función que recibirá por parámetro, una palabra, que representa un
sustantivo en singular.
La función deberá devolver, el plural de dicho sustantivo, aplicando las
siguientes reglas:
a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
b. Agregar una “s” al final, si la palabra termina con una é (acentuada).
c. Si la palabra termina en “z”, la reemplazamos por “ces”.
d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción
de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á,
í, ó, ú.
e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular,
por lo tanto la función deberá devolver lo mismo que recibió.*/

#include <stdio.h>
#include <string.h>
#define MAX 50

typedef char t_cadena[MAX];


void sust_plural(t_cadena palabra){

    int i;

    i = strlen(palabra)-1;

    if( palabra[i] == 'a' || (palabra[i] == 'e') || (palabra[i] == 'i') || (palabra[i] == 'o') || (palabra[i] == 'u')
       || (palabra[i] == 'é')  ){
            strcat(palabra,"s");

    }else

    if( palabra[i] == 'z' ){
        palabra[i] = 'c';
        strcat(palabra, "es");
    }else

    if( (palabra[i] > 'a' && palabra[i] < 'e') || (palabra[i] > 'e' && palabra[i] < 'i') ||
        (palabra[i] > 'i' && palabra[i] < 'o') || (palabra[i] > 'o' && palabra[i] < 's') ||
        (palabra[i] =='t') || (palabra[i] == 'v') || (palabra[i] == 'w' )|| (palabra[i] == 'y')
       || (palabra[i] == 'á') || (palabra[i] == 'í') || (palabra[i] == 'ó') || (palabra[i] == 'ú') ){  

        strcat(palabra, "es");
    }

}

int main(){

    char rta = 's';
  
    t_cadena palabra = "capaz";
    sust_plural(palabra);
    printf(" el plural de %s es %s \n", palabra, palabra);

    strcpy(palabra, "elefante");
    sust_plural(palabra);
    printf(" el plural de %s es %s \n", palabra, palabra);

    strcpy(palabra, "xanax");
    sust_plural( palabra);
    printf(" el plural de %s es %s \n", palabra, palabra);

    strcpy(palabra, "maneras");
    sust_plural(palabra);
    printf(" el plural de %s es %s \n", palabra, palabra);



    return 0;
}