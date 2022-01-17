#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

#define CRESCENTE 1

#define DECRESCENTE 0

typedef struct{
    int x[10000];
    int size;
    int exist;
} conjunto;

int criaConjunto(conjunto * C);

int conjuntoVazio(conjunto * C);

int insereElementoConjunto(int x, conjunto * C);

int excluirElementoConjunto(int x,conjunto * C);

int tamanhoConjunto(conjunto * C);

int maior(int x, conjunto * C);

int menor(int x, conjunto * C);

int pertenceConjunto(int x, conjunto * C);

int conjuntoIdenticos(conjunto * C1, conjunto * C2);

int subconjunto(conjunto * C1, conjunto * C2);

conjunto complemento(conjunto C1, conjunto C2);

void swap(int *a, int *b);

void selectionSort(int array[], int n);

conjunto uniao(conjunto C1, conjunto C2);

conjunto intersec(conjunto C1, conjunto C2);

conjunto diferenca(conjunto C1, conjunto C2);

void printpowerset(int *set, int set_size);

void mostraConjunto(conjunto C, int ordem);

void copy(conjunto * C1, conjunto * C2);

void destroiconj(conjunto * C);

int testeexistconj(conjunto * C);