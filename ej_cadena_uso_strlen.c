#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int largo;
    bool bul = true;

    char cadena[1000];

 /*   char cadena[] = "hola";
    largo =strlen(cadena);

    printf("largo cadena: %d", largo);
    printf("booleano: %d", bul);
*/

    printf("Ingresar clave: ");
    fgets(cadena, sizeof(cadena), stdin);
    fflush(stdin);

    largo =strlen(cadena);
    printf("largo cadena: %d", largo);

    return 0;
}