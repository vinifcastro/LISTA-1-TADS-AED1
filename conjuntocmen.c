#include "conjunto.h"

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}  

void selectionSort(int array[], int n){ 
    int i, j, min_element; 
    for (i = 0; i < n-1; i++){
        min_element = i; 
        for (j = i+1; j < n; j++) 
            if (array[j] < array[min_element]) 
        min_element = j; 
        swap(&array[min_element], &array[i]); 
    } 
}

int criaConjunto(conjunto * C){
    (C->exist) = 1;
    if ((C->exist) == 1) return 1;
    else return 0;
}

int conjuntoVazio(conjunto * C){
    if(C->exist == 0)
        return 0;
    if ((C->size) == 0) return 0;
    else return 1;
}

int insereElementoConjunto(int x, conjunto * C){
    int i, k = 0;
    if(C->exist == 0) 
        return 0;
    C->size++;
    for (i=0 ; i<(C->size) ; i++){
        if (C->x[i] == x) k=1;
    }
    if (k==1){
        C->size--;
        return 0;
    }
    else{
        C->x[(C->size)-1] = x;
        return 1;
    }
}

int excluirElementoConjunto(int x,conjunto * C){
    int i, k=0, u;
    if(C->exist == 0)
        return 0;
    for (i=0 ; i<(C->size) ; i++){
        if (C->x[i] == x){ 
            k=1;
            u=i;
        }
    }
    if (k==0) return 0;
    else{
        C->size--;
        for (i=u ; i<(C->size) ; i++){
            C->x[i] = C->x[i+1];
        }
        return 1;
    }
}

int tamanhoConjunto(conjunto * C){
    if(C->exist == 0)
        return 0;
    return C->size;
}

int maior(int x, conjunto * C){
    int i, cont=-1;
    if(C->exist == 0)
        return -1;
    for (i=0 ; i<(C->size) ; i++){
        if (C->x[i] > x) {
            if (cont==-1) cont++;
            cont++;
        }
    }
    if (cont == C->size) return 0;
    if (cont > 0) return cont;
    else return -1;
}

int menor(int x, conjunto * C){
    int i, cont=-1;
    if(C->exist == 0)
        return -1;
    for (i=0 ; i<(C->size) ; i++){
        if (C->x[i] < x) {
            if (cont==-1) cont++;
            cont++;
        }
    }
    if (cont == C->size) return 0;
    if (cont > 0) return cont;
    else return -1;
}

int pertenceConjunto(int x, conjunto * C){
    int i;
    if(C->exist == 0)
        return 0;
    for (i=0 ; i<(C->size) ; i++){
        if (C->x[i] == x) return 1;
    }
    return 0;
}

int conjuntoIdenticos(conjunto * C1, conjunto * C2){
    int i, k=0;
    if(C1->exist == 0)
        return 0;
    if(C1->exist == 0)
        return 0;
    if (C1->size != C2->size) return 0;
    for (i=0 ; i<(C1->size) ; i++){
        if (C1->x[i] == C2->x[i]) k++;
    }
    if (k==C1->size) return 1;
    else return 0;
}

int subconjunto(conjunto * C1, conjunto * C2){
    int cont=0 , i, j;
    for(i=0 ; i<(C1->size) ; i++){
        for(j=0 ; j<(C2->size) ; j++){
            if (C1->x[i] == C2->x[j]) cont++;
        }
    }
    if (cont == C1->size) return 1;
    else return 0;
}

conjunto complemento(conjunto C1, conjunto C2){
    conjunto x;
    int i, j, k, cont=0, z;
    x.exist = 1;
    if (C1.size > C2.size) x.size = C1.size;
    else x.size = C2.size;
    for (i=0 ; i<(C2.size) ; i++){
        k=0;
        for(j=0 ; j<(C1.size) ; j++){
            if (C2.x[i] == C1.x[j]) k=1;
        }
        if (k==0){
            x.x[i] = C2.x[i];
        }
        else x.x[i] = -1;
    }
    z = i;
    for (i=z ; i<x.size ; i++) x.x[i] = -1;
    selectionSort(x.x, x.size);
    return x;
}

