/* guia 7 - ej 4
4) Dados dos archivos de números enteros de 5 dígitos ordenados en forma
creciente, generar un archivo que contenga todos los números, ordenado de
igual forma. No hay números repetidos.*/

#include <stdio.h>

typedef struct{
    int num;
}t_registro;


void nros_ordenados(FILE *archivo, FILE *archivo2, FILE *archivo3){
    t_registro reg;
    t_registro reg2;

    archivo = fopen("guia7_ej4_archivo.dat", "rb");
    archivo2 = fopen("guia7_ej4_archivo2.dat", "rb");
    archivo3 = fopen("guia7_ej4_archivo3.dat", "wb");

    fread(&reg, sizeof(reg), 1, archivo);
    fread(&reg2, sizeof(reg2), 1, archivo2);
    while(!feof(archivo) && !feof(archivo2)){
        if(reg.num < reg2.num){
            fwrite(&reg, sizeof(reg), 1, archivo3);
            fread(&reg, sizeof(reg), 1, archivo);
        }else{
            fwrite(&reg2, sizeof(reg2), 1, archivo3);
            fread(&reg2, sizeof(reg2), 1, archivo2);
        }
    }
    //fread(&reg, sizeof(reg), 1, archivo);
    while( !feof(archivo)){
        fwrite(&reg, sizeof(reg), 1, archivo3);
        fread(&reg, sizeof(reg), 1, archivo);
    }
    //fread(&reg2, sizeof(reg2), 1, archivo2);
    while( !feof(archivo2)){
        fwrite(&reg2, sizeof(reg2), 1, archivo3);
        fread(&reg2, sizeof(reg2), 1, archivo2);
    }

    fclose(archivo);
    fclose(archivo2);
    fclose(archivo3);

    //compruebo si el archivo 3 esta OK
    archivo3 = fopen("guia7_ej4_archivo3.dat", "rb");
    fread(&reg, sizeof(reg), 1, archivo3);
    while(!feof(archivo3)){
        printf("archivo3 ordenado: %d\n", reg.num);
        fread(&reg, sizeof(reg), 1, archivo3);
    }
    fclose(archivo3);

}


int main(){
    t_registro reg;

    FILE *archivo;
    FILE *archivo2;
    FILE *archivo3;

/*
    archivo = fopen("guia7_ej4_archivo.dat", "wb");
    archivo2 = fopen("guia7_ej4_archivo2.dat", "wb");
    reg.num = 0;
    while(reg.num >= 0){
        printf("Ingrese nro al archivo 1, finaliza con negativo: ");
        scanf("%d", &reg.num);
        if(reg.num >=0){
            fwrite(&reg, sizeof(reg), 1, archivo);
        }  
    }
    fclose(archivo);
    reg.num = 0;
    while(reg.num >= 0){
        printf("Ingrese nro al archivo 2, finaliza con negativo: ");
        scanf("%d", &reg.num);
        if(reg.num >=0){
            fwrite(&reg, sizeof(reg), 1, archivo2);
        }   
    }
    fclose(archivo2);

*/
    archivo = fopen("guia7_ej4_archivo.dat", "rb");
    archivo2 = fopen("guia7_ej4_archivo2.dat", "rb");
    fread(&reg, sizeof(reg), 1, archivo);
    while( !feof(archivo) ){
        printf("archivo1: %d\n", reg.num);
        fread(&reg, sizeof(reg), 1, archivo);
    }
    fread(&reg, sizeof(reg), 1, archivo2);
    while( !feof(archivo2) ){
        printf("archivo2: %d\n", reg.num);
        fread(&reg, sizeof(reg), 1, archivo2);
    }
    fclose(archivo);
    fclose(archivo2);

    nros_ordenados(archivo, archivo2, archivo3);


    return 0;
}