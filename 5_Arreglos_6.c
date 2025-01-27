/*
6) Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
y el segundo ordenado descendente, crear un nuevo vector c de n + m
elementos intercalando los elementos de a y b de modo que c quede ordenado
ascendente.*/

#include <stdio.h>

#define MAX 50

typedef int Tvector[MAX];

void nuevovector(Tvector v1, Tvector v2, int n,int m){
    int vc[9];
    int i=0, j=m-1, k;
    int menor;
    k=0;
    while(j>=0 && i<n){
        //for(k=0; k<9 && j>=0 && i<n; k++){
            if(v1[i]<v2[j]){
                menor=v1[i];
                vc[k]=menor;
                i++;
            }else if(v1[i]>v2[j]){
                menor=v2[j];
                vc[k]=menor;
                j--;
            }else if(v1[i]==v2[j]){
                menor=v1[i];
                vc[k]=menor;
                i++;
            }
            k++;
    }
    
    while(i<n){
        vc[k]=v1[i];
        i++;
        k++;
    }

    while(j>=0){
        vc[k]=v2[j];
        j--;
        k++;
    }

    
    printf("vector ordenado ascendentemente es:\n");
    for(k=0; k<(n+m); k++){
         printf("%d, ", vc[k]);
    }
}


int main(){

    Tvector v1={1,2,4,6,7};  // -7, 1, 2, 3, 4, 6, 7, 7, 9
    Tvector v2={9,7,3,-7};

    
    int n=5;
    int m=4;
    
    nuevovector(v1, v2, n, m);

    return 0;
}