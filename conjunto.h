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
} conjuntos;

int criaConjunto(conjuntos * C);

int conjuntoVazio(conjuntos * C);

int insereElementoConjunto(int x, conjuntos * C);

int excluirElementoConjunto(int x,conjuntos * C);

int tamanhoConjunto(conjuntos * C);

int maior(int x, conjuntos * C);

int menor(int x, conjuntos * C);

int pertenceConjunto(int x, conjuntos * C);

int conjuntosIdenticos(conjuntos * C1, conjuntos * C2);

int subconjunto(conjuntos * C1, conjuntos * C2);

void complemento(conjuntos C1, conjuntos C2);

void swap(int *a, int *b);

void selectionSort(int array[], int n);

void uniao(conjuntos C1, conjuntos C2);

void intersec(conjuntos C1, conjuntos C2);

void printpowerset(int *set, int set_size);

void printconj(conjuntos * C, int ordem);

void copy(conjuntos * C1, conjuntos * C2);

void destroiconj(conjuntos * C);

int testeexistconj(conjuntos * C);