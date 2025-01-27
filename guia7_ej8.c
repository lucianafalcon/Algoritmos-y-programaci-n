/* guia 7 - ej 8
8) Leer un archivo de caracteres que representa un texto formado por
oraciones terminadas en punto. Calcular la cantidad de monosílabos que
hay en el texto, la longitud promedio de las palabras y la cantidad de
palabras.
*/

#include <stdio.h>
#include <stdbool.h>

void monosilabos_longitud_cantidad(FILE *archivo){
    archivo = fopen("guia7_ej8_archivo.txt", "r");

    char caracter;
    caracter = fgetc(archivo);
    int contadorletras = 0;
    int contadorpalabras = 0;
    int contadorletrasxpalabra = 0;
    int monosilabos = 0;
    bool vocales = false;
    char anterior;
    
    while(caracter != EOF){          
        if(caracter != ' ' && caracter != '.' && caracter != ','){
            contadorletras++;
            contadorletrasxpalabra++;
        }
        if( (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') 
            && (anterior == 'a' || anterior == 'e' || anterior == 'i' || anterior == 'o' || anterior == 'u') ){
                vocales = true;
        }
        if ( (caracter == ' ' || caracter == '.' || caracter == ',')  && (contadorletrasxpalabra == 4 || contadorletrasxpalabra ==5) && (vocales) ){
            monosilabos++;
        }
        if(  caracter == ' ' && (contadorletrasxpalabra == 1 || contadorletrasxpalabra == 2 || contadorletrasxpalabra == 3) ){
            monosilabos++;
        }
        if(caracter == ' ' || caracter == '.' || caracter == ','){
            contadorletrasxpalabra = 0;
            contadorpalabras++;
            vocales = false;
        }
      
        anterior = caracter;
        caracter = fgetc(archivo);
    }

    fclose(archivo);

    printf("monosilabos: %d\n", monosilabos);
    printf("longitud prom de palabras: %d\n", contadorletras/contadorpalabras);
    printf("cantidad de palabras: %d\n", contadorpalabras);
    printf("contador letras: %d", contadorletras);
}

int main(){
    FILE *archivo;

    monosilabos_longitud_cantidad(archivo);

    return 0;
}