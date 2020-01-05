/*
Lista postal em estrutura duplamente encadeada circular
O uso pode ser adaptado mudando a estrutura do nó

Trabalho 2 - Algoritmos e Técnicas de Programação 2
Autor: Luís Felipe Marconi

Compilador:
gcc 4.8 - Ubuntu 14.04
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no //definindo a estrutura de um nó
	{
	char nome[40];
	char rua[50];
	int n_rua;
	char cidade[25];
	char uf[15];
	char pais[15];
	long long cep;
	struct no *prox;
	struct no *ant;
	};

struct no *primeiro, *ultimo;//declaração dos ponteiros do inicio e final da lista

int num_nos;//variável global com o numero de nós existentes na lista

int pos;//variável para contagem das posições dos nós

//protótipos das funções usadas
void inicializar();
void add_fim();
void imprimir_ordem();
void imprimir_ordem_inversa();
void show_primeiro_ant();
void show_primeiro_prox();
void buscar();
void eliminar();                                                                                                           
                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int main(){
	int opcao;

	do
	{
	printf("\n");
	printf("\n[MENU]\n");
	printf("\n1- Inicializar (ATENCAO! Os dados da lista serao apagados!)");
	printf("\n2- Inserir no final");
	printf("\n3- Visualizar lista em ordem");
	printf("\n4- Visualizar lista em ordem invertida");
	printf("\n5- Visualizar entrada anterior a primeira");
	printf("\n6- Visualizar entrada posterior a primeira");     
	printf("\n7- Buscar uma entrada");
	printf("\n8- Apagar a primeira entrada");
	printf("\n9- Sair do Programa");
	printf("\n\n\n");
     
	printf("\nEscolha uma opção: ");
	scanf("%d",&opcao);  

     
	switch (opcao)
		{
		case 1:  inicializar();
			break;
		case 2:  add_fim();
			break;
		case 3:  imprimir_ordem();
			break;
		case 4:  imprimir_ordem_inversa();
			break;
		case 5:  show_primeiro_ant();
			break;
		case 6:  show_primeiro_prox();
			break;
		case 7:  buscar();
			break;
		case 8: eliminar();
			break;
                case 9: return 0;
			break;
		default: printf("Digite uma opcao valida\n");
			break;
	}                                                                                                                                            
} while (opcao!=9);                                                                                                                        
}
 
void inicializar(){//A função inicializar faz a lista ser "resetada", voltando para seu estado inicial
	primeiro=NULL;
	ultimo=NULL;
	num_nos=0;
	printf("\n Lista inicializada com sucesso!\n\n");
}
      
void add_fim(){//Função que vai adicionar um nó no final da lista
	struct no *novo;
	novo=( struct no*)malloc(sizeof( struct no));//alocação dinâmica para o novo nó
	if(novo==NULL)
		printf("\n Memoria insuficiente!\n");
	else{
		printf("\nDigite o nome: ");
		scanf(" %[^\n]", novo->nome);
		printf("\nDigite o nome da rua: ");
		scanf(" %[^\n]", novo->rua);
		printf("\nDigite o numero da rua: ");
		scanf(" %d", &novo->n_rua);
		printf("\nDigite a cidade: ");
		scanf(" %[^\n]", novo->cidade);
		printf("\nDigite o estado: ");
		scanf(" %[^\n]", novo->uf);
		printf("\nDigite o pais: ");
		scanf(" %[^\n]", novo->pais);
		printf("\nDigite o cep: ");
		scanf("%Ld", &novo->cep);
		novo->prox=primeiro;
		if(primeiro==NULL){//caso o ponteiro de inicio da lista aponte para nulo (não há primeiro nó):
			primeiro=novo;
			ultimo=novo;
			novo->prox=primeiro;
			novo->ant= ultimo;
		}else{//caso exista um nó no inicio da lista:
			novo->prox= primeiro;//como o nó é adicionado ao fim da lista, seu ponteiro "prox" aponta para o primeiro nó
			novo->ant=ultimo; 
			ultimo->prox=novo;
			ultimo=novo;
			primeiro->ant= ultimo; 
		}
	}
	num_nos++;                                                                                                                                                                                                                                                                                                                                                                                    
}                                                                                                                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                        
void imprimir_ordem(){

	struct no *atual;
	pos=1;
	atual=primeiro;
     
	while(pos<=num_nos){//laço que imprime, a partir do primeiro nó (pos = 1) as entradas
		printf("Entrada %d : \n", pos);
          
		printf("Nome: %s\n", atual->nome);
		printf("Rua: %s %d\n", atual->rua, atual->n_rua);
		printf("Cidade: %s\n", atual->cidade);
		printf("Estado: %s\n", atual->uf);
		printf("País: %s\n", atual->pais);
		printf("CEP:: %Ld\n\n", atual->cep);
          
		atual= atual->prox;
          
		pos++;//posição incrementada para imprimir os dados do próximo nó
	}
	if(num_nos==0)
		printf("\nA lista está vazia!");   
		printf("\n");
	}  
  
                                                                                                      
void imprimir_ordem_inversa(){
     
	struct no *atual;
	atual=ultimo;
	pos= num_nos;
     
	while(pos >0){//laço que imprime os nós a partir do último (pos = num_nos)
		printf("Entrada %d : \n", pos);
          
		printf("Nome: %s\n", atual->nome);
		printf("Rua: %s %d\n", atual->rua, atual->n_rua);
		printf("Cidade: %s\n", atual->cidade);
		printf("Estado: %s\n", atual->uf);
		printf("País: %s\n", atual->pais);
		printf("CEP:: %Ld\n\n", atual->cep);
		atual = atual->ant;
		pos--;//posição decrementada para imprimir o nó anterior
	}                                                                                                                    
	if(num_nos==0)
		printf("\nA lista está vazia!");
       
	printf("\n");
                                                                                           
}     

void show_primeiro_ant(){

	struct no *atual;
	pos = num_nos;
	atual = primeiro->ant;//o nó "atual" é criado com os valores contidos no nó anterior ao primeiro
 
	printf("Entrada %d : \n", pos);
	printf("Nome: %s\n", atual->nome);
	printf("Rua: %s %d\n", atual->rua, atual->n_rua);
	printf("Cidade: %s\n", atual->cidade);
	printf("Estado: %s\n", atual->uf);
	printf("País: %s\n", atual->pais);
	printf("CEP:: %Ld\n\n", atual->cep);
	printf("\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    

void show_primeiro_prox(){

	struct no *atual;
	pos = 1;
      
	atual = primeiro->prox;//homologamente a função anterior, o atual contém valores do nó próximo ao primeiro
 
	printf("Entrada %d : \n", pos+1);
	printf("Nome: %s\n", atual->nome);
	printf("Rua: %s %d\n", atual->rua, atual->n_rua);
	printf("Cidade: %s\n", atual->cidade);
	printf("Estado: %s\n", atual->uf);
	printf("País: %s\n", atual->pais);
	printf("CEP:: %Ld\n\n", atual->cep);
	printf("\n"); 
	printf("\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                               
                                                                                                                                                                            
void buscar(){

	struct no *atual;
	char aux [40];
	int p = 1;
	int encontrado = 0; 
     
	atual = primeiro;
	printf("\nIndique o nome a ser procurado: ");//a busca é feita pelo nome do cliente registrado na lista
	scanf(" %[^\n]", aux);
	while (p <= num_nos){//laço que percorre toda a lista  
		if(strcmp(aux, atual->nome)==0){//comparação entre o nome digitado e o nome armazenado nos nós
			printf("\n%s esta localizado na entrada numero %d", aux, p);
			encontrado = 1;
		}
		p++;
		atual = atual->prox;
	}                                                                                       
	if (encontrado==0)   
		printf("\nNenhuma entrada foi encontrada\n");
                                                                                                                                                                                                                                    
	printf("\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}
void eliminar(){//Função que vai eliminar o primeiro nó da lista

	struct no  *aux;

		aux = primeiro;//o nó 'aux' recebe informações do nó 'primeiro', para depois ser excluído
		primeiro = primeiro->prox;//o novo início da lista passa a ser o 'prox' nó (próximo do primeiro)
		if(primeiro == NULL)
			ultimo = NULL;
		else
			primeiro->ant == ultimo;//o novo nó de início recebe o último nó como nó anterior

	free(aux);//nó 'aux' é liberado da memória, e então excluído
	num_nos--; //numero total de nós da lista é diminuido                                                                                             
}                                                                                                                                                                                                                                                                                                                                                                                                                                    

  
