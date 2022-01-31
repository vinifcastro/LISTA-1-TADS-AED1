#include "texto.h"

int main(){
    Texto ** texto = NULL;
    char aux[100000];
    char * ss = NULL;
    int i;
    int z=1, k, n1, p, n2;
    texto = (Texto **) malloc(4*sizeof(Texto *));
    for(i=0;i<4;i++){
        texto[i] = NULL;
    }
    while(z){
        system("CLS");
        printf("Digite 00 - Para finalizar o programa.\n");
        printf("Digite 01 - Para criar um novo texto.\n");
        printf("Digite 02 - Para liberar um texto.\n");
        printf("Digite 03 - Para descobrir o tamanho de um texto anteriomente criado.\n");
        printf("Digite 04 - Para obter um texto para um outro auxiliar.\n");
        printf("Digite 05 - Para mostrar um texto na tela.\n");
        printf("Digite 06 - Para copiar um texto para outro.\n");
        printf("Digite 07 - Para substituir um texto por outro.\n");
        printf("Digite 08 - Para concatenar 2 textos.\n");
        printf("Digite 09 - Para gerar um subtexto.\n");
        printf("Digite 10 - Localizar ocorrencia de uma frase em um texto.\n");
        printf("Digite 11 - Para comparar 2 textos.\n");
        scanf("%d%*c", &k);
        switch(k){
            case 0:
                system("CLS");
                z=0;
                printf("Finalizando programa...\n");
            break;
            case 1:
                printf("Qual o numero do Texto que deseja criar? (T1, T2 ou T3)?\n");
                scanf("%d%*c", &n1);
                printf("Digite o texto que deseja armazenar:\n");
                scanf("%[^\n]", aux);
                switch (n1) {
                    case 1:
                        texto[n1-1] = criarTexto(aux);
                    break;
                    case 2:
                        texto[n1-1] = criarTexto(aux);
                    break;
                    case 3:
                        texto[n1-1] = criarTexto(aux);
                    break;
                    default:
                        printf("Numero do texto escolhido e invalido!\n");
                    break;
                }
                printf("Texto %d criado com sucesso!!!\n", n1);
            break;
            case 2:
                printf("Qual o numero do Texto que deseja criar? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        liberarTexto (texto[n1-1]);
                    break;
                    case 2:
                        liberarTexto (texto[n1-1]);
                    break;
                    case 3:
                        liberarTexto (texto[n1-1]);
                    break;
                    case 4:
                        liberarTexto (texto[n1-1]);
                    break;
                    default:
                        printf("Numero do texto escolhido e invalido!\n");
                    break;
                }
                printf("Texto %d liberado com sucesso!!!\n", n1);
            break;
            case 3:
                p=-1;
                printf("Qual o Texto que deseja saber o tamanho? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        p = tamanhoTexto (texto[n1-1]);
                    break;
                    case 2:
                        p = tamanhoTexto (texto[n1-1]);
                    break;
                    case 3:
                        p = tamanhoTexto (texto[n1-1]);
                    break;
                    case 4:
                        p = tamanhoTexto (texto[n1-1]);
                    break;
                    default:
                        printf("Numero do texto escolhido e invalido!\n");
                    break;
                }
                if (p == 0) printf("O texto selecionado nao foi anteriomente criado!\n");
                else if (p > 0) printf("O texto possui %d caracteres.\n", p);
            break;
            case 4:
                printf("Qual o Texto que deseja obter para um texto auxiliar T4? (T1, T2 ou T3)?\n");
                scanf("%d%*c", &n1);
                if (texto[n1-1] == NULL) printf("Texto nao criado anteriormente!\n");
                else{
                    texto[3] == NULL;
                    switch (n1) {
                        case 1:
                            ss = obterTexto (texto[n1-1]);
                        break;
                        case 2:
                            ss = obterTexto (texto[n1-1]);
                        break;
                        case 3:
                            ss = obterTexto (texto[n1-1]);
                        break;
                        default:
                            printf("Numero do texto escolhido e invalido!\n");
                        break;
                    }
                    texto[3] = criarTexto(ss);
                    printf("Texto obtido com sucesso! T4 criado!\n");
                }
            break;
            case 5:
                printf("Qual o Texto que deseja ver? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                if(n1 != 1 && n1!=3 && n1!=4 && n1!=2){
                    printf("Numero do texto escolhido e invalido!\n");
                }
                else if (texto[n1-1] == NULL) printf("Texto nao criado anteriormente!\n");
                else mostrarTexto (texto[n1-1], texto[n1-1]->size);
            break;
            case 6:
                printf("Qual o Texto que deseja copiar? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                printf("Para qual? [ T1, T2, T3 ou T4(Auxiliar) ]\n");
                scanf("%d%*c", &n2);
                if(n1 != 1 && n1!=3 && n1!=4 && n1!=2 && n2 != 1 && n2!=3 && n2!=4 && n2!=2){
                    printf("Numero do texto escolhido e invalido!\n");
                }
                else if (texto[n1-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n1);
                else if (texto[n2-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n2);
                else {
                    texto[n2-1] = copiarTexto(texto[n1-1]);
                    printf("Texto copiado com sucesso!\n");
                }
            break;
            case 7:
                printf("Qual o Texto que deseja substituir? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                printf("Digite o novo texto: \n");
                scanf("%[^\n]%*c", aux);
                if(n1 != 1 && n1!=3 && n1!=4 && n1!=2 && n2 != 1 && n2!=3 && n2!=4 && n2!=2){
                    printf("Numero do texto escolhido e invalido!\n");
                }
                else if (texto[n1-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n1);
                else if (texto[n2-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n2);
                else {
                    substituirTexto (texto[n1-1], aux);
                    printf("Texto substituido com sucesso!\n");
                }
            break;
            case 8:
                printf("Qual texto voce deseja concatenar? (T1, T2 ou T3)?\n");
                scanf("%d%*c", &n1);
                printf("Com qual? (T1, T2 ou T3)?\n");
                scanf("%d%*c", &n2);
                if (texto[n1-1] == NULL) printf("Texto nao criado anteriormente!\n");
                else if (texto[n2-1] == NULL) printf("Texto nao criado anteriormente!\n");
                else{
                    texto[3] = concatenarTextos (texto[n1-1], texto[n2-1]);
                    printf("Texto concatenado com sucesso! T4 criado com a concatenacao!\n");
                }
            break;
            case 9:
                printf("Qual texto voce deseja criar um subtexto? (T1, T2 ou T3)?\n");
                scanf("%d%*c", &n1);
                printf("A partir de qual caractere?\n");
                scanf("%d%*c", &n2);
                if (texto[n1-1] == NULL) printf("Texto nao criado anteriormente!\n");
                else{
                    texto[3] = criarTexto((obterSubtexto (texto[n1-1], n2, texto[n1-1]->size)));
                    printf("Subtexto gerado com sucesso! T4 criado com ele!\n");
                }
            break;
            case 10:
                p=-1;
                printf("Qual o Texto que deseja localizar?? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                printf("Qual ocorrencia deseja encontrar?\n");
                scanf("%d%*c", &n2);
                printf("Digite o texto que deseja encontrar: \n");
                scanf("%[^\n]%*c", aux);
                if(n1 != 1 && n1!=3 && n1!=4 && n1!=2 && n2 != 1 && n2!=3 && n2!=4 && n2!=2){
                    printf("Numero do texto escolhido e invalido!\n");
                }
                else if (texto[n1-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n1);
                else {
                    p = encontrarSubtexto (texto[n1-1], aux, n2);
                }
                if(p == 0 ) printf("Nao foi encontrado nenhuma ocorrencia do texto digitado!\n");
                if (p>0) printf ("Foi encontrada a %d ocorrencia a partir do caractere %d.\n", n2, p);
            break;
            case 11:
                p=-2;
                printf("Qual o Texto que deseja comparar? [ T1, T2, T3 ou T4(Auxiliar) ]?\n");
                scanf("%d%*c", &n1);
                printf("Com qual? [ T1, T2, T3 ou T4(Auxiliar) ]\n");
                scanf("%d%*c", &n2);
                if(n1 != 1 && n1!=3 && n1!=4 && n1!=2 && n2 != 1 && n2!=3 && n2!=4 && n2!=2){
                    printf("Numero do texto escolhido e invalido!\n");
                }
                else if (texto[n1-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n1);
                else if (texto[n2-1] == NULL) printf("Texto %d nao criado anteriormente!\n", n2);
                else {
                    p =  compararTextos (texto[n1-1], texto[n2-1]);
                }
                if(p==-1) printf("O texto %d e menor que o Texto %d.\n", n1, n2);
                else if(p==0) printf("O texto %d e igual ao Texto %d.\n", n1, n2);
                else if(p==1) printf("O texto %d e maior que o Texto %d.\n", n1, n2);
            break;
            default:
                printf("Numero digitado invalido!\n");
            break;
        }
        system("PAUSE");
    }

    for(i=0;i<4;i++){
        free((texto[i]->texto));
        free(texto[i]);
    }
    free(texto);
    free(ss);
    return 0;
}

Texto * criarTexto (char * t){
    Texto * x = NULL;
    x = (Texto *) malloc(sizeof(Texto));
    if(x != NULL){
        x->size = strlen (t);
        x->texto = NULL;
        x->texto = (char *) malloc(( (x->size)+1 ) * sizeof (char));
        if(x->texto != NULL){
            strcpy (x->texto,t);
        }
    }
    return x;
}

void liberarTexto (Texto * t){
    free(t->texto);
    free(t);
}

unsigned int tamanhoTexto (Texto * t){
    if (t == NULL) return 0;
    return t->size;
}

char * obterTexto (Texto * t){
    char * z = NULL;
    z = (char *) malloc(((t->size)+1)*sizeof(char));
    strcpy(z, t->texto);
    return z;
}

void mostrarTexto (Texto *t, unsigned int colunas){
    int i;
    for (i=0; i<colunas; i++){
        if(t->texto[i] != '\n') printf("%c", t->texto[i]);
    }
    printf("\n");
}

Texto * copiarTexto (Texto * t){
    Texto * aux = NULL;
    aux = (Texto *) malloc(sizeof(Texto));
    aux->texto = obterTexto(t);
    aux->size = strlen(aux->texto);
    return aux;
}

void substituirTexto (Texto * t, char * alteracao){
    t->texto = NULL;
    t->size = (strlen(alteracao)+1);
    t->texto = (char *) malloc((t->size)*sizeof(char));
    strcpy(t->texto, alteracao);
}

Texto * concatenarTextos (Texto * t1, Texto * t2){
    int i;
    Texto * x = NULL;
    char * z = NULL;
    int size;
    size = ( ( strlen(t1->texto) ) + ( strlen(t2->texto) ) + 1 );
    z = ( char *) malloc((size)*sizeof(char));
    sprintf(z, "%s %s", obterTexto(t1), obterTexto(t2));
    x = (Texto *) malloc(sizeof(Texto));
    x = criarTexto(z);
    free(z);
    return x;
}

char * obterSubtexto (Texto * t, unsigned int inicio, unsigned int tamanho){
    int i;
    char * aux = NULL;
    if( (inicio>=tamanho) || (inicio<1) ){
        aux = (char *) malloc(2*sizeof(char));
        aux[0] = ' ';
        aux[1] = '\n';
    }
    else{
        aux = (char *) malloc(tamanho*sizeof(char));
        strcpy(aux, t->texto);
        for(i=0;i<inicio;i++){
            aux[i] = '\n';
        }
    }
    return aux;
}

unsigned int encontrarSubtexto (Texto * t, char * subtexto, unsigned int ocorrencia){
    int i, j, k=0, z=0;
    int count = 0;
    for(i=0; i<(t->size); i++){
        z = 0;
        k=i;
        for(j=0;j<(strlen(subtexto));j++){
            if(t->texto[k] != subtexto[j]) z = 1;
            k++;
        }
        if(z==0) count++;
        if(count == ocorrencia) return (i+1);
    }
    return 0;
}

int compararTextos (Texto * t1, Texto * t2){
    if((t1->size) < (t2->size)) return -1;
    else if((t1->size) == (t2->size)) return 0;
    else if((t1->size) > (t2->size)) return 1;
}