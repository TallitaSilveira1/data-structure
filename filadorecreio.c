#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--) {
        int numAlunos, i,j;
        scanf("%d",&numAlunos);
        int notas[numAlunos+1], vetoraux[numAlunos+1];
        for(i=0;i<numAlunos;i++){ //PREENCHER O VETOR
            scanf("%d",&notas[i]);
        }
        for(i=0;i<numAlunos;i++){ //PREENCHER VETOR AUXILIAR
            vetoraux[i] = notas[i];
        }
        int aux, fimDoVetor=numAlunos-1;
        for(i=0;i<numAlunos-1;i++) { //ORDENA‚AO BUBBLESORT
            for(j=0;j<fimDoVetor;j++) {
                if(notas[j] < notas[j+1]) {
                    aux = notas[j];
                    notas[j] = notas[j+1];
                    notas[j+1] = aux;
                }
            }
            fimDoVetor--;
        }
        int resultado=numAlunos;
        for(i=0;i<numAlunos;i++) {
            if(notas[i] != vetoraux[i]){
                resultado--;
            }
        }
        printf("%d\n",resultado);
    }
    return 0;
}
