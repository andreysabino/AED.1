#include <stdio.h>
#include <stdlib.h>

void mergeSort(int x, int inf, int sup, int t);
void merge(int x, int inf, int sup, int mid, int t);


void mergeSort(int x, int inf, int sup, int t)
{  
    int meio;
    if (inf < sup){
        meio=(inf+sup)/2; //Este trecho calcula o meio do vetor
        mergeSort(x, inf, meio, t);//Metade do vetor a esquerda 
        mergeSort(x, meio+1, sup, t);//Metade do vetor a direita 
        merge(x, inf, sup, meio, t);
    }
}

void merge (int x, int inf, int sup, int mid, int t)
{
    int i, j, k, c[t];
    i = inf;
    k = inf;
    j = mid + 1;
    //Cópia os elementos da primeira parte do vetor 
    while (i <= mid && j <= sup) {
        if (c[i] < c[j]) {
            c[k] = c[i];
            k++;
            i++;
        }
        //Copia os elementos da segunda parte
        else  {
            c[k] = c[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = c[i];
        k++;
        i++;
    }
    while (j <= sup) {
        c[k] = c[j];
        k++;
        j++;
        //Copia o restante dos elementos assim que a primeira parte é finalizada
    }
    for (i = inf; i < k; i++)  {
        c[i] = c[i];
    }
    //Cópia todos os elementos do vetor auxiliar ordenado pro vetor original 
}

int main() {
  int i, t, v[] = {33, 71, 75, 10, 29, 55, 74, 73, 65, 19};

  printf("números a serem ordenados:\n");
//exibindo números do vetor
for (i = 0; i <= 9; i++)
{
    printf("%4d", v[i]);
}

  //exibe valores ordenados
  printf("\nnúmeros ordenados:\n");
  mergeSort(0, 0, 10, 10);  
  for (i = 0; i < 10; i++) {
     
    printf("%4d", v[i]);
  }
  return 0;
}