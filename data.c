#include "data.h"

int main(){
    int  z=1, n, j, n1, n2;
    unsigned int dia, mes, ano;
    Data *d1 = NULL, * d2 = NULL, * d3 = NULL;
    char format[9], *mdata;
    while(z){
        j = 0;
        system("CLS");
        printf("Digite 00 para finalizar o programa.\n");
        printf("Digite 01 criar uma data.\n");
        printf("Digite 02 para copiar uma data para outra.\n");
        printf("Digite 03 para liberar uma data.\n");
        printf("Digite 04 para somar dias em uma data.\n");
        printf("Digite 05 para subtrair dias em uma data.\n");
        printf("Digite 06 para editar uma data existente.\n");
        printf("Digite 07 para obter o(s) dia(s) de uma data existente.\n");
        printf("Digite 08 para obter o(s) mes(es) de existente.\n");
        printf("Digite 09 para obter o(s) ano(s) de existente.\n");
        printf("Digite 10 para checar se a data possui ano bissexto ou nao.\n");
        printf("Digite 11 para comparar 2 datas.\n");
        printf("Digite 12 para fazer a diferenca em dia(s) entre 2 datas.\n");
        printf("Digite 13 para fazer a diferenca em mes(es) entre 2 datas.\n");
        printf("Digite 14 para fazer a diferenca em mes(es) entre 2 datas.\n");
        printf("Digite 15 para saber o dia da semana.\n");
        printf("Digite 16 para vizualizar uma data.\n");
        scanf("%d%*c", &n);
        switch(n){
            case 0:
                z=0;
                printf("Finalizando programa...\n");
                system("PAUSE");
            break;
            case 1:
                printf("Deseja criar data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                printf("Digite o dia: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &dia);
                printf("Digite o mes: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &mes);
                printf("Digite o ano: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &ano);
                switch (n1) {
                    case 1:
                        d1 = criaData(dia, mes, ano);
                    break;
                    case 2:
                        d2 = criaData(dia, mes, ano);
                    break;
                    case 3:
                        d3 = criaData(dia, mes, ano);
                    break;
                    default:
                        printf("Numero da data invalido! Favor digite 1, 2 ou 3 para respectivamente data 1, data 2 ou data 3.\n");
                    break;
                }
                system("PAUSE");
            break;
            case 2:
                j=0;
                printf("Qual data voce deseja copiar? (1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Para qual?? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if (n1 == 1 && n2 == 2){
                    j++;
                    d2 = copiaData (*d1);
                }
                else if (n1 == 1 && n2 == 3){
                    j++;
                    d3 = copiaData (*d1);
                }
                else if (n1 == 2 && n2 == 1){
                    j++;
                    d1 = copiaData (*d2);
                }
                else if (n1 == 2 && n2 == 3){
                    j++;
                    d3 = copiaData (*d2);
                }
                else if (n1 == 3 && n2 == 2){
                    j++;
                    d2 = copiaData (*d3);
                }
                else if (n1 == 3 && n2 == 1){
                    j++;
                    d1 = copiaData (*d3);
                }
                else printf("Voce nao pode copiar uma data para ela mesma ou utilizar uma data invilida (Lembre-se que as datas validas sao 1, 2 ou 3).\n");
                if (j != 0) printf("Copiado com sucesso.\n");
                system("PAUSE");
            break;
            case 3:
                printf("Deseja liberar qual data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        liberaData (d1);
                    break;
                    case 2:
                        liberaData (d2);
                    break;
                    case 3:
                        liberaData (d3);
                    break;
                    default:
                        printf("Data informada invalida!\n");
                    break;
                }
                printf("Memoria da Data %d liberada.\n", n1);
                system("PAUSE");
            break;
            case 4:
                printf("Em que data deseja somar dias?\n");
                scanf("%d%*c", &n1);
                printf("Quantos dias deseja somar?\n");
                scanf("%d%*c", &n2);
                switch (n1) {
                    case 1:
                        d1 = somaDiasData (*d1, n2);
                        printf("Dias somados. Nova data = %02d/%02d/%04d\n", d1->d[0], d1->d[1], d1->d[2]);
                    break;
                    case 2:
                        d2 = somaDiasData (*d2, n2);
                        printf("Dias somados. Nova data = %02d/%02d/%04d\n", d2->d[0], d2->d[1], d2->d[2]);
                    break;
                    case 3:
                        d3 = somaDiasData (*d3, n2);
                        printf("Dias somados. Nova data = %02d/%02d/%04d\n", d3->d[0], d3->d[1], d3->d[2]);
                    break;
                    default:
                        printf("Data informada invalida!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 5:
                printf("Em que data deseja subtrair dias?\n");
                scanf("%d%*c", &n1);
                printf("Quantos dias deseja subtrair?\n");
                scanf("%d%*c", &n2);
                switch (n1) {
                    case 1:
                        d1 = subtrairDiasData(*d1, n2);
                        printf("Dias subtraidos. Nova data = %02d/%02d/%04d\n", d1->d[0], d1->d[1], d1->d[2]);
                    break;
                    case 2:
                        d2 = subtrairDiasData(*d2, n2);
                        printf("Dias subtraidos. Nova data = %02d/%02d/%04d\n", d2->d[0], d2->d[1], d2->d[2]);
                    break;
                    case 3:
                        d3 = subtrairDiasData(*d3, n2);
                        printf("Dias subtraidos. Nova data = %02d/%02d/%04d\n", d3->d[0], d3->d[1], d3->d[2]);
                    break;
                    default:
                        printf("Data informada invalida!\n");
                    break;
                }
                system("PAUSE");
            break;
            case 6:
                printf("Deseja atribuir dia/mes/ano em que data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                printf("Digite o dia: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &dia);
                printf("Digite o mes: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &mes);
                printf("Digite o ano: (Lembrando que deve ser uma data entre 01/01/1900 e 31/12/2200)\n");
                scanf("%d%*c", &ano);
                switch (n1) {
                    case 1:
                        if(d1 == NULL){
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        printf("Data atual = %02d/%02d/%04d\n", d1->d[0], d1->d[1], d1->d[2]);
                        atribuirData(d1, dia, mes, ano);
                    break;
                    case 2:
                        if(d2 == NULL){
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        printf("Data atual = %02d/%02d/%04d\n", d2->d[0], d2->d[1], d2->d[2]);
                        atribuirData(d2, dia, mes, ano);
                    break;
                    case 3:
                        if(d3 == NULL){
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        printf("Data atual = %02d/%02d/%04d\n", d3->d[0], d3->d[1], d3->d[2]);
                        atribuirData(d3, dia, mes, ano);
                    break;
                    default:
                        printf("Numero da data invalido! Favor digite 1, 2 ou 3 para respectivamente data 1, data 2 ou data 3.\n");
                    break;
                }
                system("PAUSE");
            break;
            case 7:
                j=0;
                printf("Deseja obter o(s) dia(s) de qual data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        if(d1 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemDiaData (*d1);
                    break;
                    case 2:
                        if(d2 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemDiaData (*d2);
                    break;
                    case 3:
                        if(d3 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemDiaData (*d3);
                    break;
                    default:
                        j++;
                        printf("Data informada invalida!\n");
                    break;
                }
                if (j == 0) printf("A data %d possui dia = %02d.\n", n1, n2);
                system("PAUSE");
            break;
            case 8:
                j=0;
                printf("Deseja obter o(s) mes(es) de qual data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        if(d1 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemMesData(*d1);
                    break;
                    case 2:
                        if(d2 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemMesData (*d2);
                    break;
                    case 3:
                        if(d3 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemMesData (*d3);
                    break;
                    default:
                        j++;
                        printf("Data informada invalida!\n");
                    break;
                }
                if (j == 0) printf("A data %d possui mes = %02d.\n", n1, n2);
                system("PAUSE");
            break;
            case 9:
                j=0;
                printf("Deseja obter o(s) ano(s) de qual data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        if(d1 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemAnoData (*d1);
                    break;
                    case 2:
                        if(d2 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemAnoData (*d2);
                    break;
                    case 3:
                        if(d3 == NULL){
                            j++;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        n2 = obtemAnoData (*d3);
                    break;
                    default:
                        j++;
                        printf("Data informada invalida!\n");
                    break;
                }
                if (j == 0) printf("A data %d possui ano = %04d.\n", n1, n2);
                system("PAUSE");
            break;
            case 10:
                j=-1;
                printf("Deseja obter o(s) ano(s) de qual data 1, 2 ou 3?\n");
                scanf("%d%*c", &n1);
                switch (n1) {
                    case 1:
                        if(d1 == NULL){
                            j=-1;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        ano = d1->d[2];
                        j = bissextoData(*d1);
                    break;
                    case 2:
                        if(d2 == NULL){
                            j=-1;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        ano = d2->d[2];
                        j = bissextoData(*d2);
                    break;
                    case 3:
                        if(d3 == NULL){
                            j=-1;
                            printf("Data nao foi criada!\n");
                            break;
                        }
                        ano = d3->d[2];
                        j = bissextoData(*d3);
                    break;
                    default:
                        j=-1;
                        printf("Data informada invalida!\n");
                    break;
                }
                if (j == 0) printf("Ano da %d Data %d nao bissexto!\n", ano, n1);
                else if (j == 1) printf("Ano %d da Data %d e bissexto!\n", ano, n1);
                system("PAUSE");
            break;
            case 11:
                j = -2;
                printf("Qual data voce deseja comparar?(1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Com qual?? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 )&& (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                if (n1 == n2){
                    printf("A data %d e igual a data %d.\n", n1, n2);
                    system("pause");
                    break;
                }
                if (n1 == 1 && n2 == 2){
                    j = comparaData (*d1, *d2);
                }
                else if (n1 == 1 && n2 == 3){
                    j = comparaData (*d1, *d3);
                }
                else if (n1 == 2 && n2 == 1){
                    j = comparaData (*d2, *d1);
                }
                else if (n1 == 2 && n2 == 3){
                    j = comparaData (*d2, *d3);
                }
                else if (n1 == 3 && n2 == 2){
                    j = comparaData (*d3, *d2);
                }
                else if (n1 == 3 && n2 == 1){
                    j = comparaData (*d3, *d1);
                }
                if (j == 0) printf("A data %d e igual a data %d.\n", n1, n2);
                else if (j == 1) printf("A data %d e maior que a data %d.\n", n1, n2);
                else if (j == -1) printf("A data %d e menor que a data %d.\n", n1, n2);
                system("PAUSE");
            break;
            case 12:
                j=0;
                printf("Qual data voce deseja comparar?(1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Com qual?? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 ) && (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                if (n1 == 1 && n2 == 2){
                    j = numeroDiasDatas (*d1, *d2);
                }
                else if (n1 == 1 && n2 == 3){
                    j = numeroDiasDatas (*d1, *d3);
                }
                else if (n1 == 2 && n2 == 1){
                    j = numeroDiasDatas (*d2, *d1);
                }
                else if (n1 == 2 && n2 == 3){
                    j = numeroDiasDatas (*d2, *d3);
                }
                else if (n1 == 3 && n2 == 2){
                    j = numeroDiasDatas (*d3, *d2);
                }
                else if (n1 == 3 && n2 == 1){
                    j = numeroDiasDatas (*d3, *d1);
                }
                printf("A diferenca entre as datas %d e data %d em dias e de: %d dia(s).\n", n1, n2, j);
                system("PAUSE");
            break;
            case 13:
                j=0;
                printf("Qual data voce deseja comparar?(1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Com qual?? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 ) && (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                if (n1 == 1 && n2 == 2){
                    j = numeroMesesDatas (*d1, *d2);
                }
                else if (n1 == 1 && n2 == 3){
                    j = numeroMesesDatas (*d1, *d3);
                }
                else if (n1 == 2 && n2 == 1){
                    j = numeroMesesDatas (*d2, *d1);
                }
                else if (n1 == 2 && n2 == 3){
                    j = numeroMesesDatas (*d2, *d3);
                }
                else if (n1 == 3 && n2 == 2){
                    j = numeroMesesDatas (*d3, *d2);
                }
                else if (n1 == 3 && n2 == 1){
                    j = numeroMesesDatas (*d3, *d1);
                }
                printf("A diferenca entre as datas %d e data %d em mes(es) e de: %d mes(es).\n", n1, n2, j);
                system("PAUSE");
            break;
            case 14:
                j=0;
                printf("Qual data voce deseja comparar?(1, 2, 3)\n");
                scanf("%d%*c", &n1);
                printf("Com qual?? (1, 2, 3)\n");
                scanf("%d%*c", &n2);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 ) && (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                if (n1 == 1 && n2 == 2){
                    j = numeroAnosDatas (*d1, *d2);
                }
                else if (n1 == 1 && n2 == 3){
                    j = numeroAnosDatas (*d1, *d3);
                }
                else if (n1 == 2 && n2 == 1){
                    j = numeroAnosDatas (*d2, *d1);
                }
                else if (n1 == 2 && n2 == 3){
                    j = numeroAnosDatas (*d2, *d3);
                }
                else if (n1 == 3 && n2 == 2){
                    j = numeroAnosDatas (*d3, *d2);
                }
                else if (n1 == 3 && n2 == 1){
                    j = numeroAnosDatas (*d3, *d1);
                }
                printf("A diferenca entre as datas %d e data %d em ano(s) e de: %d ano(s).\n", n1, n2, j);
                system("PAUSE");
            break;
            case 15:
                printf("Quer descobrir qual dia da semana de qual data?\n");
                scanf("%d%*c", &n1);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 ) && (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                switch (n1) {
                    case 1:
                        j = obtemDiaSemanaData(*d1);
                    break;
                    case 2:
                        j = obtemDiaSemanaData(*d2);
                    break;
                    case 3:
                        j = obtemDiaSemanaData(*d3);
                    break;
                    default:
                        printf("Data informada invalida!\n");
                    break;
                }
                printf("O dia da semana da data %d e: %s.\n",n1 , diasSemana[j-1]);
                system("PAUSE");
            break;
            case 16:
                for(n1=0;n1<9;n1++) format[n1] = '\0';
                printf("Qual data deseja vizualizar? (1, 2 ou 3)\n");
                scanf("%d%*c", &n1);
                printf("Qual formato? ( 'ddmmaaaa', 'aaaammdd', 'aaaa', 'mm', 'dd', 'ddmm' )\n");
                scanf("%s", format);
                if ((n1 != 1) && (n1 != 2) && (n1 != 3 ) && (n2 != 1 )&& (n2 != 2) && (n2 != 3)){
                    printf("Data(s) invalidas selecionadas!\n");
                    system("pause");
                    break;
                }
                switch (n1) {
                    case 1:
                        mdata = imprimeData (*d1, format);
                    break;
                    case 2:
                        mdata = imprimeData (*d2, format);
                    break;
                    case 3:
                        mdata = imprimeData (*d3, format);
                    break;
                    default:
                        printf("Data informada invalida!\n");
                    break;
                }
                printf("Data %d = %s\n", n1, mdata);
                system("PAUSE");
            break;
            default:
                system("CLS");
                printf("Comando invalido!\n");
                system("PAUSE");
            break;
        }
    }
    free(mdata);
    free(d1);
    free(d2);
    free(d3);
    system("CLS");
    return 0;
}

Data * criaData (unsigned int dia, unsigned int mes, unsigned int ano){
    Data * x = NULL;
    int j=0;
    x = (Data *) malloc(sizeof(Data));
    if(x != NULL){
        x->d[0] = dia;
        x->d[1] = mes; 
        x->d[2] = ano;
        
        if(bissextoData((*x)) == 1){
            if ( ( mes == 2 && ( (dia<1 ) || ( (dia>29) ) ) ) || ( ano<1900 || ano>2200) || ( ( mes != 2 && ( (dia<1 ) || ( dia > diasMeses[(mes-1)] ) ) ) || ( (mes<1) || (mes>12) ) ) ){
                j=1;
                x->d[0] = 0;
                x->d[1] = 0;
                x->d[2] = 0;
                printf("Dia/Mes/Ano invalidos, data nao criada!\n");
            }
        }
        else{
            if ( ( ano<1900 || ano>2200) ||  (dia<1 ) || ( dia > diasMeses[mes-1] )   || ( (mes<1) || (mes>12) ) ){
                j=1;
                x->d[0] = 0;
                x->d[1] = 0;
                x->d[2] = 0;
                printf("Dia/Mes/Ano invalidos, data nao criada!\n");
            }
        }
        if (j == 0) printf("Data criada com sucesso!\n");
    }
    else printf("Houve algum problema para criar a data\n");
    return x;
}

unsigned int bissextoData(Data d){
    int y = d.d[2];
    if(y % 4 == 0)
    {
        if( y % 100 == 0)
        {
            if ( y % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

Data * copiaData (Data d){
    Data * x = NULL;
    x = (Data *) malloc (sizeof (Data));
    if (x != NULL){
        *x = d;
    }
    return x;
}

void liberaData (Data * d){
    free(d);
}

Data * somaDiasData (Data d, unsigned int dias){
    int day, month, year;
    Data * x = NULL;
    x = (Data *) malloc(sizeof(Data));
    day = d.d[0] + dias;
    month = d.d[1];
    year = d.d[2];
    if (bissextoData(d) == 1){
        diasMeses[1]++;
        while(day > diasMeses[month-1]){
            day -= diasMeses[month-1];
            month++;
            if (month > 12){
                month = 1;
                year++;
            }
        }
        diasMeses[1]--;
    }
    else {
        while(day > diasMeses[month-1]){
            day -= diasMeses[month-1];
            month++;
            if (month > 12){
                month = 1;
                year++;
            }
        }
    }
    if(x!=NULL){
        x->d[0] = day;
        x->d[1] = month;
        x->d[2] = year;
    }
    return x;
}

Data * subtrairDiasData (Data d, unsigned int dias){
    int day, month, year, z;
    Data * x = NULL;
    x = (Data *) malloc(sizeof(Data));
    day = d.d[0] - dias;
    month = d.d[1];
    year = d.d[2];
    if (bissextoData(d) == 1){
        diasMeses[1]++;
        while(day < 1){
            z = day;
            month--;
            if (month < 1){
                month = 12;
                year--;
            }
            day = diasMeses[month-1] - z;
        }
        diasMeses[1]--;
    }
    else {
        while(day < 1){
            z = day;
            month--;
            if (month < 1){
                month = 12;
                year--;
            }
            day = diasMeses[month-1] - z;
        }
    }
    if(x!=NULL){
        x->d[0] = day;
        x->d[1] = month;
        x->d[2] = year;
    }
    return x;
}

void atribuirData (Data * d, unsigned int dia, unsigned int mes, unsigned int ano){
    Data x;
    int j=0;
   
    x.d[0] = dia;
    x.d[1] = mes; 
    x.d[2] = ano;
    
    if(bissextoData((*d)) == 1){
        if ( ( mes == 2 && ( (dia<1 ) || ( (dia>29) ) ) ) || ( ano<1900 || ano>2200) || ( ( mes != 2 && ( (dia<1 ) || ( dia > diasMeses[(mes-1)] ) ) ) || ( (mes<1) || (mes>12) ) ) ){
            j=1;
            x.d[0] = 0;
            x.d[1] = 0;
            x.d[2] = 0;
            printf("Dia/Mes/Ano invalidos, data nao criada!\n");
            liberaData(d);
        }
    }
    else{
        if ( ( ano<1900 || ano>2200) ||  (dia<1 ) || ( dia > diasMeses[mes-1] )   || ( (mes<1) || (mes>12) ) ){
            j=1;
            x.d[0] = 0;
            x.d[1] = 0;
            x.d[2] = 0;
            printf("Dia/Mes/Ano invalidos, data liberada!\n");
            liberaData(d);
        }
    }
    if (j == 0){ 
        printf("Data criada com sucesso!\n");
        *d = x;
    }

}

unsigned int obtemDiaData (Data d){
    return d.d[0];
}

unsigned int obtemMesData (Data d){
    return d.d[1];
}

unsigned int obtemAnoData (Data d){
    return d.d[2];
}

int comparaData (Data d1, Data d2){
    if ((d1.d[2] == d2.d[2]) && (d1.d[1] == d2.d[1]) && (d1.d[0] == d2.d[0])) return 0;
    else if (d1.d[2] < d2.d[2]) return -1;
    else if (d1.d[2] > d2.d[2]) return 1;
    else if(d1.d[1] < d2.d[1]) return -1;
    else if(d1.d[1] > d2.d[1]) return 1;
    else if(d1.d[0] < d2.d[0]) return -1;
    else if(d1.d[0] > d2.d[0]) return 1;
    return 0;
}

unsigned int numeroDiasDatas (Data d1, Data d2){
    int dt1, dt2, x, i, ano1, ano2;
    x = comparaData(d1, d2);
    if (x == 0) return 0;
    else{
        ano1 = d1.d[2];
        if (d1.d[1]<2) ano1--;
        ano1 = ano1/4 - ano1/100 + ano1/400;
        ano2 = d2.d[2];
        if (d2.d[1]<2) ano2--;
        ano2 = ano2/4 - ano2/100 + ano2/400;
    }
    dt1 = (365 * d1.d[2]) + ano1 + d1.d[0];
    for(i=0; i<(d1.d[1]-1); i++){
        dt1 += diasMeses[i];
    }
    dt2 = (365 * d2.d[2]) + ano2 + d2.d[0];
    for(i=0; i<(d2.d[1]-1); i++){
        dt2 += diasMeses[i];
    }
    if (dt1>dt2) return (dt1-dt2);
    else return (dt2-dt1);
}

unsigned int numeroMesesDatas (Data d1, Data d2){
    int mes1, mes2;
    mes1 = d1.d[2]-1;
    mes2 = d2.d[2]-1;
    mes1 = mes1*12 + d1.d[1];
    mes2 = mes2*12 + d2.d[1];
    if (mes1>mes2) return (mes1-mes2);
    else return (mes2-mes1);
}

unsigned int numeroAnosDatas (Data d1, Data d2){
    if (d1.d[2] > d2.d[2]) return (d1.d[2]-d2.d[2]);
    else return (d2.d[2]-d1.d[2]);
}

unsigned int obtemDiaSemanaData (Data d){
    int dia;
    dia = d.d[0];
    while(dia>7){
        dia-=7;
    }
    return dia;
}

char * imprimeData (Data d, char * formato){
    char * z = NULL;
    if(strcmp(formato,"ddmmaaaa") == 0 || strcmp(formato,"DDMMAAAA") == 0){
        z = (char *) malloc(11*sizeof(char));
        sprintf (z, "%02d/%02d/%04d%c", obtemDiaData(d), obtemMesData(d),obtemAnoData(d),'\n');
    }
    else if(strcmp(formato,"aaaammdd") == 0 || strcmp(formato,"AAAAMMDD") == 0){
        z = (char *) malloc(11*sizeof(char));
        sprintf (z, "%04d/%02d/%02d%c", obtemAnoData(d), obtemMesData(d), obtemDiaData(d), '\n');
    }
    else if(strcmp(formato,"aaaa") == 0 || strcmp(formato,"AAAA") == 0){
        z = (char *) malloc(5*sizeof(char));
        sprintf (z, "%04d%c", obtemAnoData(d), '\n');
    }
    else if(strcmp(formato,"dd") == 0 || strcmp(formato,"DD") == 0){
        z = (char *) malloc(3*sizeof(char));
        sprintf (z, "%02d%c", obtemDiaData(d), '\n');
    }
    else if(strcmp(formato,"mm") == 0 || strcmp(formato,"MM") == 0){
        z = (char *) malloc(3*sizeof(char));
        sprintf (z, "%02d%c", obtemMesData(d), '\n');
    }
    else if(strcmp(formato,"ddmm") == 0 || strcmp(formato,"DDMM") == 0){
        z = (char *) malloc(6*sizeof(char));
        sprintf (z, "%02d/%02d%c", obtemDiaData(d), obtemMesData(d), '\n');
    }
    else{
        z = (char *) malloc(15*sizeof(char));
        strcpy(z, "Data invalida!");
    }
    
    return z;
}