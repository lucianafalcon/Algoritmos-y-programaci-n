/* guia 7 - ej 2
2) Dado un archivo de números enteros, generar otro archivo que contenga
aquellos que son primos en el primero.*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int num;
}t_registro;


void leer_binario(FILE *archivo2){
    t_registro reg;

    archivo2 = fopen("guia7_ej2_archivo2.dat", "rb") ;

    fread(&reg, sizeof(reg), 1, archivo2);
    while( !feof(archivo2)){
        printf("%d", reg.num);
        fread(&reg, sizeof(reg), 1, archivo2);

    }

    fclose(archivo2);
}

void es_primo(FILE *arnum, FILE *archivo2){

    arnum = fopen("guia7_ej2_archivo1.dat", "rb");
    archivo2 = fopen("guia7_ej2_archivo2.dat", "wb");

    if( arnum == NULL){
        printf("no se pudo abrir el archivo");
    }else{
        t_registro registro;
        int i;
        bool esprimo;

        fread(&registro, sizeof(registro) , 1, arnum);
        while( feof(arnum) == 0 ){           //otra forma:   !feof(archivo)
            esprimo = true;
            if (registro.num <= 1){
                    esprimo = false;
            }else{
                for(i=(registro.num)/2; i>1; i--){
                    if(registro.num % i == 0){
                        esprimo = false;
                    }
                 }
            }
            if(esprimo){
                printf("el primo: %d\n", registro.num);
                fwrite(&registro.num, sizeof(registro.num), 1, archivo2);
            }  
            fread(&registro, sizeof(registro) , 1, arnum);  
        }
    }

    fclose(arnum);
    fclose(archivo2);
}



int main(){
    int num;
    char rta = 's';
    t_registro registro;

    FILE *arnum;  
    FILE *archivo2;

    arnum = fopen("guia7_ej2_archivo1.dat", "wb");

    while( rta == 's' ){
        printf("ingrese nro: ");
        scanf("%d", &registro.num);

        fwrite(&registro.num, sizeof(t_registro), 1, arnum);

        printf("desea ingresar otro nro? s/n: ");
        scanf("%c", &rta);
        scanf("%c", &rta);
    }

    fclose(arnum);

    es_primo(arnum, archivo2);

    leer_binario(archivo2);

    return 0;
}