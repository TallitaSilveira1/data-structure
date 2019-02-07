#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void OrdenaPalavras(char palavras[][25], int numPalavras) {
    int i;
    char strAux[25];
    int fimDaOrdencao = 0, count;
    // Ordenamos no estilo bubblesort
    for(count = 0; count < numPalavras - 1; count++){
        for (i = 0; i < numPalavras - 1 - fimDaOrdencao; i++) {
            /*  strcmp(str1,str2) retorna > 0 quando o primeiro caractere diferente
                entre duas strings for maior em str1
                Como queremos colocar em ordem alfabética, o primeiro deve ser
                o menor
                                                                            */
            if(strcmp(palavras[i], palavras[i+1]) > 0) {
                // Processo de troca
                strcpy(strAux, palavras[i]);
                strcpy(palavras[i], palavras[i+1]);
                strcpy(palavras[i+1], strAux);
            }
        }
        fimDaOrdencao++;
    }
}

// Função que recebe uma frase e separa em palavras:
int separaEmPalavras(char linha[], char palavras[][25], int tamLinha) {
    int numPalavras = 0;
    int posicao;
    for(posicao=0;posicao <= tamLinha; posicao++) {
        //  Se o caractere atual for um '\0', chegamos ao fim da linha:
        if(linha[posicao] == '\0')
            break;

        /*  Caso inicial: Iremos guardar a primeira palavra
            Na primeira palavra não precisamos nos preocupar
            com palavras repetidas */
        int posicaoPalavra = 0;
        while(linha[posicao] != ' ' && linha[posicao] != '\0') {
            //  Se encontrarmos um espaço em branco então a palavra acabou
            palavras[numPalavras][posicaoPalavra] = linha[posicao];
            posicao++, posicaoPalavra++;
        }
        //  Colocamos o '\0' no final para definir o fim da string
        palavras[numPalavras][posicaoPalavra] = '\0';
        /*  No caso de numPalavras maior que um, já podemos ter palavras
            repetidas, então testamos: */
        int contador = numPalavras - 1;
        while(contador >= 0) {
            //  Se a palavra atual for igual a uma já guardada:
            if(strcmp(palavras[numPalavras], palavras[contador]) == 0) {
                //  Reduzimos o numero de palavras
                numPalavras--;
                break;
            }
            contador--;
        }
        numPalavras++;
    }
    return numPalavras;
}

int main() {
    int numTestes;
    scanf("%d",&numTestes);
    // getchar elimina o \n que ficará no buffer depois de ler o numTestes
    getchar();
    while(numTestes--) {
        char listaCompras[25432];
        /*  Lerá tudo até encontrar um \n, depois consumirá um único char
            que é esse próprio \n */
        scanf("%[^\n]%*c",&listaCompras);
        int tamLinha = strlen(listaCompras);
        listaCompras[tamLinha] = '\0';
        //  O máximo de palavras possível será o numero de caracteres da linha
        char palavra[tamLinha+10][25];

        // Usamos a nossa função para separar em palavras
        int numPalavras = separaEmPalavras(listaCompras, palavra, tamLinha);
        // Depois ordenamos
        OrdenaPalavras(palavra, numPalavras);

        // E printamos
        int i;
        for(i=0;i < numPalavras; i++) {
            if(i == numPalavras - 1) {
                printf("%s" ,palavra[i]);
                break;
            }
            printf("%s " ,palavra[i]);
        }

        printf("\n");
    }

    return 0;
}
