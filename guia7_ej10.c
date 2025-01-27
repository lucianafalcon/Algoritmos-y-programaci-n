/* guia 7 - ej 10
10) Una empresa tiene en un archivo llamado “PERSONAL.DAT”, los
siguientes datos de sus empleados: NOMBRE CATEGORIA SUELDO. El
archivo está ordenado por categoría. Se pide emitir el siguiente listado:
LISTADO DE PERSONAL
CATEGORIA XX
MEDINA, JUAN PABLO
RIOS, LORENA
CATEGORIA YY
SALERNO, VICTORIA
ARANDA, MIGUEL
Además, utilizando el citado archivo:
a) Emita un listado con las categorías y el total de sueldos de
cada una de ellas.
b) Informe el empleado de mayor sueldo de cada categoría
c) Informe cuántos empleados hay en cada categoría y cuántos
hay en toda la empresa.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 21  //se inlcluye al '/0'
#define MAX_CAT 3

typedef struct{
    char nombre[MAX_NOMBRE];
    char categoria[MAX_CAT];
    float sueldo;
}t_registro;

void listado(FILE *archivo){

    archivo = fopen("guia7_ej10_archivo.dat", "rb");

    t_registro reg;

    char cat_actual[3];
    fread(&reg, sizeof(reg), 1, archivo);
    strcpy(cat_actual, reg.categoria);
    printf("CATEGORIA %s\n", reg.categoria);
    while(!feof(archivo)){
        if(strcmp(cat_actual, reg.categoria) != 0){
            strcpy(cat_actual, reg.categoria); 
            printf("CATEGORIA %s\n", cat_actual);
            printf("%s\n", reg.nombre);
            printf("%f\n", reg.sueldo);
        }else{
            printf("%s\n", reg.nombre);
            printf("%f\n", reg.sueldo);
        }
        fread(&reg, sizeof(reg), 1, archivo);
    }


    fclose(archivo);

}



int main(){

    FILE *archivo;
    t_registro reg;
/*
    archivo = fopen("guia7_ej10_archivo.dat", "wb");

    strcpy(reg.nombre, "MEDINA, JUAN PABLO");
    strcpy(reg.categoria,"XX");
    reg.sueldo =300000;
    fwrite(&reg, sizeof(reg), 1, archivo);

    strcpy(reg.nombre, "RIOS, LORENA");
    strcpy(reg.categoria,"XX");
    reg.sueldo = 350000;
    fwrite(&reg, sizeof(reg), 1, archivo);

    strcpy(reg.nombre, "SALERNO, VICTORIA");
    strcpy(reg.categoria,"YY");
    reg.sueldo = 330000;
    fwrite(&reg, sizeof(reg), 1, archivo);

    strcpy(reg.nombre, "ARANDA, MIGUEL");
    strcpy(reg.categoria,"YY");
    reg.sueldo = 340000;
    fwrite(&reg, sizeof(reg), 1, archivo);

    fclose(archivo);
*/
    listado(archivo);

    return 0;
}