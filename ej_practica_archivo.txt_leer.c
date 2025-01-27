/* ej leer texto 
Usando un editor de texto plano, por ejemplo el block de notas; crea un archivo TXT, llamado texto1.txt. 
Escribí un texto corto, que comience con: 
"Mi nombre es ........, y mi padrón es ...........
 Nací el .......................".

Luego escribí un programa modular en C, que lea el archivo que creaste y muestre por pantalla el texto, y luego indique la cantidad de
caracteres numéricos que hay en el archivo".

El archivo sólo se puede leer una vez.
*/

#include <stdio.h>


void leer_archivo(FILE *archivo){
    char caracter;
    int contador = 0;

    archivo = fopen("ej_archivo_texto_leer_texto.txt", "r");
    if(archivo == NULL){
        printf("no se pudo abrir\n");
    }

    caracter = fgetc(archivo);
    

    while(caracter != EOF){
        if(caracter >= '0' && caracter <= '9'){
            contador++;
        }
        caracter = fgetc(archivo);
    }

    fclose(archivo);

    printf("Cantidad de numeros en el archivo: %d", contador);

}


int main(){

    FILE *archivo;

    leer_archivo(archivo);

    return 0;
}
