/* ej archivos 1
 Se tiene un archivo de números telefónicos cuyos registros son de la forma: 
Característica de localidad (4 dígitos) 
Característica central (4 dígitos) 
Número (4 dígitos) 
Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha característica. 
Suponer los siguientes casos: 
a) El archivo no cabe en memoria y está desordenado. 
b) El archivo no cabe en memoria y está ordenado según números telefónicos crecientes. 
*/

#include <stdio.h>
#define MIN_DIGITO 1000
#define MAX_DIGITO 9999


typedef struct {
    int c_localidad;
    int c_central;
    int numero;
} Tnumero_telefonico;

void busqueda_localidad(FILE *archivo_telefonos,   int buscado)
{ int   encontrados;
    Tnumero_telefonico telefono;
    encontrados = 0;
     archivo_telefonos = fopen("./telefonos.dat","rb");
    
    fread(&telefono, sizeof(telefono), 1, archivo_telefonos);
    while(!feof(archivo_telefonos) &&  (telefono.c_localidad<=buscado ) ){
        if (telefono.c_localidad == buscado){
            printf("%d %d %d\n", telefono.c_localidad, telefono.c_central, telefono.numero);
            encontrados += 1;
        }
        fread(&telefono, sizeof(telefono), 1, archivo_telefonos);
    }
    if(encontrados == 0){
        printf("no se encontro ninguna coincidencia\n");
    }
    fclose(archivo_telefonos);
}

 

 

int main()
{
   FILE *archivo_telefonos;
    
   int buscado;
    do {
        printf("ingrese nro de localidad (4 digitos) a buscar: ");
        scanf("%d", &buscado);
    } while (buscado < MIN_DIGITO || buscado > MAX_DIGITO   );
   
   
   
    busqueda_localidad (archivo_telefonos, buscado );
    
    return 0;
}