conjunto uniao(conjunto C1, conjunto C2){
    conjunto x;
    int i, j, k, cont=0, z;
    x.exist = 1;
    x.size = C1.size+C2.size;
    for (i=0 ; i<x.size ; i++) x.x[i] = -1;
    for (i=0 ; i<C1.size ; i++){
        x.x[i] = C1.x[i];
    }
    z=i;
    for(i=0 ; i<C2.size ; i++){
        k=0;
        for (j=0 ; j<x.size ; j++){
            if (C2.x[i] == x.x[j]) k=1;
        }
        if (k==0){
            x.x[z] = C2.x[i];
            z++;
        }
        else continue;
    }
    for (i=z ; i<x.size ; i++) x.x[i] = -1;
    selectionSort(x.x, x.size);
    return x;
}

conjunto interseccao(conjunto C1, conjunto C2){
    conjunto x;
    int i, j, k, cont=0, z;
    x.exist = 1;
    if (C1.size > C2.size) x.size = C1.size;
    else x.size = C2.size;
    for (i=0 ; i<(C2.size) ; i++){
        k=1;
        for(j=0 ; j<(C1.size) ; j++){
            if (C2.x[i] == C1.x[j]) k=0;
        }
        if (k==0){
            x.x[i] = C2.x[i];
        }
        else x.x[i] = -1;
    }
    z = i;
    for (i=z ; i<x.size ; i++) x.x[i] = -1;
    selectionSort(x.x, x.size);
    return x;
}

conjunto diferenca(conjunto C1, conjunto C2){
    return complemento(C1,C2);
}

void printpowerset(int *set, int set_size){
    int x = pow(2, set_size);
    int counter, j, init = 0;

    for(counter = 0; counter < x; counter++){
        printf("[");
        init = 0;
        for(j = 0; j < set_size; j++){
            if(counter & (1<<j)){
                if (init == 0) {
                    printf(" %d", set[j]);
                    init=1;
                }
            else printf(", %d", set[j]);
          }
        }
       printf(" ]\n");
    }
}

void mostraConjunto(conjunto C, int ordem){
    int x, y, i, init = 0, z;
    selectionSort(C.x, C.size);
    if (ordem == CRESCENTE){
        x=0;
        y= C.size-1;
    }
    else{
        y=0;
        x= (C.size-1)*(-1);
    }
    printf("{ ");
    for(i=x; i<=y; i++){
        if (x<0) z = i*-1;
        else z = i;
        if (init == 0){
            if(C.x[z] != -1){
                printf ("%d", C.x[z]);
                init = 1;
            }
        }
        else {
            if(C.x[z]!=-1) printf (", %d", C.x[z]);
        }
    }
    printf(" }\n");
}

void copy(conjunto * C1, conjunto * C2){
    int i;
    C2->size = C1->size;
    C2->exist = C1->exist;
    for(i=0 ; i<(C1->size) ; i++){
        C2->x[i] = C1->x[i];
    }
}

void destroiconj(conjunto * C){
    C->size = 0;
    C->exist = 0;
}

int testeexistconj(conjunto * C){
    if (C->exist == 0) return 0;
    else return 1;
}

