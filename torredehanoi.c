#include <stdio.h>
int A[8];
int B[8];
int C[8];

int posA = 0;
int posB = 0;
int posC = 0;

void empilhaA (int n){
      A[posA] = n;
        posA++;
}

int desempilhaA (){
      posA--;
      return A[posA];
}

int espiarA(){
    return A[posA-1];
}

void empilhaB (int n){
      B[posB] = n;
        posB++;
}

int desempilhaB (){
      posB--;
      return B[posB];
}

int espiarB(){
    return B[posB-1];
}

void empilhaC (int n){
      C[posC] = n;
        posC++;
}

int desempilhaC (){
      posC--;
      return C[posC];
}

int espiarC(){
    return C[posC-1];
}
/* mostra o conteudo das pilhas A,B e C*/
void mostrar(){
  int i;
  printf("\nA:");
  for(i = 0; i < posA; i++){
    printf("%d" ,A[i]);
  }
  printf("\nB:");
  for(i = 0; i < posB; i++){
    printf("%d" ,B[i]);
  }
  printf ("\nC:");
  for(i = 0; i < posC; i++){
    printf("%d" ,C[i]);
  }
    printf("\n");
}
    void inicializar(){
        int i;
        for (i = 8; i >= 1; i--){
            empilhaA(i);
        }
}
/*movimentos executados*/
    void moverAB(){
        if (posA==0){
            empilhaA(desempilhaB());
        } else if (posB==0){
            empilhaB(desempilhaA());
        }   else if (espiarA() < espiarB()) {
            empilhaB(desempilhaA());
        } else if (espiarB() < espiarA()) {
            empilhaA(desempilhaB());
        }
}

    void moverAC(){
         if (posA==0){
            empilhaA(desempilhaC());
        } else if (posC==0){
            empilhaC(desempilhaA());
        }   else if (espiarA() < espiarC()) {
            empilhaC(desempilhaA());
        } else if (espiarC() < espiarA()) {
            empilhaA(desempilhaC());
        }
    }

    void moverBC(){
          if (posB==0){
            empilhaB(desempilhaC());
        } else if (posC==0){
            empilhaC(desempilhaB());
        }   else if (espiarB() < espiarC()) {
            empilhaC(desempilhaB());
        } else if (espiarC() < espiarB()) {
            empilhaB(desempilhaC());
    }
}
int main (int argc, char *argv[]){
  inicializar();
  mostrar();
  moverAB();
  moverAC();
  moverBC();
  while (posC < 8){
    moverAB();
    mostrar();
    if (posC == 8) break;
    moverAC();
    mostrar();
    if (posC == 8) break;
    moverBC();
    mostrar();
}
  return 0;
}
