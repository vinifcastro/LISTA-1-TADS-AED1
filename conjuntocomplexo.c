#include "conjuntocomplexo.h"

int main(){
    int z=1, x, i, n1, n2;
    Conjunto temp;
    double k, y;
    Conjunto * conjunto = NULL;
    conjunto = (Conjunto *) malloc(6*sizeof(Conjunto));
    temp.real = temp.imaginario = NULL;
    temp.size = temp.exist = 0;
    for(i=0;i<6;i++){
        conjunto[i].exist = 0;
        conjunto[i].size = 0;
        conjunto[i].imaginario = NULL;
        conjunto[i].real = NULL;
    }
    criaConjunto(&temp);
    while(z){
        system("CLS");
        printf("Digite 00 para finalizar o programa.\n");
        printf("Digite 01 para criar um conjunto dos numeros complexos.\n");
        printf("Digite 02 para verificar se um conjunto esta ou nao vazio.\n");
        printf("Digite 03 para inserir um numero a um conjunto.\n");
        printf("Digite 04 para excluir um elemento de um conjunto.\n");
        printf("Digite 05 para saber a cardinalidade de um conjunto.\n");
        printf("Digite 06 para saber se um elemento pertence a um conjunto.\n");
        printf("Digite 07 para comparar se dois conjuntos sao iguais.\n");
        printf("Digite 08 para saber se um conjunto e subconjunto de outro.\n");
        printf("Digite 09 para gerar o conjunto complemento entre 2 conjuntos.\n");
        printf("Digite 10 para gerar o conjunto uniao entre 2 conjuntos.\n");
        printf("Digite 11 para gerar o conjunto interseccao entre 2 conjuntos.\n");
        printf("Digite 12 para gerar o conjunto diferenca entre 2 conjuntos.\n");
        printf("Digite 13 mostrar os elementos de um conjunto!\n");
        printf("Digite 14 para copiar um conjunto para outro.\n");
        printf("Digite 15 para destruir um conjunto.\n");
        printf("Digite 16 para testar se um conjunto esta criado!\n");
        scanf("%d%*c", &x);
        switch(x){
            case 0:
                system("CLS");
                printf("Finalizando Programa...\n");
                z=0;
            break;
            case 1:
                printf("Qual conjunto de usuario deseja criar? (1 ou 2):\n");
                scanf("%d%*c", &n1);
                if(n1!=1 && n1!=2){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 1) {
                    printf("O conjunto ja foi criado anteriormente.\n");
                    break;
                }
                if(criaConjunto(&conjunto[n1-1]) == 1) printf("Conjunto %d criado com sucesso!\n", n1);
                else printf("Houve um problema ao criar o conjunto %d!\n", n1);
            break;
            case 2:
                printf("Qual conjunto deseja verificar se esta vazio?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(conjuntoVazio(conjunto[n1-1]) == 1) printf("Conjunto %d esta vazio!\n", n1);
                else printf("O conjunto %d nao esta vazio!\n", n1);
            break;
            case 3:
                printf("Qual conjunto deseja adicionar um elemento? (1 ou 2):\n");
                scanf("%d%*c", &n1);
                printf("Qual a parte real do numero complexo?\n");
                scanf("%lf%*c", &k);
                printf("Qual a parte imaginaria do numero complexo?\n");
                scanf("%lf%*c", &y);
                 if(n1!=1 && n1!=2){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(insereElementoConjunto(k, y, &conjunto[n1-1]) == 1) printf("Sucesso ao inserir o numero ao conjunto %d.\n", n1);
                else printf("Falha ao inserir o numero ao conjunto %d.\n", n1);
                selectionSort(conjunto[n1-1].real, conjunto[n1-1].imaginario, conjunto[n1-1].size);
            break;
            case 4:
                printf("Qual conjunto deseja excluir um elemento? (1 ou 2):\n");
                scanf("%d%*c", &n1);
                printf("Qual a parte real do elemento que deseja excluir?\n");
                scanf("%lf%*c", &k);
                printf("Qual a parte imaginaria do elemento que deseja excluir?\n");
                scanf("%lf%*c", &y);
                if(n1!=1 && n1!=2){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(excluirElementoConjunto(k, y, &conjunto[n1-1]) == 1) printf("Sucesso ao excluir o elemento do conjunto %d.\n", n1);
                else printf("Falha ao excluir o elemento do conjunto %d.\n", n1);
                selectionSort(conjunto[n1-1].real, conjunto[n1-1].imaginario, conjunto[n1-1].size);
            break;
            case 5:
                printf("Qual conjunto deseja saber a cardinalidade?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                printf("A cardinalidade do conjunto %d e de %d elementos.\n", n1, tamanhoConjunto(conjunto[n1-1]));
            break;
            case 6:
                printf("Qual conjunto deseja verificar se existe um elemento? (1 ou 2):\n");
                scanf("%d%*c", &n1);
                printf("Qual a parte real do numero complexo a ser procurado?\n");
                scanf("%lf%*c", &k);
                printf("Qual a parte imaginaria do numero complexo a ser procurado?\n");
                scanf("%lf%*c", &y);
                if(n1!=1 && n1!=2){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(pertenceConjunto(k, y, conjunto[n1-1]) == 1) printf("O elemento inserido pertence ao conjunto %d!\n", n1);
                else printf("O elemento inserido nao pertence ao conjunto %d!\n", n1);
            break;
            case 7:
                printf("Qual conjunto deseja comparar a igualdade? (1 , 2, 3, 4 ,5 e 6):\n");
                scanf("%d%*c", &n1);
                printf("Com qual? (1 , 2, 3, 4 ,5 e 6):\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(conjuntosIdenticos(conjunto[n1-1],conjunto[n2-1]) == 1) printf("O conjunto %d e igual ao conjunto %d.\n", n1, n2);
                else printf("O conjunto %d nao e igual ao conjunto %d.\n", n1, n2);
            break;
            case 8:
                printf("Qual conjunto deseja saber se e subconjunto de outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("De qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(subconjunto(conjunto[n1-1],conjunto[n2-1]) == 1) printf("O conjunto %d e subconjunto do conjunto %d.\n", n1, n2);
                else printf("O conjunto %d nao e subconjunto do conjunto %d.\n", n1, n2);
            break;
            case 9:
                printf("Qual conjunto deseja gerar o complemento em relacao a outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("A qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(testaCriado(conjunto[2]) == 0) criaConjunto(&conjunto[2]);
                temp = complemento(conjunto[n1-1], conjunto[n2-1]);
                conjunto[2].real = NULL;
                conjunto[2].imaginario = NULL;
                conjunto[2] = temp;
                printf("Conjunto complemento criado com sucesso!\n");
            break;
            case 10:
                printf("Qual conjunto deseja gerar a uniao em relacao a outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("A qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(testaCriado(conjunto[3]) == 0) criaConjunto(&conjunto[3]);
                temp = uniao(conjunto[n1-1], conjunto[n2-1]);
                conjunto[3].real = NULL;
                conjunto[3].imaginario = NULL;              
                conjunto[3] = temp;
                printf("Conjunto uniao criado com sucesso!\n");
            break;
            case 11:
                printf("Qual conjunto deseja gerar a interseccao em relacao a outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("A qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(testaCriado(conjunto[4]) == 0) criaConjunto(&conjunto[4]);
                temp = interseccao(conjunto[n1-1], conjunto[n2-1]);
                conjunto[4].real = NULL;
                conjunto[4].imaginario = NULL;              
                conjunto[4] = temp;
                printf("Conjunto interseccao criado com sucesso!\n");
            break;
            case 12:
                printf("Qual conjunto deseja gerar a diferenca em relacao a outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("A qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(testaCriado(conjunto[5]) == 0) criaConjunto(&conjunto[5]);
                temp = diferenca(conjunto[n1-1], conjunto[n2-1]);
                conjunto[5].real = NULL;
                conjunto[5].imaginario = NULL;              
                conjunto[5] = temp;
                printf("Conjunto diferenca criado com sucesso!\n");
            break;
            case 13:
                printf("Qual conjunto deseja imprimir?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("Qual ordem voce deseja vizualizar o conjunto?\n0 - Decrescente\n1 - Crescente\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 0) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                selectionSort(conjunto[n1-1].real, conjunto[n1-1].imaginario, conjunto[n1-1].size);
                mostraConjunto(conjunto[n1-1], n2);
            break;
            case 14:
                printf("Qual conjunto deseja copiar para outro?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                printf("Para qual?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n2);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6 && n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5 && n2!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                conjunto[n2-1].real = NULL;
                conjunto[n2-1].imaginario = NULL;
                if(copiarConjunto(&conjunto[n1-1], &conjunto[n2-1]) == 1) printf("Copia do conjunto %d para o conjunto %d, realizada com sucesso.\n", n1, n2);
                else printf("Nao foi possivel copiar o conjunto %d para o conjunto %d.\n", n1, n2);
            break;
            case 15:
                printf("Qual conjunto deseja destruir?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if( (testaCriado(conjunto[n1-1]) == 0) || (testaCriado(conjunto[n2-1]) == 0)) {
                    printf("O conjunto nao foi criado.\n");
                    break;
                }
                if(destroiConjunto(&conjunto[n1-1]) == 1) printf("Conjunto %d destruido com sucesso!\n", n1);
                else printf("Nao foi possivel destrui conjunto %d.\n", n1);
            break;
            case 16:
                printf("Qual conjunto deseja testar?\n[ 1, 2, 3 (Conj. Complemento), 4 (Conj. Uniao), 5 (Conj. Interssecao), 6 (Conj. Diferenca) ]:\n");
                scanf("%d%*c", &n1);
                if(n1!=1 && n1!=2 && n1!=3 && n1!=4 && n1!=5 && n1!=6){
                    printf("Numero do conjunto digitado invalido!\n");
                    break;
                }
                if(testaCriado(conjunto[n1-1]) == 1) printf("O conjunto esta criado!\n");
                else printf("O conjunto nao esta criado!\n");
            break;
            default:
                printf("Comando Digitado e Invalido!\n");
            break;
        }
        system("PAUSE");
    }
    free(temp.real);
    free(temp.imaginario);
    for(i=0;i<6;i++){
        free(conjunto[i].imaginario);
        free(conjunto[i].real);
    }
    free(conjunto);
}

int testaCriado(Conjunto C1){
    if (C1.exist == 0) return 0;
    else return 1;
}

int criaConjunto(Conjunto * C){
    if (C->exist == 1) return 0;
    C->exist=1;
    return 1;
}

int conjuntoVazio(Conjunto C){
    if(C.size == 0) return 1;
    else return 0;
}

int insereElementoConjunto(double x, double y, Conjunto * C){
    int size, i, k=0;
    for(i=0;i<C->size;i++){
        if((x == C->real[i]) && (y == C->imaginario[i]))
            k=1;
    }
    if(k==1) return 0;
    if(C->size == 0){
        C->size++;
        size = C->size;
        C->real = (double *) malloc(sizeof(double));
        C->imaginario = (double *) malloc(sizeof(double));
        C->real[(size-1)] = x;
        C->imaginario[(size-1)] = y;
    }
    else{
        C->size++;
        size = C->size;
        C->real = (double *) realloc(C->real,size*sizeof(double));
        C->imaginario = (double *) realloc(C->imaginario,size*sizeof(double));
        C->real[(size-1)] = x;
        C->imaginario[(size-1)] = y;
    }
    if ( (C->real[size-1] == x) && (C->imaginario[size-1] == y) ) return 1;
    else return 0;
}

void swap(double *a, double *b){ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
}

void selectionSort(double array[], double array2[], int n){ 
    int i, j, min_element; 
    for (i = 0; i < n-1; i++){
        min_element = i; 
        for (j = i+1; j < n; j++) 
            if (array[j] < array[min_element]) 
                min_element = j; 
        swap(&array[min_element], &array[i]);
        swap(&array2[min_element], &array2[i]);
    }
    for (i = 0; i < n-1; i++){
        min_element = i; 
        for (j = i+1; j < n; j++) 
            if (array[j] == array[min_element]) 
                if(array2[j]<array2[min_element])
                    min_element = j;
        swap(&array2[min_element], &array2[i]);
    }
}

void mostraConjunto(Conjunto C, int ordem){
    int i;
    printf("{ ");
    if (ordem == CRESCENTE){
        for(i=0;i<C.size; i++){
            if(i==0){
                if(C.imaginario[i]>0){
                    if(C.real[i]!=0) printf(" %.2lf", C.real[i]);
                    if(C.imaginario[i]!=0) printf("+%.2lfi", C.imaginario[i]);
                }
                else{
                    if(C.real[i]!=0) printf(" %.2lf", C.real[i]);
                    if(C.imaginario[i]!=0) printf("%.2lfi", C.imaginario[i]);
                }
            }
            else{
                if(C.imaginario[i]<0){
                    if(C.real[i]!=0) printf(", %.2lf", C.real[i]);
                    if(C.real[i]==0) printf(", ", C.real[i]);
                    if(C.imaginario[i]!=0) printf("%.2lfi", C.imaginario[i]);
                }
                else{
                    if(C.real[i]!=0) printf(", %.2lf", C.real[i]);
                    if(C.real[i]==0) printf(", ", C.real[i]);
                    if(C.imaginario[i]!=0) printf("+%.2lfi", C.imaginario[i]);
                }
            }
        }
    }
    else{
        for(i=(C.size-1);i>=0; i--){
            if(i==(C.size-1)){
                if(C.imaginario[i]>0){
                    if(C.real[i]!=0) printf(" %.2lf", C.real[i]);
                    if(C.imaginario[i]!=0) printf("+%.2lfi", C.imaginario[i]);
                }
                else{
                    if(C.real[i]!=0) printf(" %.2lf", C.real[i]);
                    if(C.imaginario[i]!=0) printf("%.2lfi", C.imaginario[i]);
                }
            }
            else{
                if(C.imaginario[i]<0){
                    if(C.real[i]!=0) printf(", %.2lf", C.real[i]);
                    if(C.real[i]==0) printf(", ", C.real[i]);
                    if(C.imaginario[i]!=0) printf("%.2lfi", C.imaginario[i]);
                }
                else{
                    if(C.real[i]!=0) printf(", %.2lf", C.real[i]);
                    if(C.real[i]==0) printf(", ", C.real[i]);
                    if(C.imaginario[i]!=0) printf("+%.2lfi", C.imaginario[i]);
                }
            }
        }
    }
    printf(" }\n");
    return;
}

int excluirElementoConjunto(double x, double y, Conjunto * C){
    int i, k=0;
    for(i=0;i<C->size;i++){
        if((x == C->real[i]) && (y == C->imaginario[i])){
            swap(&C->real[i], &C->real[i+1]);
            swap(&C->imaginario[i], &C->imaginario[i+1]);
            k=1;
        }
    }
    C->size--;
    if(C->size!=0){
        C->real = (double*) realloc(C->real, C->size*sizeof(double));
        C->imaginario = (double*) realloc(C->imaginario, C->size*sizeof(double));
    }
    else{
        C->real = (double*) realloc(C->real, sizeof(double));
        C->imaginario = (double*) realloc(C->imaginario, sizeof(double));
    }
    if(k==0) return 0;
    return 1;
}

int tamanhoConjunto(Conjunto C){
    return C.size;
}

int pertenceConjunto(double x, double y, Conjunto C){
    int i, k=0;
    for(i=0;i<C.size;i++){
        if((x == C.real[i]) && (y == C.imaginario[i])){
            k=1;
        }
    }
    if (k == 0) return 0;
    else return 1;
}

int conjuntosIdenticos(Conjunto C1,Conjunto C2){
    int k=0, i;
    if(C1.size != C2.size) return 0;
    for(i=0;i<C1.size;i++){
        if( (C1.real[i] == C2.real[i]) && (C1.imaginario[i] == C2.imaginario[i]) )
            k++;
    }
    if(C1.size == k) return 1;
    else return 0;
}

int subconjunto(Conjunto C1, Conjunto C2){
    int k=0, i, j;
    if(C1.size > C2.size) return 0;
    for(i=0;i<C1.size;i++){
        for(j=0;j<C2.size;j++)
            if( (C1.real[i] == C2.real[j]) && (C1.imaginario[i] == C2.imaginario[j]) )
                k++;
    }
    if(C1.size == k) return 1;
    else return 0;
}

Conjunto complemento(Conjunto C1, Conjunto C2){
    Conjunto x;
    int size=0, i, k, j, z=0;
    x.real = x.imaginario = NULL;
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==0){
            size++;
        }
    }
    x.real = (double *) malloc(size*sizeof(double));
    x.imaginario = (double *) malloc(size*sizeof(double));
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==0){
            x.real[z] = C2.real[i];
            x.imaginario[z] = C2.imaginario[i];
            z++;
        }
    }
    x.size = size;
    return x;
}

Conjunto diferenca(Conjunto C1, Conjunto C2){
    Conjunto x;
    x = complemento(C2, C1);
    return x;
}

Conjunto interseccao(Conjunto C1, Conjunto C2){
    Conjunto x;
    int size=0, i, k, j, z=0;
    x.real = x.imaginario = NULL;
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==1){
            size++;
        }
    }
    x.real = (double *) malloc(size*sizeof(double));
    x.imaginario = (double *) malloc(size*sizeof(double));
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==1){
            x.real[z] = C2.real[i];
            x.imaginario[z] = C2.imaginario[i];
            z++;
        }
    }
    x.size = size;
    return x;
}

Conjunto uniao(Conjunto C1, Conjunto C2){
    Conjunto x;
    int size=0, i, j, k, z=0;
    size = C1.size + C2.size;
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==1){
            size--;
        }
    }
    x.size = size;
    x.real = (double *) malloc(size*sizeof(double));
    x.imaginario = (double *) malloc(size*sizeof(double));
    for(i=0; i<C2.size; i++){
        k=0;
        for(j=0; j<C1.size; j++){
            if( (C1.real[j] == C2.real[i]) && (C1.imaginario[j] == C2.imaginario[i]) )
                k=1;
        }
        if(k==0){
            x.real[z] = C2.real[i];
            x.imaginario[z] = C2.imaginario[i];
            z++;
        }
    }
    for(i=0; i<C1.size; i++){
        x.real[z] = C1.real[i];
        x.imaginario[z] = C1.imaginario[i];
        z++;
    }
    return x;
}

int copiarConjunto(Conjunto * C1, Conjunto * C2){
    int x = 0, i;
    C2->size = C1->size;
    C2->real = (double *) malloc(C1->size*sizeof(double));
    C2->imaginario = (double *) malloc(C1->size*sizeof(double));
    *C2 = *C1;
    for(i=0; i<(C1->size); i++){
        if( (C1->real[i] == C2->real[i]) && (C2->imaginario[i] == C1->imaginario[i]) )
            x++;
    }
    return (x == C1->size);
}

int destroiConjunto(Conjunto * C){
    C->exist = 0;
    C->size = 0;
    C->imaginario = NULL;
    C->real = NULL;
    if (C->exist == 0) return 1;
    else return 0;
}