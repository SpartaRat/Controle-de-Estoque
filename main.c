#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//Declaração de macros
#define QUANT_NOTAS 10
#define QUANT_ITENS 6

//Declaração de funções
void cadastros();

//Declaração de variáveis globais
int gQuantidadeCliente = 0;

//Declaração de estruturas
struct { //Estruturas para clientes
	int cod_cliente;
	char endereco[100];
	char telefone[100];
}clientes, lista_cliente[3];

struct { //Estruturas para notas
	int numero_NF;
	int cod_cliente;
	float total_geral;
} notas, lista_notas[QUANT_NOTAS];

struct { //Estruturas para itens das notas
	int numero_NF;
	int cod_produto;
	int quantidade;
	float preco_venda;
} itens_notas, lista_itens_notas[QUANT_ITENS];

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

	int pause = 0, op;

	while(!pause) {
		switch(op) {
			//TODO: Chamar o menu de opções principais
			case 1://Função de cadastro
				//TODO: Chamar a função de cadastro
			break;

			case 2: //Função de movimentação
				//TODO: Chamar a função de movimentação
			break;

			case 3: //Função de consultas
				//TODO: Chamar a função de consultas
			break;
		}
	}

	return 0;
}

void cadastros() { //Função para cadastro
	int j, op;

	printf("\n========== Menu de Cadastros ==========\n");
	printf("|=====================================|\n");
	printf("|  Código     |        Operação       |\n");
	printf("|=====================================|\n");
	printf("|     01      |        Inclusão       |\n");
	printf("|     02      |        Alteração      |\n");
	printf("|     03      |        exclusão       |\n");
	printf("=======================================\n");

	switch(op) {
		case 1:
			if(!gQuantidadeCliente) {
				lista_cliente[gQuantidadeCliente].cod_cliente = rand() % 10;
				printf("Informe o endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
			}else {
				lista_cliente[gQuantidadeCliente].cod_cliente = lista_cliente[gQuantidadeCliente].cod_cliente + 1;
				printf("Informe o endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
			}
			gQuantidadeCliente++;
		break;
		
		case 2:
			if(!gQuantidadeCliente) {
				printf("\n\a\tNão existe nenhum cliente cadastrado até o momento!\n");
				system("pause");
			}else {
				printf("\n\t======= Clientes cadastrados =======\n");
				printf("\t====================================\n");
				for(j=0; j<gQuantidadeCliente; j++) {
					printf("\t\t| 0%i | %d |\n", j);
				}
				printf("Informe qual cliente deseja alterar: ");
				scanf("%i", &j); setbuf(stdin, NULL);
				printf("Informe o novo endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o novo telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tAlteração realizada com sucesso\n");
					printf("=======================================\n"); system("pause");
				system("cls");
			}
		break;
	}
}

void movimentacoes(int i) { //Função para movimentação

}

void consultas(int i) { //Função para consultas

}
