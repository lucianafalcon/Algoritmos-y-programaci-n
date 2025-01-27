/*
Usando un editor de texto plano, por ejemplo el block de notas; crea un archivo TXT, llamado texto1.txt. 
Escribí un texto corto, que comience con: 
"Mi nombre es ........, y mi padrón es ...........
 Nací el .......................".

Escribí un programa modular en C, que agregue al archivo de Texto, una nueva línea que comience con:

"Estoy estudiando la carrera ........................."*/

#include <stdio.h>

#define MAX_CARAC 30

typedef char t_cadena[MAX_CARAC];

void agregar_texto(FILE *archivo){

    t_cadena carrera;

    printf("Ingrese la carrera que esta estudiando: ");
    fgets(carrera, MAX_CARAC, stdin);

    archivo = fopen("ej_archivo_texto_agregar_texto.txt", "a");

    fprintf(archivo, "estoy estudiando la carrera %s", carrera);

    fclose(archivo);

}

int main(){

    FILE *archivo;

    agregar_texto(archivo);

    return 0;
}