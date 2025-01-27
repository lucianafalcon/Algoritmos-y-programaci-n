/*guia 6 - ej 8
8. Escribir una función en C, que reciba una cadena que representa una palabra o
una frase y devuelva si la misma es o no un palíndromo.
Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- amar a roma (Es palíndromo)
- ana lava lana (Es palíndromo)
- a ti no, bonita (Es palíndromo)
- algoritmos y programas (No es palíndromo)
- lenguaje C (No es palíndromo)
Evitar realizar ciclos innecesarios.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool frasepalindromo(char frase[]){
    bool espalindromo = true;
    int i,j;

    i=0;
    j=strlen(frase)-1;
    while( i<=j && espalindromo){

        if( (frase[i] <'a' && frase[i]>'z') || (frase[i] <'A' && frase[i]>'Z') ){ 
            i++;
        }
        if( (frase[j] <'a' && frase[j]>'z') || (frase[j] <'A' && frase[j]>'Z') ){
            j--;
        }
               
        if(frase[i] == frase[j]){
            i++;
            j--;
        }else{
            espalindromo = false;
            i++;
        }

    }

return espalindromo;

}

int main(){

    char frase[100]= "anilina";
    bool x;

    x = frasepalindromo(frase); // Es palíndromo
    if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo \n", frase );
    }

    strcpy(frase, "ojo"); // Es palindromo
      x = frasepalindromo(frase);
    if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    strcpy(frase, "radar");  // Es palindromo
    x = frasepalindromo(frase);  
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    strcpy(frase, "reconocer");   //Es palindromo
    x = frasepalindromo(frase); 
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    strcpy(frase, "amor a roma");   // Es palíndromo
    x = frasepalindromo(frase);  
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }



    strcpy(frase, "ana lava lana");   // Es palíndromo
    x = frasepalindromo(frase);  
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }



    strcpy(frase, "a ni no, bonita");   // Es palíndromo
    x = frasepalindromo(frase);  
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }


    strcpy(frase, "radar");   // Es palindromo
    x = frasepalindromo(frase);  
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    strcpy(frase, "algoritmos y programas");    // No es palíndromo
    x = frasepalindromo(frase); 
      if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    strcpy(frase, "lenguaje C");   // No es palíndromo
    x = frasepalindromo(frase);
    if(x){
        printf("la frase: %s - es palindromo\n", frase) ;
    }else{
         printf("la frase: %s - NO es palindromo\n", frase );
    }

    return 0;
}