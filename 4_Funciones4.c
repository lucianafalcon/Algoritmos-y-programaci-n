/*guia 4_ej4
4. Escribir un programa que solicite el ingreso de dos números, y luego informe los
números primos que hay entre esos dos números.
Se debe validar que los números ingresados sean enteros y además que el primer
número sea menor o igual que el segundo.*/

#include <stdio.h>
#include <stdbool.h>

void validar(int *num){
    bool espositivo = false;

    while (espositivo == false){
        if(*num <0){
        printf("error, ingrese numero positivo.");
        scanf("%d", num);
        }else{
            espositivo = true;
        }
    }

}

void es_primo(){
    int num1, num2= -1,i, j;
    bool es_primo = true;

    printf("Ingrese 1er numero: ");
    scanf("%d", &num1);
    validar(&num1);

    while(num1 >num2){
        printf("Ingrese  numero mayor al primero.");
        scanf("%d", &num2);
    }

    printf("los primos entre %d y %d son: ", num1, num2);
    for(i=num1+1; i<num2; i++){     //4 y 11 -> 5,7,8
        es_primo = true;
        for(j=2;j<=i/2;j++){
            if(i%j == 0){
                es_primo = false;
            }
        }
        if(es_primo == true){
            printf("%d ", i);
        }
    }
}

int main(){
    int num1;
    int num2;

    es_primo(num1, num2);

    return 0;
}