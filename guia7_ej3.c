/* guia 7 - ej 3
3) Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres
correspondientes según el código ASCII.*/

#include <stdio.h>

typedef struct{
    int num;
}t_registro;

void caracter_ascii(FILE *archivo){

    t_registro reg;
    int ascii;

    fopen("guia7_ej3_archivo.dat", "rb");

    fread(&reg, sizeof(reg), 1, archivo);
    while (!feof(archivo)){
        ascii = reg.num;
        printf("el codigo ascci de %d es %c\n", reg.num, ascii);
        fread(&reg, sizeof(reg), 1, archivo);
    }
    
    fclose(archivo);

} 

int main(){
    t_registro reg;

    FILE *archivo;

    //creo el archivo de nros entre 0 y 255:
    archivo = fopen("guia7_ej3_archivo.dat", "wb");
    reg.num = 1;
    fwrite(&reg, sizeof(reg), 1, archivo);
    reg.num = 41;
    fwrite(&reg, sizeof(reg), 1, archivo);
    reg.num = 100;
    fwrite(&reg, sizeof(reg), 1, archivo);
    reg.num = 200;
    fwrite(&reg, sizeof(reg), 1, archivo);
    reg.num = 255;
    fwrite(&reg, sizeof(reg), 1, archivo);
    fclose(archivo);

    archivo = fopen("guia7_ej3_archivo.dat", "rb");
    fread(&reg, sizeof(reg), 1, archivo);
        while( !feof(archivo)){
            printf("registro: %d\n ", reg.num);
            fread(&reg, sizeof(reg), 1, archivo);
        }
    fclose(archivo);       

    caracter_ascii(archivo);

    return 0;
}