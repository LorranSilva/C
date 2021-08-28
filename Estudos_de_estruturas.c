#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

// estrutura da lista
struct lista{
	int info;
	struct lista *prox;
};

int *stack; //recebe o valor alocado
int *top; //topo da pilha
int *bottom; //final da pilha

void ordena_crescente(int *k, int v);
void ordena_decrescente(int *l, int p);
void push(int i, int max); //poe um elemento na pilha
int pop(void); //recupera o elemento no topo da pilha


int main(){

	int p=0, i=0, n=0, pi=0, select=1, count=0;
	int *j;

	do{
		count=0;
		n=0;
		fflush(stdin);
		printf("\nMENU:\n");
		printf("1 - Ordenar Vetor de Forma Crescente\n");
		printf("2 - Ordenar Vetor de Forma Decrescente\n");
		printf("3 - Ordenar Matriz de Forma Crescente\n");
		printf("4 - Ordenar Matriz de Forma Decrescente\n");
		printf("5 - Funcao Recursiva: Fribonacchi\n");
		printf(" -\n");
		printf(" -\n");
		printf("8 - Criar Lista Encadeada\n");
		printf("9 - Pilha\n");
		scanf("%d",&p);
		
		switch(p){
			case 1:
				system("cls");
				printf("\nSelecione o numero de posicoes do vetor:\n");
				scanf("%d",&n);
				system("cls");
				j=(int*)malloc(n*sizeof(int));
				if(j==NULL){
					printf("\nMemoria indisponivel\n");
					return 1;
				}
				for(i=0;i<n;i++){
					j[i]=rand()%50; //numeros randomicos entre 0 -50
					printf("%d: %d\t",i+1,j[i]); // mostra o vetor na ordem atual
				}
				ordena_crescente(j, n);
				p=0;
			case 2:
				system("cls");
				printf("\nSelecione o numero de posicoes do vetor:\n");
				scanf("%d",&n);
				system("cls");
				j=(int*)malloc(n*sizeof(int));
				if(j==NULL){
					printf("\nMemoria indisponivel\n");
					return 1;
				}
				for(i=0;i<n;i++){
					j[i]=rand()%50;
					printf("%d: %d\t",i+1,j[i]);
				}
				ordena_decrescente(j, n);
				p=0;
			case 3:
				/*system("cls");
				printf("Numero de linhas:\n");
				scanf("%d",&);
				system("cls");
				printf("Numero de colunas:\n");
				scanf("%d",&);*/
				break;
			case 4:
				system("cls");
				break;
			case 8:
				system("cls");
				break;
			case 9:
				system("cls");
				int a=0, b=0;
				printf("Tamanho da Pilha:\n");
				scanf("%d",&pi);
				stack=(int*)malloc(pi*sizeof(int));
				if(stack==NULL){
					printf("\nMemoria indisponivel\n");
					exit(1);
				}
				top=stack;
				bottom=stack+pi-1;
				pop();
				while(select==1 && count<pi){
					system("cls");
					if(count==pi-1){
						printf("Somente mais um valor disponivel\n");
					}
					printf("Valor a inserir:\n");
					scanf("%d",&n);
					push(n,pi);
					do{
						printf("Cotinuar a inserir:\n 1-sim 0-nao\n");
						scanf("%d",&select);
					}while(select!=0);
					count++;
				}
				p=0;
			default:
				printf("Comando nao existente");
		}
	}while(p==0);
	return 0;
}
void ordena_crescente(int *k, int v){
	int i=0, j=0, aux=0;
	printf("\n");
	for(i=0;i<v;i++){
		for(j=i;j<v;j++){
			if(k[i]>k[j]){
				aux=k[i];
				k[i]=k[j];
				k[j]=aux;
			}
		}
	}
	for(i=0;i<v;i++){
		printf("%d: %d\t",i,k[i]);
	}
	sleep(8);
	free(k);
	system("cls");
}
void ordena_decrescente(int *l, int p){
	int i=0, j=0, aux=0;
	printf("\n");
	for(i=0;i<p;i++){
		for(j=i;j<p;j++){
			if(l[i]<l[j]){
				aux=l[i];
				l[i]=l[j];
				l[j]=aux;
			}
		}
	}
	for(i=0;i<p;i++){
		printf("%d: %d\t",i,l[i]);
	}
	sleep(8);
	free(l);
	system("cls");
}
void push(int i, int max){
	if(stack>bottom){
		printf("Pilha Cheia\n");
		sleep(1);
		system("cls");
		return;
	}
	*stack=i;
	stack++;
}
int pop(void){
	stack--;
	if(stack<top){
		printf("Pilha vazia\n");
		return 0;
	}
	return *stack;
}
