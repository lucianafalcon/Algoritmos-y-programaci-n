/*
Escribir un programa modular en C, que permita listar los datos de los productos que se encuentran en el archivo productos.dat.
La estructura de los registros es la siguiente:
    typedef struct{
        int codigo;
        char descripcion[30];
        float cantidad;
    }t_regProducto;
El archivo sólo se puede leer una vez.
Informar al final del listado, el total de Productos en Stock.
Para la construcción del programa, podés utilizar el editor del intérprete o el IDE que prefieras.
Luego copia y pega lo que hayas hecho en la caja de texto de esta actividad y efectuá la entrega de la misma.
*/

#include <stdio.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;



int main(){
    float total_stock=0;

    t_regProducto registro;

    FILE *archivo;

    archivo = fopen("productos.dat", "rb");
    if( archivo == NULL){
        printf("Error. Archivo no se puede leer");
    }else{

        fread(&registro, sizeof(t_regProducto), 1, archivo);

        while(!feof (archivo)){
            total_stock += registro.cantidad;
            fread(&registro, sizeof(t_regProducto), 1, archivo);
        }

    fclose(archivo);
    }

    printf("La cantidad de stock total es: %f", total_stock);

    return 0;
}
