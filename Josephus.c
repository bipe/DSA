/*
Programa que resolve o problema de Josephus com o numero de prisioneiros e numero de passos, a saída é o ultimo sobreivente
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k;

	struct bloco {//definindo a estrutura de um nó
		int prisioneiro;
		struct bloco *prox;
		struct bloco *ant;
	};

	struct bloco *atual, *head;

	atual = NULL;
	head = NULL; //inicialização dos ponteiros (lista vazia)

	int i, cont;

	printf("Digite o número de prisioneiros (n): ");
	scanf("%d", &n);
	printf("Digite o número de passos (k): ");
	scanf("%d", &k);

	//Alocação de memória para os blocos de todos os prisioneiros:

	atual = head = malloc(sizeof(struct bloco));

	atual->prisioneiro = 1;//atribuição do numero do primeiro prisioneiro

	for (i = 2; i <= n; i++) {//atribuição dos números dos próximos prisioneiros
		atual->prox = malloc(sizeof(struct bloco));
		atual = atual->prox;
		atual->prisioneiro = i;
	}

	atual->prox = head;//Fechar a lista circular fazendo o "próximo" do último bloco apontar para o primeiro da lista
	 

// Eliminar os prisioneiros "de k em k" até que sobre apenas um sobrevivente

	for (cont = n; cont > 1; cont--){
		for (i = 0; i < k - 1; i++){
			atual = atual->prox;
		}
		atual->prox = atual->prox->prox;
	}

	printf("Sobrevivente: %d\n", atual->prisioneiro);

	return 0;
}
