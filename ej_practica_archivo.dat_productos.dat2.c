/*
Escribir un programa modular en C, que solicite el ingreso de un código de producto, y luego muestre los datos asociados al mismo, 
que se encuentran en el archivo productos.dat
Si el código de producto no existe, debe mostrarse el mensaje "Código de Producto Inexistente".
El programa debe continuar solicitando el ingreso de códigos de próducto hasta que se ingrese 0.

La estructura de los registros es la siguiente:

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;


void buscar_codigo(int nro){
    bool encontrado = false;

    t_regProducto registro;

    FILE* archivo;

    archivo = fopen("productos.dat", "rb");
    
    fread(&registro, sizeof(t_regProducto), 1, archivo);
    
    while(!feof (archivo)){
        if( nro == registro.codigo){
            printf("codigo: %d - descripcion: %s - cantidad: %f\n", registro.codigo, registro.descripcion, registro.cantidad);
            encontrado = true;
        }
        fread(&registro, sizeof(t_regProducto), 1, archivo);
    }

    fclose(archivo);

    if(!encontrado){
        printf("Codigo de Producto Inexistente\n");
    }
    
}

int main(){
    int nro;

    printf("Ingrese codigo de producto: ");
    scanf("%d", &nro);

    while(nro != 0){
        buscar_codigo(nro);
        printf("Ingrese codigo de producto: ");
        scanf("%d", &nro);
    }

    return 0;
}