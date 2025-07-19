#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct duplamente
{
	int valor;
	struct duplamente *next, *back;
}duplamente;

typedef struct simples
{
	int valor;
	struct simples *next;
}simples;

typedef struct arvore
{
	int valor;
	struct arvore *next, *back, *below;
}arvore;

typedef struct arvoreBinaria
{
	int valor;
	struct arvoreBinaria *next, *back;
}arvoreBinaria;

typedef struct fila
{
	int valor;
	struct fila *next;
}fila;

typedef struct pilha
{
	int valor;
	struct pilha *next;
}pilha;

struct pilha *novo, *topo;
struct fila *corrente, *auxiliar, *primeiro;
struct arvoreBinaria *raiz, *root;
struct arvore *chain, *helper, *tree, *grass;
struct simples *simCorrente, *simAuxiliar, *simInicio;
struct duplamente *duplaCorrente, *duplaAuxiliar, *duplaInicio, *end;

bool arvoreBValidacao;
int valInserido;

void enterdata()
{
	printf("|Digite um numero: ");
}

void pop()
{
	printf("\t---'Pop Pilha'---\n\n");

	if(topo == NULL) printf("> Pilha vazia\n\n");
	else
	{
		printf("> O topo %d foi excluido com sucesso\n\n", topo->valor);
		novo = topo;
		topo = topo->next;
		free(novo);
	}

	system("pause");
	system("cls");
}

void top()
{
	printf("\t---'Top Pilha'---\n\n");

	if(topo == NULL) printf("> Pilha vazia\n\n");
	else printf("> Topo da pilha: %d\n\n", topo->valor);

	system("pause");
	system("cls");
}

void push()
{
	printf("\t---'Push Pilha'---\n\n");

	novo = (pilha*)malloc(sizeof(pilha));

	enterdata();
	scanf("%d", &novo->valor);

	if(topo == NULL)
	{
		topo = novo;
		novo->next = NULL;
	}
	else
	{
		novo->next = topo;
		topo = novo;
	}

	printf("\n> Numero %d inserido com sucesso na pilha\n\n", novo->valor);
	system("pause");
	system("cls");
}

