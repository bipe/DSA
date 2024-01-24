#include <stdlib.h>
#include <stdio.h>

struct node //Estrutura do nó
{
	int valor;
	struct node* prox;
};
typedef struct node NODE;

NODE* lista;

NODE* criaLista();
NODE* insereIni(NODE* lista, int valor);
NODE* insereFim(NODE* lista, int valor);
NODE* removeFim(NODE* lista);
NODE* removeIni(NODE* lista);
NODE* removeMid(NODE* lista, int valor);
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

NODE* removeFim(NODE* lista){
	NODE* aux = lista;
	NODE* ant = NULL;
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
	NODE* aux = lista;
	NODE* ant = NULL;

	while(aux!=NULL && aux->valor!=valor){//Procura o no que contem o valor a ser removido
		ant = aux;
		aux = aux->prox;
	}
	if(aux==NULL) printf("Valor nao encontrado\n");//Caso rode toda a lista sem encontrar o valor procurado

	if(ant==NULL){//caso o nó a ser removido seja o primeiro
		lista = lista->prox;
		free(aux);
		aux = NULL;
	}
	else{
		ant->prox = aux->prox;
		free(aux);
		aux = NULL;
	}
	return lista;
}

void imprime(NODE* lista){
	NODE* aux = lista;
	while(aux!=NULL){
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
}