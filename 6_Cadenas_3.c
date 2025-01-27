/* guia 6 ej 3
3. Escribir una función en C, que reciba como parámetro una cadena de tipo
t_cadena, y devuelva la cantidad de palabras que hay en la cadena.
Considerar que una palabra está separada de otra, por uno ó más blancos.
No recorrer la cadena más de una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes caso de prueba:

cant_palabras("El sol es amarillo.") devuevle 4
cant_palabras(" Hoy es 30 de Junio de 2021 ") devuevle 7
cant_palabras("30/06/2021") devuelve 1
cant_palabras("El precio es $2.000.- ") devuelve 4
cant_palabras(" ") devuelve 0

*/
#include <stdio.h>
#include <string.h>

#define MF 30 

typedef char t_cadena[MF];

int cant_palabras(t_cadena cadena){
    int i, cantidad=0;

    if(strlen(cadena) == 2 && cadena[0] == ' '){
        cantidad = 0;
    }
    if (strlen(cadena) == 2 && cadena[0] != ' '){
        cantidad++;
    }
    
    i=0;
    
    while( cadena[i] != '\0'){
        
        if((cadena[i] != ' ' && cadena[i+1] == ' ') || (cadena[i] != ' ' && cadena[i+1] == ' ')){
            cantidad++;
        }
        i++;
    }

    if((strlen(cadena) > 1 && cantidad == 0) || (cadena[i-1] != ' '))
        cantidad++;

 /*  OTRA FORMA: 
    i=0;
    while(cadena[i] == ' '){
        i++;
    }

    while(cadena[i] != '\0'){
        if(cadena[i] == ' ' && cadena[i+1] != ' '){
            cantidad++;
        }
        i++;
    }

    if((strlen(cadena) > 1 && cantidad == 0) || (cadena[i-1] != ' '))
        cantidad++;
*/
    return cantidad;

}

int main(){
    int x;

    t_cadena cadena = "el sol es amarillo";
    x = cant_palabras(cadena);
    printf("resultado 1: %d \n", x); // devuevle 4

    strcpy(cadena, " Hoy es 30 de Junio de 2021 "); 
    x = cant_palabras(cadena); 
    printf("resultado 2: %d \n", x);  //devuevle 7

    strcpy(cadena, "30/06/2021");
    x = cant_palabras(cadena); 
    printf("resultado 3: %d \n", x);  //devuelve 1

    strcpy(cadena, "El precio es $2.000.- "); 
    x = cant_palabras(cadena); 
    printf("resultado 4: %d\n", x);  //devuelve 4
    
    strcpy(cadena, " "); 
    x = cant_palabras(cadena); 
    printf("resultado 5: %d", x);  //devuelve 0

    return 0;

}