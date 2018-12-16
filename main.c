#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//Declaração de macros
#define QUANT_NOTAS 5
#define QUANT_ITENS 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

//Declaração de funções
void cadastros();
void movimentacoes();
void consultas(int i);
void insercaoDeMercadorias();

//Declaração de variáveis globais
int gQuantidadeCliente = 0;
int gQuantidadeProdutos = 0;
int gQuantidadeNotas = 0;

//Declaração de estruturas
struct { //Estruturas para clientes
	int cod_cliente;
	char endereco[100];
	char telefone[100];
}clientes, lista_cliente[3];

struct itens_notas{ //Estruturas para itens das notas
	int numero_NF;
	int cod_produto;
	int quantidade;
	float preco_venda;
};

struct { //Estruturas para notas
	int numero_NF;
	int cod_cliente;
	float total_geral;
	struct itens_notas listaItensNotas[QUANT_ITENS];
} notas, lista_notas[QUANT_NOTAS];


struct { //Estruturas para cadastro de produtos
	int cod_produto;
	char descricao[100];
	char unidade[100];
	float preco_unitario;
	int quant_estoque;
} produtos, lista_produtos[6];

//Criação de funções
int main(void) { //Função principal
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	int pause = 0, op = 2;

	while(!pause) {
		switch(op) {
			//TODO: Chamar o menu de opções principais
			case 1://Função de cadastro
				cadastros();
			break;

			case 2: //Função de movimentação
				if(gQuantidadeNotas < 5) {
					if(!gQuantidadeNotas) {
						lista_notas[gQuantidadeNotas].numero_NF = rand() % 10000; //Gera um número de NF aleatorio para a primeira nota
					}else {
						lista_notas[gQuantidadeNotas].numero_NF = lista_notas[gQuantidadeNotas - 1].numero_NF + 15; //Fixa um número de NF para a nota baseado na última nota emitida
					}
					movimentacoes(); // Realiza a movimentação das notas
				}else {
					printf("\n\tNúmero máximo de notas atingido.\nNão permitido emitir novas notas\n");
				}
			break;

			case 3: //Função de consultas
				//TODO: Chamar a função de consultas
			break;
		}
		pause = 1;
	}

	return 0;
}

