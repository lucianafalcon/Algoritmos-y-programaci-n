/*
12) Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de
un mes, ordenada cronológicamente. Se pide: a) Ingresar el número de mes
para conocer la cantidad de días registrados. b) Cargar el listado en una matriz
e informarla en forma bidimensional. c) Informar además la máxima y la mínima
temperatura por día, la máxima y la mínima temperatura del mes.*/



#include <stdio.h>
#define MAXDIA 4
#define MAXHORA 4

typedef int Tvector[MAXDIA];
typedef Tvector Tmatriz[MAXHORA]; 

void matriz_temperaturas(int dias_mes, Tmatriz matriz){
    int i,j;

    i=0;
    while(i<dias_mes){
        for(j=0; j<MAXHORA; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
        i++;
    }

}

int dias_mes_buscador(int numero, Tmatriz matrizx){
    int dias_mes;
    int vec[4] = {1,2,3,4}

    if(numero == 1 || numero == 3 || numero == 5 || numero == 7 ||
            numero == 8 || numero == 10 || numero ==12){
        dias_mes = 3;
        //matrizx = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    }else if(numero == 2){
        dias_mes = 2;
        //matrizx = {{1,2,3,4},{5,6,7,8}};

    }else{
        dias_mes = 4;
        //matrizx = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    }

    return dias_mes;
}

int main(){
    int numero = 2;
    int dias_mes;
    Tmatriz matriz;

    printf("ingrese numero de mes: ");
    scanf("%d", &numero);
    dias_mes = dias_mes_buscador(numero, matriz);
    printf("dias del mes son: %d", dias_mes);

 //   matriz_temperaturas(dias_mes, matriz);

    return 0;
}