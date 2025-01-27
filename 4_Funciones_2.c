/******************************************************************************
2. Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo; de lo contrario,
se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.
*******************************************************************************/
 
#include <stdio.h>
#include <stdbool.h>

//esta funcion se fija si es capicua o no
bool capicua(int x){  
    bool escapicua = false;
    int resto;
    int inversion = 0;
    int divisor;
    int otro=x;
    
    while(x > 0){
        resto = x % 10;
        inversion = inversion*10 + resto;
        x = x / 10;
    }
    
    if (inversion == otro){
        escapicua = true;
    }
    return escapicua; 
}

int main()
{
    int x = 1;
    bool z;
    
    while(x != 0){
        printf("Ingrese numero, termina con 0:");
        scanf("%d",&x);
        
        z = capicua(x);

        //informa en pantalla si es capicua o no
        if (z == true){
            printf("El numero ingresado %d : es capicua\n",x);
        }else{
            printf("El numero ingresado %d : no es capicua\n",x);
        }
    }
    return 0;
}
