/*guia 6 - ej 5
5. Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave candidata, que ya fue ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones:
- La clave debe estar formada únicamente por, entre 6 y 12 caracteres
numéricos
- La cantidad de dígitos pares debe ser mayor a la de los impares.
A los sumo debe recorrer una vez la cadena.
Evite realizar ciclos innecesarios.
Compruebe el correcto funcionamiento, incluyendo los siguientes casos de
prueba:
validar("j20893") devuevle false  0          ->tiene 6
validar("20893a") devuevle false  0          -> tiene 6
validar("208X930") devuevle false  0         ->tiene 7
validar("20201") devuelve false  0           ->tiene 5
validar("23445776") devuelve false  0        ->tiene 8
validar("089010") devuelve true  1           ->tiene 6
validar("02784532132567") devuelve false  0  -> tiene 14
validar("027845320011") devuelve true  1     ->tiene 12
*/

#include <stdio.h>
#include <stdbool.h>  // 1 ES TRUE
#include <string.h>

bool validar(char cadena[]){
    bool clave = true, pararcontar = false;
    int i, contador=0;

    if (strlen(cadena) < 6 || strlen(cadena) > 12){
        clave =false;
    }

    else{
        i=0; 
        while(cadena[i] != '\0' && pararcontar == false){
            if(cadena[i] >= '0' && cadena[i] <= '9' && cadena[i]%2 == 0){        
                contador++;
            }   
            else if(cadena[i]<'0' || cadena[i] > '9'){
                pararcontar = true;
            }
            i++;
        }
    }
 //   printf("contador %d\n", contador);
 //   printf("largo %d\n", strlen(cadena)/2);

    if(pararcontar == true || contador <= (strlen(cadena)/2)){
            clave = false;
    }


    return clave;
}

int main(){

    char clave[] = "j20893";
    bool x;
   
    x = validar(clave);
    printf("resultado1: %d \n", x);   // devuevle false
    
    x = validar("20893a");
    printf("resultado2: %d \n", x);   // devuevle false

    x = validar("208X930");
    printf("resultado3: %d \n", x);   // devuevle false

    x = validar("20201");
    printf("resultado4: %d \n", x);   //devuelve false
    x = validar("23445776");
    printf("resultado5: %d \n", x);   // devuelve false

    x = validar("089010");
    printf("resultado6: %d \n", x);   // devuelve true

    x = validar("02784532132567"); 
    printf("resultado7: %d \n", x);   // devuelve false

    x = validar("027845320011");
    printf("resultado8: %d", x);   // devuelve true

    return 0;
}