void pilhas()
{
	novo = NULL;
	topo = NULL;

	int operacao;

	do
	{
		printf("\t---'Menu Pilha'---\n\n");
		printf("[1] - Push\n");
		printf("[2] - Top\n");
		printf("[3] - Pop\n");
		printf("[4] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				push();
			break;

			case 2:
				top();
			break;

			case 3:
				pop();
			break;

			case 4:
				return;
			break;

			default:
				printf("\t---'Menu Pilha'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}

	}while(operacao != 4);
}

void dequeue()
{
	printf("\t---'Dequeue Fila'---\n\n");

	if(primeiro == NULL) printf("> Fila vazia\n\n");
	else
	{
		printf("> O valor %d foi excluido da fila\n\n", primeiro->valor);
		auxiliar = primeiro;
		primeiro = primeiro->next;
		free(auxiliar);
		auxiliar = primeiro;
	}

	system("pause");
	system("cls");
}

void showQueue()
{
	int i = 0;

	printf("\t---'ShowQueue Fila'---\n\n");

	if(primeiro == NULL) printf("> Fila vazia\n\n");
	else
	{
		corrente = primeiro;

		while(corrente != NULL)
		{
			i++;
			printf("[Posicao: %dº] - |Valor: %d|\n", i, corrente->valor);
			corrente = corrente->next;
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

void enqueue()
{
	corrente = (fila*)malloc(sizeof(fila));

	printf("\t---'Enqueue Fila'---\n\n");

	enterdata();
	scanf("%d", &corrente->valor);

	if(primeiro == NULL)
	{
		auxiliar = corrente;
		primeiro = corrente;
	}
	else
	{
		auxiliar->next = corrente;
		auxiliar = corrente;
	}

	corrente->next = NULL;

	printf("\n> Numero %d inserido com sucesso na fila\n\n", corrente->valor);
	system("pause");
	system("cls");
}

void filas()
{
	corrente = NULL;
	auxiliar = NULL;
	primeiro = NULL;

	int operacao;

	do
	{
		printf("\t---'Menu Fila'---\n\n");
		printf("[1] - Enqueue\n");
		printf("[2] - ShowQueue\n");
		printf("[3] - Dequeue\n");
		printf("[4] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				enqueue();
			break;

			case 2:
				showQueue();
			break;

			case 3:
				dequeue();
			break;

			case 4:
				return;
			break;

			default:
				printf("\t---'Menu Fila'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}


	}while(operacao != 4);
}

arvoreBinaria *criarAB(arvoreBinaria *corrente, int dado)
{
	corrente = (arvoreBinaria*)malloc(sizeof(arvoreBinaria));
	corrente->valor = dado;
	corrente->next = NULL;
	corrente->back = NULL;

	if(raiz == NULL) raiz = corrente;

	return corrente;
}

arvoreBinaria *inserirArvoreBinaria(arvoreBinaria *corrente, int dado)
{
	if(corrente == NULL) corrente = criarAB(corrente, dado);
	else
	{
		if(dado > corrente->valor) corrente->next = inserirArvoreBinaria(corrente->next, dado);
		else if(dado <  corrente->valor) corrente->back = inserirArvoreBinaria(corrente->back, dado);
		else 
		{
			arvoreBValidacao = false;
			printf("\n> Valor %d ja existe na arvore\n\n", corrente->valor);
		}
	}

	return corrente;
}

bool pesquisaAB(arvoreBinaria *root, int pesq)
{
	if(pesq > root->valor)
	{
		while(root != NULL)
		{
			if(root->valor == pesq)
			{
				return true;
				break;
			} 
			root = root->next;
		}
	}
	else
	{
		while(root != NULL)
		{
			if(root->valor == pesq)
			{
				return true;
				break;
			} 
			root = root->back;
		}
	}

	return false;
}

void pesquisarAB()
{
	printf("\t---'Pesquisar Arvore Binaria'---\n\n");

	if(raiz == NULL) printf("> Arvore Binaria vazia\n\n");
	else
	{
		int pesq;
		bool resultado = false;

		printf("|Digite um numero para a pesquisa: ");
		scanf("%d", &pesq);

		if(pesq == raiz->valor) 
		{
			printf("\n> O numero %d eh a raiz da arvore binaria\n\n", pesq);
			return;
		}
		else if(pesq > raiz->valor)
		{
			root = raiz;

			while(root != NULL)
			{	
				if(root->valor == pesq)
				{	
					printf("\n> O numero %d existe a direita da raiz\n\n", pesq);
					resultado = true;
					break;
				}
				root = root->next;
			}
		}
		else
		{
			root = raiz;

			while(root != NULL)
			{	
				if(root->valor == pesq)
				{	
					printf("\n> O numero %d existe a esquerda da raiz\n\n", pesq);
					resultado = true;
					break;
				}
				root = root->back;
			}
		}

		if(resultado == false) printf("\n> O numero %d nao existe na arvore binaria\n\n", pesq);
	}
}

void exibirArvoreBinaria(arvoreBinaria *root)
{
	if(root == NULL) return;
	else
	{
		exibirArvoreBinaria(root->back);

		if(root->valor == raiz->valor) printf("[RAIZ] - |Valor: %d|\n", root->valor);
		else if(root->valor < raiz->valor) printf("[ESQUERDA] - |Valor: %d|\n", root->valor);
		else printf("[DIREITA] - |Valor: %d|\n", root->valor);

		exibirArvoreBinaria(root->next);
	}
}

void exibirAB()
{
	printf("\t---'Exibindo Arvore Binaria'---\n\n");

	if(raiz == NULL) printf("> Arvore Binaria vazia\n\n");
	else
	{
		root = raiz;
		exibirArvoreBinaria(root);
	}
}

void inserirAB()
{
	int val;

	printf("\t---'Inseir Arvore Binaria'---\n\n");

	enterdata();
	scanf("%d", &val);

	valInserido = val;

	root = inserirArvoreBinaria(raiz, val);
}

void arvoreBinarias()
{
	arvoreBValidacao = true;
	raiz = NULL;
	root = NULL;

	int operacao;

	do
	{
		printf("\t---'Menu Arvore Binaria'---\n\n");
		printf("[1] - Inserir\n");
		printf("[2] - Exibir\n");
		printf("[3] - Pesquisar\n");
		printf("[4] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				inserirAB();
				if(arvoreBValidacao == true) printf("\n> Valor %d inserido com sucesso\n\n", valInserido);
				
				system("pause");
				system("cls");
			break;

			case 2:
				exibirAB();
				printf("\n");
				system("pause");
				system("cls");
			break;

			case 3:
				pesquisarAB();
				system("pause");
				system("cls");
			break;

			case 4:
				return;
			break;

			default:
				printf("\t---'Menu Arvore Binaria'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 4);
}

void inserir_embaixo()
{
	helper = tree;

	while(helper->below != NULL) helper = helper->below;

	helper->below = chain;

	printf("\n> Numero %d inserido abaixo da arvore\n\n", chain->valor);
}

void inserir_esquerda()
{
	helper = tree;

	while(helper->back != NULL) helper = helper->back;

	helper->back = chain;

	printf("\n> Numero %d inserido a esquerda da arvore\n\n", chain->valor);
}

void inserir_direita()
{
	helper = tree;

	while(helper->next != NULL) helper = helper->next;

	helper->next = chain;

	printf("\n> Numero %d inserido a direita da arvore\n\n", chain->valor);
}

void inserirA()
{
	chain = (arvore*)malloc(sizeof(arvore));
	chain->next = NULL;
	chain->back = NULL;
	chain->below = NULL;

	printf("\t---'Inserir Arvore'---\n\n");
	enterdata();
	scanf("%d", &chain->valor);

	if(tree == NULL)
	{
		tree = chain;
		helper = chain;
		grass = chain;

		printf("\n> A raiz da arvore [%d] foi inserida com sucesso\n\n", tree->valor);
	}
	else
	{
		int op;

		printf("\n> Digite aonde quer inserir o novo numero:\n\n");
		printf("[1] - ESQUERDA [2] - DIREITA [3] - ABAIXO\n\n");
		printf("|: ");
		scanf("%d", &op);

		if(op == 1) inserir_esquerda();
		else if(op == 2) inserir_direita();
		else if(op == 3) inserir_embaixo();
		else printf("\n> Digite um numero valido\n\n");
	}
}

void exibirA()
{
	printf("\t---'Exibindo Arvore'---\n\n");

	if(tree == NULL) printf("> Arvore vazia\n\n");
	else
	{
		grass = tree;

		printf("-> [RAIZ DA ARVORE] : %d\n\n", tree->valor);

		system("pause");
		system("cls");

		printf("-> [EQUERDA DA ARVORE]\n\n");

		if(tree->back != NULL)
		{
			while(grass != NULL)
			{
				if(grass->valor != tree->valor) printf("|Valor: %d|\n", grass->valor);
		
				grass = grass->back;
			}
		}
		else printf("> Nao ha valores\n");

		printf("\n");
		system("pause");
		system("cls");

		grass =  tree;

		printf("-> [DIREITA DA ARVORE]\n\n");

		if(tree->next != NULL)
		{
			while(grass != NULL)
			{
				if(grass->valor != tree->valor) printf("|Valor: %d|\n", grass->valor);
				grass = grass->next;
			}
		}
		else printf("> Nao ha valores\n");

		printf("\n");
		system("pause");
		system("cls");

		grass = tree;

		printf("-> [ABAIXO DA ARVORE]\n\n");

		if(tree->below != NULL)
		{
			while(grass != NULL)
			{
				if(grass->valor != tree->valor) printf("|Valor: %d|\n", grass->valor);
				grass = grass->below;
			}
		}
		else printf("> Nao ha valores\n");

		printf("\n");
	}
}

void pesquisarA()
{
	printf("\t---'Pesquisar Arvore'---\n\n");

	if(tree == NULL) printf("> Arvore vazia\n\n");
	else
	{
		int pesq;
		bool resultado = false;

		printf("|Digite um numero para a pesquisa: ");
		scanf("%d", &pesq);

		if(pesq == tree->valor)
		{
			printf("\n> O numero %d eh a raiz da arvore\n\n", pesq);
			return;
		} 

		grass = tree;

		while(grass != NULL)
		{
			if(grass->valor == pesq)
			{
				printf("\n> O numero %d existe a esquerda da arvore\n\n", pesq);
				resultado = true;
				break;
			}

			grass = grass->back;
		}

		if(resultado == false)
		{
			grass = tree;

			while(grass != NULL)
			{
				if(grass->valor == pesq)
				{
					printf("\n> O numero %d existe a direita da arvore\n\n", pesq);
					resultado = true;
					break;
				}

				grass = grass->next;
			}
		}

		if(resultado == false)
		{
			grass = tree;

			while(grass != NULL)
			{
				if(grass->valor == pesq)
				{
					printf("\n> O numero %d existe abaixo da arvore\n\n", pesq);
					resultado = true;
					break;
				}

				grass = grass->below;
			}
		}
		if(resultado == false) printf("\n> O numero %d nao exite na arvore\n\n", pesq);
	}
}

void arvores()
{
	chain = NULL; 
	helper = NULL;
	tree = NULL;
	grass = NULL;
	int operacao;

	do
	{
		printf("\t---'Menu Arvore'---\n\n");
		printf("[1] - Inserir\n");
		printf("[2] - Exibir\n");
		printf("[3] - Pesquisar\n");
		printf("[4] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				inserirA();
				system("pause");
				system("cls");
			break;

			case 2:
				exibirA();
				system("pause");
				system("cls");
			break;

			case 3:
				pesquisarA();
				system("pause");
				system("cls");

			break;

			case 4:
				return;
			break;

			default:
				printf("\t---'Menu Arvore'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 4);
}

void removerSimples()
{
	printf("\t---'Remover Simplesmente'---\n\n");
	if(simInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		bool achou = false;
		int op;

		printf("|Digite o numero a ser removido: ");
		scanf("%d", &op);
		
		if(simInicio->valor == op)
		{
			simCorrente = simInicio;
			simInicio = simInicio->next;
			free(simCorrente);
			achou = true;
		}
		else
		{
			simCorrente = simInicio;

			while(simCorrente != NULL)
			{
				if(simCorrente->valor == op)
				{
					achou = true;
					simAuxiliar->next = simCorrente->next;
					free(simCorrente);
					if(simAuxiliar->next != NULL)simCorrente = simAuxiliar->next;
					else break;	
				}
				simAuxiliar = simCorrente;
				simCorrente = simCorrente->next;
			}
		}
		if(!achou) printf("\n> O numero %d nao existe na lista\n\n");
		else printf("\n> O numero %d foi excluido com sucesso\n\n", op);
	}
}

void pesquisarSimples()
{
	printf("\t---'Pesquisar Simplesmente'---\n\n");

	if(simInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		bool achou = false;
		int op;

		printf("|Digite o numero a ser pesquisado: ");
		scanf("%d", &op);

		simCorrente = simInicio;

		while(simCorrente != NULL)
		{
			if(simCorrente->valor == op)
			{
				achou = true;
				printf("\n> O numero %d existe na lista\n\n", simCorrente->valor);
				break;
			}
			simCorrente = simCorrente->next;
		}

		if(!achou) printf("\n> O numero %d nao existe na lista\n\n", op);
	}
}

void exibirSimples()
{	
	printf("\t---'Exibir Simplesmente'---\n\n");

	if(simInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		simCorrente = simInicio;

		while(simCorrente != NULL)
		{
			printf("|Valor: %d\n", simCorrente->valor);
			simCorrente = simCorrente->next;
		}
	}
	printf("\n");
}

void inserirSimples()
{
	simCorrente = (simples*)malloc(sizeof(simples));

	printf("\t---'Inserir Simplesmente'---\n\n");

	enterdata();
	scanf("%d", &simCorrente->valor);

	if(simInicio == NULL)
	{
		simInicio = simCorrente;
		simAuxiliar = simCorrente;
	}	
	else
	{
		simAuxiliar->next = simCorrente;
		simAuxiliar = simCorrente;
	}

	simCorrente->next = NULL;

	printf("\n> O numero %d foi inserido na lista com sucesso\n\n", simCorrente->valor);
}

void removerDupla()
{
	printf("\t---'Remover Duplamente'---\n\n");

	if(duplaInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		int op;
		bool achou = false;
		printf("|Digite o numero a ser pesquisado: ");
		scanf("%d", &op);

		if(duplaInicio->valor == op)
		{
			achou = true;

			if(duplaInicio->next == NULL)
			{
				duplaCorrente = NULL;
				duplaAuxiliar = NULL;
				duplaInicio = NULL;
			}
			else
			{
				duplaCorrente = duplaInicio;
				duplaInicio = duplaInicio->next;
				duplaInicio->back = NULL;
				free(duplaCorrente);
			}
		}
		else if(end->valor == op)
		{
			achou = true;

			if(end->back == NULL)
			{
				duplaCorrente = NULL;
				duplaAuxiliar = NULL;
				duplaInicio = NULL;
			}
			else
			{
				duplaCorrente = end;
				end = end->back;
				end->next = NULL;
				free(duplaCorrente);
			}
		}
		else
		{
			duplaCorrente = duplaInicio;
			
			while(duplaCorrente != NULL)
			{
				if(duplaCorrente->valor == op)
				{	
					achou = true;
					duplaAuxiliar = duplaCorrente->next;
					duplaAuxiliar->back = duplaCorrente->back;
					duplaAuxiliar = duplaCorrente->back;
					duplaAuxiliar->next = duplaCorrente->next;

					free(duplaCorrente);
					duplaCorrente = duplaAuxiliar->next;
				}

				duplaAuxiliar = duplaCorrente;
				duplaCorrente = duplaCorrente->next;
			}
		}

		if(!achou) printf("\n> O numero %d nao existe na fila\n\n", op);
		else printf("\n> O numero %d foi excluido com sucesso\n\n", op);
	}
}

void pesquisarDupla()
{
	printf("\t---'Pesquisar Duplamente'---\n\n");

	if(duplaInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		int op;
		bool achou = false;
		printf("|Digite o numero a ser pesquisado: ");
		scanf("%d", &op);

		if(duplaInicio->valor == op)
		{
			achou = true;
			printf("\n> O numero %d existe no inicio da lista\n\n", op);
		}
		else if(end->valor == op)
		{
			achou = true;
			printf("\n> O numero %d existe no final da lista\n\n", op);
		}
		else
		{
			duplaCorrente = duplaInicio;

			while(duplaCorrente != NULL)
			{
				if(duplaCorrente->valor == op)
				{	
					achou = true;
					printf("\n> O numero %d existe no meio da lista\n\n", op);
					break;
				}

				duplaCorrente = duplaCorrente->next;
			}
		}

		if(!achou) printf("\n> O numero %d nao existe na fila\n\n", op);
	}
}

void exibirDupla()
{
	printf("\t---'Exibir Duplamente'---\n\n");

	if(duplaInicio == NULL) printf("> Lista vazia\n\n");
	else
	{
		printf("-> [NORMAL]:\n\n");

		duplaCorrente = duplaInicio;

		while(duplaCorrente != NULL)
		{
			printf("|Valor: %d|\n", duplaCorrente->valor);
			duplaCorrente = duplaCorrente->next;
		}

		printf("\n-> [AO CONTRARIO]:\n\n");

		duplaCorrente = end;

		while(duplaCorrente != NULL)
		{
			printf("|Valor: %d|\n", duplaCorrente->valor);
			duplaCorrente = duplaCorrente->back;
		}
		printf("\n");
	}
}

void inserirDupla()
{
	duplaCorrente = (duplamente*)malloc(sizeof(duplamente));

	printf("\t---'Inserir Duplamente'---\n\n");

	enterdata();
	scanf("%d", &duplaCorrente->valor);

	if(duplaInicio == NULL)
	{
		duplaInicio = duplaCorrente;
		duplaAuxiliar = duplaCorrente;
		duplaCorrente->next = NULL;
		duplaCorrente->back = NULL;
	}
	else
	{
		duplaCorrente->back = duplaAuxiliar;
		duplaAuxiliar->next = duplaCorrente;
		duplaAuxiliar = duplaCorrente;
	}

	end = duplaCorrente;
	duplaCorrente->next = NULL;

	printf("\n> O numero %d foi inserido com sucesso na lista\n\n", duplaCorrente->valor);
}

void duplamentes()
{
	duplaCorrente = NULL;
	duplaAuxiliar = NULL;
	duplaInicio = NULL;
	end = NULL;

	int operacao;

	do
	{
		printf("\t---'Menu Duplamente'---\n\n");
		printf("[1] - Inserir\n");
		printf("[2] - Exibir\n");
		printf("[3] - Pesquisar\n");
		printf("[4] - Remover\n");
		printf("[5] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				inserirDupla();
				system("pause");
				system("cls");
			break;

			case 2:
				exibirDupla();
				system("pause");
				system("cls");
			break;

			case 3:
				pesquisarDupla();
				system("pause");
				system("cls");
			break;

			case 4:
				removerDupla();
				system("pause");
				system("cls");
			break;

			case 5:
				return;
			break;

			default:
				printf("\t---'Menu Duplamente'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 5);
}

void simplesmente()
{
	simCorrente = NULL;
	simAuxiliar = NULL;
	simInicio = NULL;

	int operacao;

	do
	{
		printf("\t---'Menu Simplesmente'---\n\n");
		printf("[1] - Inserir\n");
		printf("[2] - Exibir\n");
		printf("[3] - Pesquisar\n");
		printf("[4] - Remover\n");
		printf("[5] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				inserirSimples();
				system("pause");
				system("cls");
			break;

			case 2:
				exibirSimples();
				system("pause");
				system("cls");
			break;

			case 3:
				pesquisarSimples();
				system("pause");
				system("cls");
			break;

			case 4:
				removerSimples();
				system("pause");
				system("cls");
			break;

			case 5:
				return;
			break;

			default:
				printf("\t---'Menu Simplesmente'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 5);
}

void listas()
{
	int operacao;

	do
	{
		printf("\t---'Menu Listas'---\n\n");
		printf("[1] - Simplesmente encadeada\n");
		printf("[2] - Duplamente encadeada\n");
		printf("[3] - Voltar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				simplesmente();
			break;

			case 2:
				duplamentes();
			break;

			case 3:
				return;
			break;

			default:
				printf("\t---'Menu Listas'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 3);
}

int main()
{
	int operacao;

	do
	{	
		printf("\t---'Escolha o tipo de estrutura'---\n\n");
		printf("[1] - Fila\n");
		printf("[2] - Pilha\n");
		printf("[3] - Arvore Binaria\n");
		printf("[4] - Arvore\n");
		printf("[5] - Listas\n");
		printf("[6] - Encerrar\n\n");
		printf("|: ");
		scanf("%d", &operacao);

		system("cls");

		switch(operacao)
		{
			case 1:
				filas();
			break;

			case 2:
				pilhas();
			break;

			case 3:
				arvoreBinarias();
			break;

			case 4:
				arvores();
			break;

			case 5:
				listas();
			break;
			
			case 6:

				printf("\t---'Escolha o tipo de estrutura'---\n\n");
				printf("> Programa encerrado\n\n");

			break;

			default:

				printf("\t---'Escolha o tipo de estrutura'---\n\n");
				printf("> Digite um numero valido\n\n");
				system("pause");
				system("cls");
		}
	}while(operacao != 6);
}