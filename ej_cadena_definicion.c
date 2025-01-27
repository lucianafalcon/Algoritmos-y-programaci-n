
#include <stdio.h>
#include <stdbool.h>

int main(){
    char clave[5]="1234";
    int i=0;
    bool validacion = true;

    while(clave[i] != '\0' && validacion){
        if(clave[i] < '0' ||  clave[i] > '9'){
            printf("validacion incorr");
            validacion = false;
        }else{
              printf("validacion correcta");
        }

        i++;
    }

    return 0;
}
