#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char * texto;
    int size;
} Texto;

Texto * criarTexto (char * t);

void liberarTexto (Texto * t);

unsigned int tamanhoTexto (Texto * t);

char * obterTexto (Texto * t);

void mostrarTexto (Texto *t, unsigned int colunas);

Texto * copiarTexto (Texto * t);

void substituirTexto (Texto * t, char * alteracao);

Texto * concatenarTextos (Texto * t1, Texto * t2);

char * obterSubtexto (Texto * t, unsigned int inicio, unsigned int tamanho);

unsigned int encontrarSubtexto (Texto * t, char * subtexto, unsigned int ocorrencia);

int compararTextos (Texto * t1, Texto * t2);