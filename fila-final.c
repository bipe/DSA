/*
Arquivo em C de Fila e funções pertinentes

->Seg Fault caso tente remover de uma fila vazia não foi tratado
->Podem ocorrer outros erros não tratados
*/


#include <stdlib.h>
#include <stdio.h>

struct node{ //Estrutura do nó

	int valor;
	struct node* prox;
};
typedef struct node NODE;

struct fila{ //Tipo Abstrato de Dados fila
	NODE* inicio;
	NODE* final;
};
typedef struct fila FILA;


FILA* criaFila();
int vazia(FILA* fila);
void insereFila(FILA* fila, int valor);
int removeFila(FILA* fila);
void cabeca(FILA* fila);

int main(){
	
	int menu;
	int valor;
	FILA* fila;

	
	do{
		printf("\n[MENU]\n\n1-Criar fila\n2-Inserir valor\n3-Remover valor\n4-Imprimir cabeca\n0-Sair\n");
		scanf("%d",&menu);
		switch(menu){

			case 1:
				fila = criaFila();
				printf("\nFila criada!\n");
			break;
			case 2:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &valor);
				insereFila(fila, valor);
			break;
			case 3:
				printf("\nValor removido: %d\n", removeFila(fila));
			break;
			case 4:
				cabeca(fila);
			break;

		}

	}while(menu!=0);

	return 0;
}//fim da main

FILA* criaFila(){ //Criação da fila, atribui NULL ao inicio e ao final
	FILA* fila = malloc(sizeof(FILA));
	fila->inicio = NULL;
	fila->final = NULL;
	return fila;
}

int vazia(FILA* fila){ //Checa se a fila esta vazia vendo o inicio de "fila"
	if(fila->inicio == NULL) return 1;
	else return 0;
}

void insereFila(FILA* fila, int valor){
	NODE* novo = malloc(sizeof(FILA));
	novo->valor = valor;
	novo->prox = NULL;

	if(vazia(fila)){//caso a lista esteja vazia, o inicio e o fim da fila apontam para o mesmo nó
		fila->inicio = novo;
		fila->final = novo;
	}
	else{//caso haja elementos na fila, o novo nó é adicionado ao fim
		(fila->final)->prox = novo;
		fila->final = novo;
	}
}

int removeFila(FILA* fila){
	NODE* aux = fila->inicio;
	int valor;
	fila->inicio = aux->prox;//o novo inicio da fila é o segundo nó (já q o primeiro será deletado)
	valor = aux->valor;//valor apagado será retornado usando esta variável
	free(aux);
	aux = NULL;
	if(fila->inicio == NULL) fila->final = NULL;
	return valor;
}

void cabeca(FILA* fila){ //exibe o valor do primeiro nó da fila

	if(!vazia(fila)) printf("\nPrimeiro da fila: %d\n", (fila->inicio)->valor);
	else printf("\nFila vazia!\n");
}