int main(){
    int x, finalize=1, n1, tof, n2;
    conjunto c1, c2, c3, c4, c5, c6, c7;
    c7.exist = c7.size = c6.exist = c6.size = c5.exist = c5.size = c4.exist = c4.size = c3.exist = c3.size = c2.exist = c2.size = c1.exist = c1.size = 0;
    while(finalize){
        system("CLS");
        printf("Digite 00 para finalizar.\n");
        printf("Digite 01 para criar um conjunto.\n");
        printf("Digite 02 para verifica se o conjunto e vazio.\n");
        printf("Digite 03 para adicionar um numero a um conjunto.\n");
        printf("Digite 04 para excluir um numero de um conjunto.\n");
        printf("Digite 05 para calcular a cardinalidade de um conjunto.\n");
        printf("Digite 06 para determinar quantos elementos do conjunto sao maiores que um numero.\n");
        printf("Digite 07 para determinar quantos elementos do conjunto sao menores que um numero.\n");
        printf("Digite 08 para verificar se um numero pertence a um conjunto.\n");
        printf("Digite 09 para comparar se dois conjunto sao iguais.\n");
        printf("Digite 10 para saber se um conjunto e subconjunto de outro.\n");
        printf("Digite 11 para gerar o conjunto complemento entre 2 conjunto.\n");
        printf("Digite 12 para para gerar a uniao entre 2 conjunto.\n");
        printf("Digite 13 para para gerar a interseccaoao entre 2 conjunto.\n");
        printf("Digite 14 para para gerar a diferenca entre 2 conjunto.\n");
        printf("Digite 15 para gerar o conjunto das partes de um conjunto.\n");
        printf("Digite 16 para mostrar um conjunto.\n");
        printf("Digite 17 para copiar um conjunto para o outro.\n");
        printf("Digite 18 para destruir um conjunto.\n"); 
        printf("Digite 19 para verificar se um conjunto existe.\n"); 
        scanf("%d%*c", &x);
        switch(x){
            case 0:
                system("CLS");
                printf("Finalizando programa...\n");
                system("PAUSE");
                finalize=0;
            break;
            case 1:
                printf("Deseja criar o conjunto 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = criaConjunto(&c1);
                        if (tof == 1) printf("Conjunto %d criado com sucesso!\n", n1);
                        else printf("Nao foi possivel criar o conjunto %d\n", n1);
                    break;
                    case 2:
                        tof = criaConjunto(&c2);
                        if (tof == 1) printf("Conjunto %d criado com sucesso!\n", n1);
                        else printf("Nao foi possivel criar o conjunto %d\n", n1);
                    break;
                    case 3:
                        tof = criaConjunto(&c3);
                        if (tof == 1) printf("Conjunto %d criado com sucesso!\n", n1);
                        else printf("Nao foi possivel criar o conjunto %d\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 2:
                printf("Qual conjunto voce deseja verificar se e vazio ou nao? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = conjuntoVazio(&c1);
                        if (tof == 1) printf("Conjunto %d nao e vazio!\n", n1);
                        else printf("Conjunto %d e vazio!\n", n1);
                    break;
                    case 2:
                        tof = conjuntoVazio(&c2);
                        if (tof == 1) printf("Conjunto %d nao e vazio!\n", n1);
                        else printf("Conjunto %d e vazio!\n", n1);
                    break;
                    case 3:
                        tof = conjuntoVazio(&c3);
                        if (tof == 1) printf("Conjunto %d nao e vazio!\n", n1);
                        else printf("Conjunto %d e vazio!\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 3:
                printf("Qual numero deseja adicionar? (1, 2 ou 3)\n");
                scanf("%d%*c", &n2);
                printf("Qual conjunto voce deseja que o numero seja adicionado? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = insereElementoConjunto(n2, &c1);
                        if (tof == 1) printf("Numero adicionado ao conjunto %d\n", n1);
                        else printf("Nao foi possivel adicionar o numero ao conjunto %d (Conjunto ja possui esse numero ou ele nao existe).\n", n1);
                    break;
                    case 2:
                        tof = insereElementoConjunto(n2, &c2);
                        if (tof == 1) printf("Numero adicionado ao conjunto %d\n", n1);
                        else printf("Nao foi possivel adicionar o numero ao conjunto %d (Conjunto ja possui esse numero ou ele nao existe).\n", n1);
                    break;
                    case 3:
                        tof = insereElementoConjunto(n2, &c3);
                        if (tof == 1) printf("Numero adicionado ao conjunto %d\n", n1);
                        else printf("Nao foi possivel adicionar o numero ao conjunto %d (Conjunto ja possui esse numero ou ele nao existe).\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 4:
                printf("Qual numero deseja excluir? (1, 2 ou 3)\n");
                scanf("%d%*c", &n2);
                printf("Qual conjunto voce deseja que o numero seja excluido? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = excluirElementoConjunto(n2,&c1);
                        if (tof == 1) printf("Numero excluido do conjunto %d.\n", n1);
                        else printf("Numero nao pertence ao conjunto %d ou o conjunto e vazio/nao existe!\n", n1);
                    break;
                    case 2:
                        tof = excluirElementoConjunto(n2,&c2);
                        if (tof == 1) printf("Numero excluido do conjunto %d.\n", n1);
                        else printf("Numero nao pertence ao conjunto %d ou o conjunto e vazio/nao existe!\n", n1);
                    break;
                    case 3:
                        tof = excluirElementoConjunto(n2,&c3);
                        if (tof == 1) printf("Numero excluido do conjunto %d.\n", n1);
                        else printf("Numero nao pertence ao conjunto %d ou o conjunto e vazio/nao existe!\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 5:
                printf("Qual conjunto voce deseja descobrir a cardinalidade?? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = tamanhoConjunto(&c1);
                        printf("A cardinalidade do conjunto %d e: %d. Caso seja 0 o conjunto e nulo/nao existe.\n", n1, tof);
                    break;
                    case 2:
                        tof = tamanhoConjunto(&c2);
                        printf("A cardinalidade do conjunto %d e: %d. Caso seja 0 o conjunto e nulo/nao existe.\n", n1, tof);
                    break;
                    case 3:
                        tof = tamanhoConjunto(&c3);
                        printf("A cardinalidade do conjunto %d e: %d. Caso seja 0 o conjunto e nulo/nao existe.\n", n1, tof);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 6:
                printf("Qual numero deseja verificar se ha elementos maiores? (1, 2 ou 3)\n");
                scanf("%d%*c", &n2);
                printf("Qual conjunto voce deseja que o numero seja verificado? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = maior(n2, &c1);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao maiores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento maior que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos maiores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d maiores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    case 2:
                        tof = maior(n2, &c2);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao maiores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento maior que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos maiores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d maiores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    case 3:
                        tof = maior(n2, &c3);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao maiores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento maior que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos maiores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d maiores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 7:
                printf("Qual numero deseja verificar se ha elementos maiores? (1, 2 ou 3)\n");
                scanf("%d%*c", &n2);
                printf("Qual conjunto voce deseja que o numero seja verificado? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = menor(n2, &c1);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao menores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento menor que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos menores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d menores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    case 2:
                        tof = menor(n2, &c2);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao menores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento menor que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos menores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d menores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    case 3:
                        tof = menor(n2, &c3);
                        if (tof == 0) printf("Todos os elementos do conjunto %d sao menores que %d.\n", n1, n2);
                        else if (tof > 0) {
                            if(tof == 1) printf("No conjunto %d ha %d elemento menor que %d.\n", n1, tof, n2);
                            else printf("No conjunto %d ha %d elementos menores que %d.\n", n1, tof, n2);
                        }
                        else printf("Nao ha elementos no conjunto %d menores que %d, ou o conjunto nao existe.\n", n1, n2);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 8:
                printf("Qual numero deseja verificar se pertence a um conjunto? (1, 2 ou 3)\n");
                scanf("%d%*c", &n2);
                printf("Qual conjunto voce deseja que o numero seja verificado? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = pertenceConjunto(n2, &c1);
                        if (tof == 1) printf("O numero %d pertence ao conjunto %d.\n", n2, n1);
                        else printf("O numero %d nao pertence ao conjunto %d.\n", n2, n1);
                    break;
                    case 2:
                        tof = pertenceConjunto(n2, &c2);
                        if (tof == 1) printf("O numero %d pertence ao conjunto %d.\n", n2, n1);
                        else printf("O numero %d nao pertence ao conjunto %d.\n", n2, n1);
                    break;
                    case 3:
                        tof = pertenceConjunto(n2, &c3);
                        if (tof == 1) printf("O numero %d pertence ao conjunto %d.\n", n2, n1);
                        else printf("O numero %d nao pertence ao conjunto %d.\n", n2, n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 9:
                printf("Qual conjunto voce deseja comparar a igualdade? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Qual conjunto a ser comparado? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    tof = conjuntoIdenticos(&c1, &c2);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 1 && n2 == 3){
                    tof = conjuntoIdenticos(&c1, &c3);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 1){
                    tof = conjuntoIdenticos(&c2, &c1);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 3){
                    tof = conjuntoIdenticos(&c2, &c3);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 2){
                    tof = conjuntoIdenticos(&c3, &c2);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 1){
                    tof = conjuntoIdenticos(&c3, &c1);
                    if (tof == 1) printf("Conjunto %d e igual ao Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e igual ao Conjunto %d.\n", n1, n2);
                }
                else printf("Voce nao pode copiar um conjunto para ele mesmo!\n");
                system("PAUSE");
            break;
            case 10:
                printf("Qual conjunto voce deseja saber se e subconjunto de outro? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Qual conjunto a ser comparado? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    tof = subconjunto(&c1, &c2);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 1 && n2 == 3){
                    tof = subconjunto(&c1, &c3);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 1){
                    tof = subconjunto(&c2, &c1);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 3){
                    tof = subconjunto(&c2, &c3);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 2){
                    tof = subconjunto(&c3, &c2);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 1){
                    tof = subconjunto(&c3, &c1);
                    if (tof == 1) printf("Conjunto %d e subconjunto do Conjunto %d.\n", n1, n2);
                    else printf("Conjunto %d nao e subconjunto do Conjunto %d.\n", n1, n2);
                }
                else{
                    if ((n1 == 1 && n2==1) || (n1 == 2 && n2==2) || (n1 == 3 && n2==3)) printf("Voce nao pode copiar um conjunto para ele mesmo!\n");
                    else printf("Numero de conjunto invalido!\n");
                }
                system("PAUSE");
            break;
            case 11:
                printf("Deseja descobrir o conjunto complemento de qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Em relacao a qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c1, c2);
                }
                else if (n1 == 1 && n2 == 3){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c1, c3);
                }
                else if (n1 == 2 && n2 == 1){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c2, c1);
                }
                else if (n1 == 2 && n2 == 3){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c2, c3);
                }
                else if (n1 == 3 && n2 == 2){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c3, c2);
                }
                else if (n1 == 3 && n2 == 1){
                    printf("Gerando o conjunto 4 (complemento)... Entre o Conjunto %d e o Conjunto %d = (Todos que estao em %d que nao estao em %d)\n", n2, n1, n2, n1);
                    c4 = complemento(c3, c1);
                }
                else{
                    if ((n1 == 1 && n2==1) || (n1 == 2 && n2==2) || (n1 == 3 && n2==3)) printf("{ }\n");
                    else printf("Numero de conjunto invalido!\n");
                }
                system("PAUSE");
            break;
            case 12:
                printf("Deseja descobrir o conjunto uniao de qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Em relacao a qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c1, c2);
                }
                else if (n1 == 1 && n2 == 3){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c1, c3);
                }
                else if (n1 == 2 && n2 == 1){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c2, c1);
                }
                else if (n1 == 2 && n2 == 3){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c2, c3);
                }
                else if (n1 == 3 && n2 == 2){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c3, c2);
                }
                else if (n1 == 3 && n2 == 1){
                    printf("Gerando o conjunto 5 (uniao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c5 = uniao(c3, c1);
                }
                else{
                    if ((n1 == 1 && n2==1) || (n1 == 2 && n2==2) || (n1 == 3 && n2==3)) printf("{ }\n");
                    else printf("Numero de conjunto invalido!\n");
                }
                system("PAUSE");
            break;
            case 13:
                printf("Deseja descobrir o conjunto interseccao de qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Em relacao a qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c1, c2);
                }
                else if (n1 == 1 && n2 == 3){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c1, c3);
                }
                else if (n1 == 2 && n2 == 1){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c2, c1);
                }
                else if (n1 == 2 && n2 == 3){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c2, c3);
                }
                else if (n1 == 3 && n2 == 2){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c3, c2);
                }
                else if (n1 == 3 && n2 == 1){
                    printf("Gerando o conjunto 6 (intersecao)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c6 = interseccao(c3, c1);
                }
                else {
                    selectionSort(c1.x, c1.size);
                    selectionSort(c2.x, c2.size);
                    selectionSort(c3.x, c3.size);
                    if (n1 == 1 && n2==1) c5 = c1;
                    else if (n1 == 2 && n2==2) c5 = c2;
                    else if (n1 == 3 && n2==3) c5 = c3;
                    else printf("Numero de conjunto invalido!\n");
                }
                system("PAUSE");
            break;
            case 14:
                printf("Deseja descobrir o conjunto diferenca de qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Em relacao a qual conjunto? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c2, c1);
                }
                else if (n1 == 1 && n2 == 3){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c3, c1);
                }
                else if (n1 == 2 && n2 == 1){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c1, c2);
                }
                else if (n1 == 2 && n2 == 3){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c3, c2);
                }
                else if (n1 == 3 && n2 == 2){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c2, c3);
                }
                else if (n1 == 3 && n2 == 1){
                    printf("Gerando o conjunto 7 (diferenca)... Entre o Conjunto %d e o Conjunto %d.\n", n1, n2);
                    c7 = diferenca(c1, c3);
                }
                else{
                    if ((n1 == 1 && n2==1) || (n1 == 2 && n2==2) || (n1 == 3 && n2==3)) printf("{ }\n");
                    else printf("Numero de conjunto invalido!\n");
                }
                system("PAUSE");
            break;
            case 15:
                printf("Qual conjunto voce deseja ver o conjunto das partes? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        printf("Conjunto das partes do Conjunto 1 =\n");
                        printpowerset(c1.x, c1.size);
                    break;
                    case 2:
                        printf("Conjunto das partes do Conjunto 2 =\n");
                        printpowerset(c2.x, c2.size);
                    break;
                    case 3:
                        printf("Conjunto das partes do Conjunto 3 =\n");
                        printpowerset(c3.x, c3.size);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 16:
                selectionSort(c1.x, c1.size);
                selectionSort(c2.x, c2.size);
                selectionSort(c3.x, c3.size);
                printf("Qual conjunto voce deseja vizualizar?\n(1, 2, 3) Conjuntos de usuários.\n(4, 5, 6, 7) Respectivamente: Complemento, Uniao, interseccaoao e diferenca.\n");
                scanf("%d%*c", &n1);
                printf("Digite 1 para vizualizar em ordem crescente e 0 para vizualizar em ordem decrescente:\n");
                scanf("%d%*c", &n2);
                switch(n1){
                    case 1:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c1, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c1, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 2:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c2, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c2, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 3:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c3, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c3, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 4:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c4, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c4, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 5:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c5, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c5, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 6:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c6, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c6, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    case 7:
                        if(n2 == 1){
                            printf("Conjunto %d em ordem CRESCENTE = ", n1);
                            mostraConjunto(c7, CRESCENTE);
                            printf("\n");
                        }
                        else if (n2==0){
                            printf("Conjunto %d em ordem DECRESCENTE = ", n1);
                            mostraConjunto(c7, DECRESCENTE);
                            printf("\n");
                        }
                        else printf("Ordenacao invalida!\n");
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 17:
                printf("Qual conjunto voce deseja copiar? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Qual conjunto sera copia do anterior? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    copy(&c1, &c2);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else if (n1 == 1 && n2 == 3){
                    copy(&c1, &c3);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 1){
                    copy(&c2, &c1);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else if (n1 == 2 && n2 == 3){
                    copy(&c2, &c3);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 2){
                    copy(&c3, &c2);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else if (n1 == 3 && n2 == 1){
                    copy(&c3, &c1);
                    printf("Conjunto %d copiado para o Conjunto %d com sucesso!\n", n1, n2);
                }
                else printf("Voce nao pode copiar um conjunto para ele mesmo!\n");
                system("PAUSE");
            break;
            case 18:
                printf("Digite o conjunto que deseja destruir (1, 2 ou 3) :\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        destroiconj(&c1);
                        printf("Conjunto %d destruido com sucesso!\n", n1);
                    break;
                    case 2:
                        destroiconj(&c2);
                        printf("Conjunto %d destruido com sucesso!\n", n1);
                    break;
                    case 3:
                        destroiconj(&c3);
                        printf("Conjunto %d destruido com sucesso!\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 19:
                printf("Digite o conjunto que deseja verificar a existencia (1, 2 ou 3) :\n");
                scanf("%d%*c", &n1);
                switch(n1){
                    case 1:
                        tof = testeexistconj(&c1);
                        if (tof == 1) printf("Conjunto %d existe!\n", n1);
                        else printf("Conjunto %d nao existe!\n", n1);
                    break;
                    case 2:
                        tof = testeexistconj(&c2);
                        if (tof == 1) printf("Conjunto %d existe!\n", n1);
                        else printf("Conjunto %d nao existe!\n", n1);
                    break;
                    case 3:
                        tof = testeexistconj(&c3);
                        if (tof == 1) printf("Conjunto %d existe!\n", n1);
                        else printf("Conjunto %d nao existe!\n", n1);
                    break;
                    default:
                    printf("Numero do conjunto invalido!\n");
                    break;
                }
                system("PAUSE");
            break;
            default:
                printf("Comando nao identificado!");
                system("PAUSE");
            break;
        }
    }
    system("CLS");
    return 0;
}