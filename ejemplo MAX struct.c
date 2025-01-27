/*
*/

#include <stdio.h>
#include <string.h>

#define MAX 2

typedef struct{

    char nombre[MAX];

}t_registro;

int main(){

    t_registro reg;
    char nom[5];

    strcpy(nom,"alexis");

    
    printf("nombre 0 %s\n",nom);
    strcpy(reg.nombre, "alexis");
    printf("nombre: %s", reg.nombre);

    return 0;
}