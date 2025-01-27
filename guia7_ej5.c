/* guia 7 - ej 5
5) Dado un archivo de apellidos y nombres, generar otro archivo con los
mismos datos ordenados alfabéticamente.
Suponer que el archivo de entrada cabe en memoria.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

typedef char t_vector[MAX];
typedef t_vector t_matriz[MAX];

void alfabeticamente(FILE *archivo, FILE *archivo2){

    archivo = fopen("guia7_ej5_archivo.txt", "r");
    archivo2 = fopen("guia7_ej5_archivo2.txt", "w");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo");
    }else{
        t_matriz cadena; 
        t_vector vector;
        int i;

        i=0;
        int ML = 0;
        //fscanf(archivo,"%s", cadena1);
        fgets(vector, MAX, archivo);
        while( feof(archivo) == 0){   // igual a hacer !feof(archivo)  
            //cadena[i] = cadena1;
            strcpy(cadena[i],vector);
            //fscanf(archivo,"%s", cadena1);
            ML ++;
            fgets(vector, MAX, archivo);
            i++;
        }
               
        int j;
        bool intercambio=true;
        t_vector aux; 
        
        i=1;
        while(intercambio && i < ML){
            intercambio = false;
            for(j=0; j< ML-i; j++){
                if( strcmp(cadena[j], cadena[j+1]) > 0 ){    
                    strcpy(aux, cadena[j]);
                    strcpy(cadena[j], cadena [j+1]);
                    strcpy(cadena[j+1], aux);
                    intercambio = true;
                }
            }
            i++;
        }

    for(i=0; i<ML; i++){
            printf("ordenado: %s\n", cadena[i]);
            fprintf(archivo2, "%s", cadena[i]);
        }
    }

    

    fclose(archivo);
    fclose(archivo2);

}


int main(){
    FILE *archivo;
    FILE *archivo2;

    alfabeticamente(archivo, archivo2);

    return 0;
}