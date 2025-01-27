/*guia 7 - ej 7
7) Leer un archivo de caracteres que representa un texto formado por
oraciones terminadas en punto. Copiarlo en otro archivo eliminando los
espacios superfluos.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef char t_cadena[MAX];

void eliminador_espacios(FILE *archivo, FILE *archivo2){

    archivo = fopen("guia7_ej7_archivo.txt", "r");
    archivo2 = fopen("guia7_ej7_archivo2", "w");

    if(archivo == NULL){
        printf("no se pudo leer el archivo");
    }else{
        t_cadena cadena;
        char caracter;
        char anterior;
        int i;

        bool encontre = false;
        caracter = fgetc(archivo);
        i=0;
        
        while( caracter != EOF ){
            /*if(cadena[i] != ' '){
                caracter[0] = caracter;
            }*/
            
            if(caracter != ' '){
                fputc(caracter, archivo2);
                printf("%c",caracter);
            }else if(caracter == ' ' && anterior != ' ' && i>0){
                fputc(caracter, archivo2);
                printf("%c",caracter);
            }

            anterior = caracter;
            caracter = fgetc(archivo);
        }

    }

    fclose(archivo);
    fclose(archivo2);
}

int main(){
    FILE *archivo;
    FILE *archivo2;

    eliminador_espacios(archivo, archivo2);

    return 0;
}