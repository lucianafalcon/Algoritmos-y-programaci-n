/* Ejercicio 3 Archivos binario - Salida a un archivo TXT
Dado el archivo binario adjunto, y que posee la siguiente estructura:

	int codigo;
        char descripcion[30];
        float stock;

Escribir un programa modular en C, que deje en un archivo .txt, la descripción de aquellos artículos cuyo stock, sea nulo. 
Los productos con stock, deben ser mostrados por pantalla todos sus datos.
El archivo sólo puede ser recorrido una vez en su totalidad.*/

#include <stdio.h>
#define MAX_DESC 100

typedef struct{
    int codigo;
    char descripcion[MAX_DESC];
    float stock;
}t_regProducto;

void stock_productos(FILE *productos, FILE *texto){

    t_regProducto Producto;

    if (productos == NULL){
        printf("No se pudo abrir el archivo");
    }else{
        int contador = 0;

        fread(&Producto, sizeof(Producto), 1, productos);

        while( !feof(productos) ){
            if(Producto.stock == 0){
                fprintf(texto, "\n%s", Producto.descripcion);
            }else{
                if(contador == 0){
                    printf("\n Codigo \tDescripcion \t\t\tcantidad");
                }
                contador ++;
                printf("\n %d \t\t %-30s %8.2f", Producto.codigo, Producto.descripcion, Producto.stock);
            }
            fread(&Producto, sizeof(Producto), 1, productos);
        }
    }
    fclose(productos);
    fclose(texto);

}

int main(){
    FILE *productos;
    FILE *texto;

    stock_productos(productos, texto);

    return 0;
}