void cadastros() { //Função para cadastro
	int i, j, op, perms = 1;

	printf("\n========== Menu de Cadastros ==========\n");
	printf("|=====================================|\n");
	printf("|  Código     |        Operação       |\n");
	printf("|=====================================|\n");
	printf("|     01      |        Inclusão       |\n");
	printf("|     02      |        Alteração      |\n");
	printf("|     03      |        exclusão       |\n");
	printf("=======================================\n");
	
	printf("\n\nQual a opção desejada: ");
	scanf("%i", &op); setbuf(stdin, NULL);

	switch(op) {
		case 1: // Cadastro de cliente
			if(!gQuantidadeCliente) {
				lista_cliente[gQuantidadeCliente].cod_cliente = rand() % 10;
				printf("Informe o endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					gQuantidadeNotas++; //Incrementa o número de notas já emitidas
					printf("\n\tCliente cadastrado com sucesso!\n\n"); system("pause");
				system("cls");
			}else {
				lista_cliente[gQuantidadeCliente].cod_cliente = lista_cliente[gQuantidadeCliente].cod_cliente + 1;
				printf("Informe o endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					gQuantidadeNotas++; //Incrementa o número de notas já emitidas
					printf("\n\tCliente cadastrado com sucesso!\n\n"); system("pause");
				system("cls");
			}
			gQuantidadeCliente++;
		break;
		
		case 2: //Alteração de cliente
			if(!gQuantidadeCliente) {
				printf("\n\a\tNão existe nenhum cliente cadastrado até o momento!\n\n");
				system("pause");
			}else {
				printf("\n\t======= Clientes cadastrados =======\n");
				printf("\t====================================\n");
				for(i=0; i<gQuantidadeCliente; i++) {
					printf("\t\t| %02d | %d |\n", i, lista_cliente[i].cod_cliente);
				}
				printf("Informe qual cliente deseja alterar: ");
				scanf("%i", &i); setbuf(stdin, NULL);
				printf("Informe o novo endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o novo telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tAlteração realizada com sucesso\n\n");
					printf("=======================================\n"); system("pause");
				system("cls");
			}
		break;

		case 3: //Exclusão de cliente
			printf("\n\t======= Clientes cadastrados =======\n");
			printf("\t====================================\n");
			for(i=0; i<gQuantidadeCliente; i++) {
				printf("\t\t| %02d | %d |\n", i, lista_cliente[i].cod_cliente);
			}
			printf("Informe qual cliente deseja excluir: ");
			scanf("%i", &i); setbuf(stdin, NULL); system("cls");
			for(j=0; j<gQuantidadeNotas; j++) {
				if(lista_notas[j].cod_cliente == lista_cliente[i].cod_cliente) {
					printf("Não é possivel excluir o cliente, pois ele possui notas em seu nome.\n");
					perms = 0;
					break;
				}
			}
			if(perms == 1) {
				while(i < gQuantidadeCliente) {
					j = i+1;
					strcpy(lista_cliente[i].endereco, lista_cliente[j].endereco);
					strcpy(lista_cliente[i].telefone, lista_cliente[j].telefone);
					lista_cliente[i].cod_cliente = lista_cliente[j].cod_cliente;
					i++;
				}
			}
		break;
	}
}

void movimentacoes() { //Função para movimentação
	int i;
	printf("\n\t======= Clientes cadastrados =======\n");
	printf("\t====================================\n");
	for(i=0; i<gQuantidadeCliente; i++) {
		printf("\t\t| %02d | %d |\n", i, lista_cliente[i].cod_cliente);
	}
	printf("Informe o cliente que realizou essa compra: ");
	scanf("%i", &i); setbuf(stdin, NULL); system("cls");
	lista_notas[gQuantidadeNotas].cod_cliente = lista_cliente[i].cod_cliente;
	insercaoDeMercadorias();
}

void consultas(int i) { //Função para consultas

	printf("\n========== Menu de Consultas =============\n");
	printf("|==========================================|\n");
	printf("|    Código   |           Operação         |\n");
	printf("|==========================================|\n");
	printf("|     01      |      Pesquisa por preço    |\n");
	printf("|     02      |     Pesquisa por cliente   |\n");
	printf("|     03      | Pesquisa por valor da nota |\n");
	printf("============================================\n");
}

void insercaoDeMercadorias() {
	int resp = 0, op = 0, key, i, j = 0;
	while(!resp &&  j < 2) {
		printf("\n\t======= Produtos cadastrados =======\n");
		printf("\t====================================\n");
		for(i=0; i<gQuantidadeProdutos; i++) {
			printf("\t\t| %02d | %d |\n", i, lista_produtos[i].cod_produto);
		}
		printf("Informe qual produto foi comprado: ");
		scanf("%i", &i); setbuf(stdin, NULL); system("cls");
		if(i >= 0 && i < gQuantidadeProdutos) {
			lista_notas[gQuantidadeNotas].listaItensNotas[j].cod_produto = lista_produtos[i].cod_produto;
			lista_notas[gQuantidadeNotas].listaItensNotas[j].numero_NF = lista_notas[gQuantidadeNotas].numero_NF;
			printf("\tQuantidade do produto: ");
			scanf("%i", &lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade); setbuf(stdin, NULL); system("cls");
			if(j == 0) {
				if(lista_produtos[i].quant_estoque >= lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade) {
					lista_produtos[i].quant_estoque -= lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade;
				}else {
					lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade = lista_produtos[i].quant_estoque;
					lista_produtos[i].quant_estoque = 0;
				}
				while(j == 0 && !resp) {
					system("cls");
					printf("Esse cliente comprou mais algum produto?\n");
			  		printf("\n%s SIM\n", (op == 0) ? "->" : " ");
					printf("%s NÃO\n", (op == 1) ? "->" : " ");
					key = getch();
					if(key == KEY_UP && op > 0) {
						op--;
					}else if(key == KEY_DOWN && op < 1) {
						op++;
					}else if(key == KEY_ESC) {
						resp = 1;
					}else if(key == KEY_ENTER) {
						j++;
						resp = op;
					}
					system("cls");
				}
			}else if(j==1){
				if(lista_notas[gQuantidadeNotas].listaItensNotas[j].cod_produto == lista_notas[gQuantidadeNotas].listaItensNotas[j-1].cod_produto){
					printf("\n\tProduto já cadastrado na nota.\n\tPor favor informe um produto diferente\n");
					system("pause");
				}else {
					if(lista_produtos[i].quant_estoque >= lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade) {
						lista_produtos[i].quant_estoque -= lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade;
					}else {
						lista_notas[gQuantidadeNotas].listaItensNotas[j].quantidade = lista_produtos[i].quant_estoque;
						lista_produtos[i].quant_estoque = 0;
					}
					j++;
				}
			}
		}else {
			printf("\n\tErro: Produto não reconhecido\n");
		}
	}
}
