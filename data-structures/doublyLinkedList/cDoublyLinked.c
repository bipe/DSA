#include <stdio.h>
#include <stdlib.h>


struct node //Estrutura do nó
{
	int valor;
	struct node* prox;
	struct node* ant;
};
typedef struct node NODE;

NODE* lista;

NODE* criaLista();
NODE* insereIni(NODE* lista, int valor);
NODE* insereFim(NODE* lista, int valor);
NODE* removeFim(NODE* lista);
NODE* removeIni(NODE* lista);
NODE* removeMid(NODE* lista, int valor);
NODE* busca(NODE* lista, int valor);
void imprime(NODE* lista);
int vazia(NODE* lista);


int main(){
	
	int menu;
	int valor;
	NODE* lista;

	
	do{
		printf("\n[MENU]\n\n1-Criar lista\n2-Inserir no inicio\n3-Inserir no fim\n4-Remover no inicio\n5-Remover no fim\n6-Remover no meio\n7-Imprimir lista\n0-Sair\n");
		scanf("%d",&menu);
		switch(menu){

			case 1:
				lista = criaLista();
			break;
			case 2:
				printf("\nDigite o valor a ser inserido no inicio: ");
				scanf("%d", &valor);
				lista = insereIni(lista, valor);
			break;
			case 3:
				printf("\nDigite o valor a ser inserido no fim: ");
				scanf("%d", &valor);
				lista =insereFim(lista, valor);
			break;
			case 4:
				printf("\nRemovendo nó do final...\n");
				lista =removeFim(lista);
			break;
			case 5:
				printf("\nRemovendo nó do inicio...\n");
				lista =removeIni(lista);
			break;
			case 6:
				printf("\nDigite o valor a ser buscado e removido: ");
				scanf("%d", &valor);
				lista = removeMid(lista, valor);
			break;
			case 7:
				imprime(lista);
			break;

		}

	}while(menu!=0);

	return 0;
}//fim da main



NODE* criaLista(){
	printf("\nLista criada!\n");
	return NULL;
}

int vazia(NODE* lista){
	if(lista){
		return 0;
	}
	else return 1;
}

NODE* insereIni(NODE* lista, int valor){
	NODE* novo = malloc(sizeof(NODE));
	novo->valor = valor;
	novo->ant = NULL;
	novo->prox = lista;
	lista = novo;
	return lista;
}

NODE* insereFim(NODE* lista, int valor){
	NODE* aux = lista;
	NODE* novo = malloc(sizeof(NODE));
	novo->valor = valor;
	novo->prox = NULL;
	if(vazia(lista)) lista = novo;
	else{
		while(aux->prox!=NULL) aux = aux->prox;
		aux->prox = novo;
		novo->ant = aux;
	}//else
	return lista;
}

NODE* removeIni(NODE* lista){
	NODE* aux = lista;
	lista = lista->prox;
	free(aux);
	aux = NULL;
	return lista;
}

NODE* removeFim(NODE* lista){ //até aqui tudo certo
	NODE* aux = lista;

	while(aux->prox!=NULL){
		ant = aux;
		aux = aux->prox;
	}
	if(ant == NULL){
		lista = NULL;
		free(aux);
		aux = NULL;
	}
	else{
		ant->prox = NULL;
		free(aux);
		aux = NULL;

	}
	return lista;
}

NODE* removeMid(NODE* lista, int valor){
	NODE* aux = busca(lista, valor);
	if(aux == NULL){
		printf("O valor nao foi encontrado!\n");
		return lista;
	}

	if(lista == aux) lista = aux->prox; //Quando o elemento é o primeiro da lista
	else aux->ant->prox = aux->prox;

	if(aux->prox != NULL) aux->prox->ant = aux->ant;
	free(aux);
	aux = NULL;
	return lista;
}


void imprime(NODE* lista){
	NODE* aux = lista;
	while(aux!=NULL){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
}

NODE* busca(NODE* lista, int valor){
	NODE* aux;
	for(aux = lista; aux!=NULL; aux = aux->prox){
		if(aux->valor == valor) return aux;
		else return NULL;
	}
}