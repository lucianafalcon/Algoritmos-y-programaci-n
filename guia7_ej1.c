/* guia 7- ej 1
1) Dado un archivo de números enteros mayores o iguales que 0, generar otro
archivo que almacene los factoriales de cada número del registro
correspondiente del archivo de entrada.

*/

#include <stdio.h>

typedef struct{
    int num;
}t_registro;       

void leer_binario(FILE *archivo2){
    t_registro reg;

    archivo2 = fopen("guia7_ej1_archivo2.dat", "rb");
    fread( &reg, sizeof(reg) , 1, archivo2);

    while(!feof(archivo2)){
        
        printf("%d\n",reg.num);
        fread( &reg, sizeof(reg) , 1, archivo2);
    }
    fclose(archivo2);
}

void archivo_factorial(FILE *archivo, FILE *archivo2){
    
    archivo = fopen("guia7_ej1_archivo.dat", "rb");     //paso 2 - abro el archivo lectura
    archivo2 = fopen("guia7_ej1_archivo2.dat", "wb"); 

  //  fscanf(archivo, "%s", &reg_entrada.num);     //paso 3 - leo archivo

    if(archivo == NULL){
        printf("no se pudo abrir el archivo");
    }else{
        int i;
        int factorial;
        t_registro registro;

        fread( &registro, sizeof(registro) , 1, archivo);

        while( feof(archivo) == 0){                                   // 0 es false    |   paso 4- control de fin de archivo
            printf("archivo dat: %d\n", registro.num);
        
            factorial = 1;
            if( registro.num != 0){
                for(i = registro.num; i>0; i--){          
                    factorial = factorial * i;          
                }
            }
            printf("factorial es: %d\n", factorial);
            
            fwrite(&factorial, sizeof(factorial), 1, archivo2);               // <- escribo el segundo archivo

            fread( &registro, sizeof(registro) , 1, archivo);

        }
    } 

    fclose(archivo);     //paso 5 - cierre archivo
    fclose(archivo2);
}


int main(){

    t_registro registro;

    FILE *archivo;     // paso 1- declaracion archivo lectura
    FILE *archivo2;

    archivo = fopen("guia7_ej1_archivo.dat", "wb");

    registro.num = 1;
    fwrite(&registro.num, sizeof(t_registro), 1, archivo);

    registro.num = 2;
    fwrite(&registro.num, sizeof(t_registro), 1, archivo);

    registro.num = 3;
    fwrite(&registro.num, sizeof(t_registro), 1, archivo);

    registro.num = 4;
    fwrite(&registro.num, sizeof(t_registro), 1, archivo);

    registro.num = 0;
    fwrite(&registro.num, sizeof(t_registro), 1, archivo);

    fclose(archivo);
    
    archivo_factorial(archivo, archivo2);

    leer_binario(archivo2);
    return 0;
}