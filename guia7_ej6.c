/* guia 7 - ej 6
6) Se tiene un archivo de números telefónicos cuyos registros son de la forma:
Característica de localidad (4 dígitos)
Característica central (3 dígitos)
Número (4 dígitos)
Dado un número que representa una característica de localidad, listar
todos los números telefónicos con dicha característica.
Suponer los siguientes casos:
a) El archivo no cabe en memoria y está desordenado.
b) El archivo no cabe en memoria y está ordenado según números
telefónicos crecientes.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char num[12];
}t_registro;                   // 1234 567 1111


//ejercicio parte b:
//void buscadorbinario_telefonico(FILE *archivo, FILE *archivo2, char numero[]){





//ejercicio parte a:
void ver_archivo(FILE *archivo2){
    archivo2 = fopen("guia7_ej6_archivo2.dat", "rb");

    if(archivo2 == NULL){
        printf("no se pudo abrir el archivo\n");
    }else{

        t_registro reg;
        fread(&reg, sizeof(reg), 1, archivo2);
        while(!feof(archivo2)){
            printf("archivo2: %s\n", reg.num);
            fread(&reg, sizeof(reg), 1, archivo2);
        }
    }
    fclose(archivo2);
}

void buscador_telefonico(FILE *archivo, FILE *archivo2, char numero[]){

    archivo = fopen("guia7_ej6_archivo.dat", "rb");
    archivo2 = fopen("guia7_ej6_archivo2.dat", "wb");

    if(archivo == NULL){
        printf("no se pudo abrir el archivo\n");
    }else{

        t_registro reg;
        bool escribir = true;
        int i;
        fread(&reg, sizeof(reg), 1, archivo);
        while(!feof(archivo)){
            for(i=0; i<4; i++){
                if(reg.num[i] != numero[i]){
                    escribir = false;
                }
            }
          if(escribir){
            fwrite(&reg, sizeof(reg), 1, archivo2);
          }

        fread(&reg, sizeof(reg), 1, archivo);
        escribir = true;
    }
/*
    fread(&reg, sizeof(reg), 1, archivo2);
    while(!feof(archivo2)){
        printf("archivo2: %s\n", reg.num);
        fread(&reg, sizeof(reg), 1, archivo2);
    }
*/
    fclose(archivo);
    fclose(archivo2);
    }

}


int main(){
    FILE *archivo;
    FILE *archivo2;
    char num[5] = "0011";
    t_registro reg;

/*    //relleno el archivo.dat:
    archivo = fopen("guia7_ej6_archivo.dat", "wb");
    strcpy(reg.num, "12341112121");
    fwrite(&reg, sizeof(reg), 1, archivo);
    strcpy(reg.num, "00111113322");
    fwrite(&reg, sizeof(reg), 1, archivo);
    strcpy(reg.num, "00111114455");
    fwrite(&reg, sizeof(reg), 1, archivo);
    strcpy(reg.num,"12341115555");
    fwrite(&reg, sizeof(reg), 1, archivo);
    strcpy(reg.num, "12341116767");
    fwrite(&reg, sizeof(reg), 1, archivo);
    strcpy(reg.num, "00111117677");
    fwrite(&reg, sizeof(reg), 1, archivo);
    fclose(archivo);

    buscador_telefonico(archivo, archivo2, num);
*/    ver_archivo(archivo2);
    return 0;
}