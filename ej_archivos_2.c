/* ej archivos 2
Una institucion educativa posee los siguientes archivos binarios:
Archivo de socios (socios.dat) contiene todos los socios actuales de la institucion
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string).

Archivo de Socios Nuevos (nuevos.dat) contiene los socios nuevos
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string), Sucursal (entero)

Todos los dias se recibe el archivo de Socios nuevos con la altas realizadas el dia anterior 
y se desea actualizar el archivo de socios agregando los socios nuevos.
Ambos archivos estan ordenados por DNI en forma ascendente.
En caso de que el DNI de un socio nuevo ya existiera en el archivos de socios se debe actualizar el campo Nombre y apellido 
y agregar el DNI a un archivo de texto llamado actualizaciones.txt

Escribir un programa en lenguaje C que genere un tercer archivo de socios actualizado
(sociosAct.dat)
Este archivo debe quedar ordenado por DNI en forma ascendente.
*/ 


//VERSION RODRIGO
#include <stdio.h>
#include <string.h>

typedef struct
{
    int dni;
    int num_socio;
    char nombre_apellido[50];
} Socios;

typedef struct
{
    int dni;
    int num_socio;
    char nombre_apellido[50];
    int sucursal;
} SociosNuevos;

void actualizarSocios(FILE *archivo_socios, FILE *archivo_nuevos_socios, FILE *archivo_socios_activos, FILE *archivo_actualizaciones)
{
    Socios socio_actual;
    Socios aux;
    SociosNuevos nuevo;

    archivo_socios = fopen("socios.dat", "rb");
    archivo_nuevos_socios = fopen("nuevos.dat", "rb");
    archivo_socios_activos = fopen("sociosAct.dat", "w");
    archivo_actualizaciones = fopen("actualizaciones.txt", "w");

    if (archivo_socios == NULL || archivo_nuevos_socios == NULL || archivo_socios_activos == NULL || archivo_actualizaciones == NULL)
    {
        printf("Error al abrir alguno de los archivos\n");
    }
    else
    {

        fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
        fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);

        while (!feof(archivo_socios) && !feof(archivo_nuevos_socios))
        {
            if (socio_actual.dni < nuevo.dni)
            {
                fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);
                fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
            }
            else if (socio_actual.dni == nuevo.dni)
            {
                strcpy(socio_actual.nombre_apellido, nuevo.nombre_apellido);
                fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);

                fprintf(archivo_actualizaciones, "%d\n", socio_actual.dni);

                fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
                fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
            }
            else
            {
                aux.dni = nuevo.dni;
                strcpy(aux.nombre_apellido, nuevo.nombre_apellido);
                aux.num_socio = nuevo.num_socio;

                fwrite(&aux, sizeof(aux), 1, archivo_socios_activos);
                fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
            }
        }

        while (!feof(archivo_socios))
        {
            fwrite(&socio_actual, sizeof(socio_actual), 1, archivo_socios_activos);
            fread(&socio_actual, sizeof(socio_actual), 1, archivo_socios);
        }

        while (!feof(archivo_nuevos_socios))
        {
            aux.dni = nuevo.dni;
            strcpy(aux.nombre_apellido, nuevo.nombre_apellido);
            aux.num_socio = nuevo.num_socio;

            fwrite(&aux, sizeof(aux), 1, archivo_socios_activos);
            fread(&nuevo, sizeof(nuevo), 1, archivo_nuevos_socios);
        }
    }

    fclose(archivo_socios);
    fclose(archivo_nuevos_socios);
    fclose(archivo_socios_activos);
    fclose(archivo_actualizaciones);
}

int main()
{
    FILE *archivo_socios, *archivo_nuevos_socios, *archivo_socios_activos, *archivo_actualizaciones;

    actualizarSocios(archivo_socios, archivo_nuevos_socios, archivo_socios_activos, archivo_actualizaciones);

    return 0;
}





//VERSION CAMILA

#include <string.h>
#define MAX_CARACTERES 60

typedef char Tnombres[MAX_CARACTERES];
typedef struct
{
    int dni;
    int num_socio;
    Tnombres nombre;//no se me ocurre un nombre mejorxd help
}reg_socios;

typedef struct
{
    int dni;
    int num_socio;
    Tnombres nombre;//no se me ocurre un nombre mejorxd help
    int sucursal;
}reg_socios_nuevos;

void cargar_socios_nuevos()
{
    FILE* socios, socios_nuevos, actualizaciones,archivo;
    reg_socios socio;
    reg_socios_nuevos socio_nuevo;

    archivo = fopen("sociosAct.dat", "wb");
    socios = fopen("socios.dat", "rb");
    socios_nuevos = fopen("nuevos.dat", "rb");
    actualizaciones = fopen("actualizaciones.txt", "wb");
    if(socios != NULL)//opcional
    {
        printf("No se pudo abrir el archivo de socios");
        fclose(socios_nuevos);
        fclose(actualizaciones);
    }
    else
    {
        if(socios_nuevos != NULL)//opcional
        {
        printf("No se pudo abrir el archivo de socios");
        fclose(socios);
        fclose(actualizaciones);
        }
        else
        {
            fread(&socio, sizeof(socio),1,socios);
            fread(&socio_nuevo, sizeof(socio_nuevo),1,socios_nuevos);
            while(!feof(socios) && !feof(socios_nuevos))
            {
                if(socio.dni < socio_nuevo.dni)
                {
                    fwrite(&socio,sizeof(socio),1,archivo);
                    fread(&socio, sizeof(socio),1,socios);
                }
                else if(socio_nuevo.dni < socio.dni)
                {
                    fwrite(&socio_nuevo,sizeof(socio_nuevo),1,archivo);
                    fread(&socio_nuevo, sizeof(socio_nuevo),1,socios_nuevos);
                }
                else
                {
                    fwrite(&socio,sizeof(socio),1,archivo);
                    fwrite(&socio.dni,sizeof(socio.dni),1,actualizaciones);
                    fread(&socio, sizeof(socio),1,socios);
                    fread(&socio_nuevo, sizeof(socio_nuevo),1,socios_nuevos);
                }
                
            }

            while(!feof(socios))
            {
                fread(&socio, sizeof(socio),1,socios);
                fwrite(&socio,sizeof(socio),1,archivo);
            }

            while(!feof(socios_nuevos))
            {
                fread(&socio_nuevo, sizeof(socio_nuevo),1,socios_nuevos);
                fwrite(&socio_nuevo,sizeof(socio_nuevo),1,archivo);
            }
        }
    }
    fclose(actualizaciones);
    fclose(archivo);
    fclose(socios);
    fclose(socios_nuevos);
}

int main()
{
    cargar_socios_nuevos();
}


