#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define CRESCENTE 1
#define DECRESCENTE 0

typedef struct{
    double *real, *imaginario;
    int size, exist;
} Conjunto;

int testaCriado(Conjunto C1);

int criaConjunto(Conjunto * C);

int conjuntoVazio(Conjunto C);

int insereElementoConjunto(double x, double y, Conjunto * C);

void mostraConjunto(Conjunto C, int ordem);

void selectionSort(double array[], double array2[], int n);

void swap(double *a, double *b);

int excluirElementoConjunto(double x, double y, Conjunto * C);

int tamanhoConjunto(Conjunto C);

int pertenceConjunto(double x, double y, Conjunto C);

int conjuntosIdenticos(Conjunto C1,Conjunto C2);

int subconjunto(Conjunto C1, Conjunto C2);

Conjunto complemento(Conjunto C1, Conjunto C2);

Conjunto diferenca(Conjunto C1, Conjunto C2);

Conjunto interseccao(Conjunto C1, Conjunto C2);

Conjunto uniao(Conjunto C1, Conjunto C2);

int copiarConjunto(Conjunto * C1, Conjunto * C2);

int destroiConjunto(Conjunto * C);