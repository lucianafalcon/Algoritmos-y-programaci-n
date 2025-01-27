/*
6. Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
- Los caracteres deben ser todos distintos
Ejemplos:
validar("j2020") devuevle false
validar("2021a") devuevle false
validar("20X21") devuevle false
validar("2220") devuelve false
validar("23445776") devuelve false
validar("089") devuelve false
validar("027845321") devuelve false
validar("02784532") devuelve true
validar("33333") devuelve false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool validar(char clave[]){
    int long_clave, i, j;
    char aux;
    bool validacion = true;

    long_clave = strlen(clave)-1;
   
    if(long_clave < 4 || long_clave > 8){
       validacion = false;
   }


    i=0;  
    while(clave[i] != '\0' && validacion && i<long_clave){
        if(clave[i] < '0' ||  clave[i] > '9'){
            validacion = false;    
        }
        else{
            for(j = 0; j<i; j++){
                if(clave[i] == clave[j]){
                   validacion = false;
                }
            }
        }
        i++;
    }
/*    

    OTRA FORMA DE RESOLVER LO MISMO
    i=0;  
    while(clave[i] != '\0' && validacion && i<long_clave){
        printf("entra al while: %c \n", clave[i]);

         if(clave[i] >= '0' && clave[i]<='9'){
            for(j=0; j<i; j++){
                printf(" i = %c  y j= %c\n", clave[i], clave[j]);
                if(clave[i] == clave[j]){
                    validacion = false;
                }
            }
        }else{
            validacion = false;
        }
    i++;    
    }
*/
    return validacion;
}

int main(){

    char clave[100];
    char rta = 's';

    while(rta == 's'){
        fflush(stdin);
        printf("Ingresar clave: ");
        fgets(clave, sizeof(clave), stdin);
        fflush(stdin);

        if(validar(clave)){
            printf("validacion es correcta\n");
        } else{
            printf("validacion es incorrecta\n");
        }

        printf("desea ingresar otra clave? s/n: \n");
        scanf("%c", &rta);
    }

    return 0;
}