#include<stdio.h>
#include<stdlib.h>
#define N 100

struct _heap{
int max; // tamanho maximo do heap
int pos; // proxima posicao disponivel no vetor
float* prioridade; // vetor das prioridades
};

typedef struct _heap Heap;
Heap* heap_cria(int max);
void heap_insere(Heap* heap, float priority);
void corrige_acima(Heap* heap, int pos);
void troca(int a, int b, float* v);
void imprime_vetor(Heap* heap);
float heap_remove(Heap* heap);
void imprime_maiores(Heap* heap);
void corrige_abaixo(Heap* heap);
float consulta_segunda(Heap* heap);
void imprime_em_ordem(Heap* heap);

int main(){

    //vai criar um heap vazio
    Heap *heap = heap_cria(N);
    
   float v;
    
    //vai inserir elementos no heap
    heap_insere(heap, 11.0);
    heap_insere(heap, 8.0);
    heap_insere(heap, 5.0);
    heap_insere(heap, 4.0);
    heap_insere(heap, 3.0);
    heap_insere(heap, 16.0);
    heap_insere(heap, 8.5);
    heap_insere(heap, 4.3);
    //vai imprimir o vetor das prioridades
    imprime_vetor(heap);
    
    //vai remover um elemento do heap
    v = heap_remove(heap);
    printf("\nElemento removido: %6.2f\n", v);
    imprime_vetor(heap);
    printf("\n");

    //vai consultar o segunda maior prioridade
    v = consulta_segunda(heap);
    if(v!= -1)   printf("\nSegunda maior prioridade: %6.2f\n", v);
    
   //vai imprimir as 3 maiores prioridades usando as funções anteriores (insere e remove)
    imprime_maiores(heap);
    printf("\n");
    
    //vai imprimir as prioridades em ordem decrescente, usando as funções anteriores (insere e remove) - use um heap
    imprime_em_ordem(heap);
    printf("\n");
    imprime_vetor(heap);
    printf("\n");

    v = heap_remove(heap);
    v = heap_remove(heap);
    v = heap_remove(heap);
    v = heap_remove(heap);
    
    imprime_maiores(heap);
    printf("\n");
    imprime_vetor(heap);
    printf("\n");
	
    system("pause");
    return 0;
}

Heap* heap_cria(int max){
  Heap* heap=(Heap*)malloc(sizeof(Heap));
  heap->max=max;
  heap->pos=0;
  heap->prioridade=(float *)malloc(max*sizeof(float));
  return heap;
}

void heap_insere(Heap* heap, float prioridade){
  if(heap->pos < heap->max){
    heap->prioridade[heap->pos]=prioridade;
    corrige_acima(heap,heap->pos);
    heap->pos++;
  }
  else{
    printf("Heap CHEIO!\n");
  }
}

void troca(int a, int b, float* v){
  float f = v[a];
  v[a] = v[b];
  v[b] = f;
}

void imprime_vetor(Heap* heap){
  int i=0;
  for(i=0;i<heap->pos;i++){
    printf("%.2f ",heap->prioridade[i]);
  }
 printf("\n");
}

void corrige_acima(Heap* heap, int pos){
  while (pos > 0){
  int pai = (pos-1)/2;
  if(heap->prioridade[pai] < heap->prioridade[pos]){
    troca(pos,pai,heap->prioridade);
  }
  else{
    break;
  }
  pos=pai;
  }
}

void imprime_maiores(Heap* heap){
  float p1=-1.0, p2=-1.0, p3=-1.0;
  if(heap->pos>0){
    p1=heap->prioridade[0];
    float ele1,ele2;
    if( heap->pos >= 2 ){
      ele1 = heap->prioridade[1];
      if (heap->pos > 2){
          ele2 = heap->prioridade[2];
      }
      else{
          ele2 = ele1;
      }
      if (ele2 > ele1){
        p2 = ele2;
        p3 = ele1;
      }
    }
    if(p1!=-1.0){
      printf("\nPrioridade 1: %6.2f", p1);
    }
    else{
     printf("\nNao ha prioridade 1");
    }
    if(p2!=-1.0){
      printf("\nPrioridade 2: %6.2f", p2);
    }
    else{
      printf("\nNao ha prioridade 2");
    }
    if(p3!=-1.0){
      printf("\nPrioridade 3: %6.2f\n", p3);
    }
    else{
      printf("\nNao ha prioridade 3");
    }
  }
}

float consulta_segunda(Heap* heap){
  float p1=-1.0, p2=-1.0;
  if(heap->pos>=2){
    float ele1 = heap->prioridade[1];
    float ele2 = heap->pos>2 ? heap->prioridade[2] : ele1;
    return ele2>ele1 ? ele2 : -1;
  }
}

void imprime_em_ordem(Heap* heap){
  Heap* heap_aux = heap_cria(N);
  Heap* heap_temp = heap_cria(N);
  heap_temp = heap;
  int i=0;
  while(heap_temp->pos > 0){
    heap_insere(heap_aux, heap_remove(heap_temp));
  }
  imprime_vetor(heap_aux);
}

void corrige_abaixo(Heap* heap){
  int pai=0;
  while(2*pai+1 < heap->pos){
    int filho_esq = 2*pai+1;
    int filho_dir = 2*pai+2;
    int filho;
    if (filho_dir >= heap->pos) filho_dir=filho_esq;
    if (heap->prioridade[filho_esq]>heap->prioridade[filho_dir])
    filho=filho_esq;
    else
    filho=filho_dir;
    if(heap->prioridade[pai]<heap->prioridade[filho])
      troca(pai,filho,heap->prioridade);
    else
      break;
    pai=filho;
  }
}

float heap_remove(Heap* heap){
  if(heap->pos>0){
    float topo=heap->prioridade[0];
    heap->prioridade[0]=heap->prioridade[heap->pos-1];
    heap->pos--;
    corrige_abaixo(heap);
    return topo;
  }
  else{
    printf("Heap VAZIO!");
    return -1;
  }
}