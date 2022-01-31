#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

int diasMeses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char diasSemana[7][20]={ "Domingo", "Segunda-Feira","Terca-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira","Sabado" };

typedef struct {
    unsigned int d[3];
}Data;

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano);

unsigned int bissextoData (Data d);

Data * copiaData (Data d);

void liberaData (Data * d);

Data * somaDiasData (Data d, unsigned int dias);

Data * subtrairDiasData (Data d, unsigned int dias);

void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano);

unsigned int obtemDiaData (Data d);

unsigned int obtemMesData (Data d);

unsigned int obtemAnoData (Data d);

int comparaData (Data d1, Data d2);

unsigned int numeroDiasDatas (Data d1, Data d2);

unsigned int numeroMesesDatas (Data d1, Data d2);

unsigned int numeroAnosDatas (Data d1, Data d2);

unsigned int obtemDiaSemanaData (Data d);

char * imprimeData (Data d, char * formato);