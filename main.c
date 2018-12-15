#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//Declara��o de macros
#define QUANT_NOTAS 10
#define QUANT_ITENS 6

//Declara��o de fun��es
void cadastros();

//Declara��o de vari�veis globais
int gQuantidadeCliente = 0;

//Declara��o de estruturas
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

//Cria��o de fun��es
int main(void) { //Fun��o principal
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	int pause = 0, op;

	while(!pause) {
		switch(op) {
			//TODO: Chamar o menu de op��es principais
			case 1://Fun��o de cadastro
				//TODO: Chamar a fun��o de cadastro
			break;

			case 2: //Fun��o de movimenta��o
				//TODO: Chamar a fun��o de movimenta��o
			break;

			case 3: //Fun��o de consultas
				//TODO: Chamar a fun��o de consultas
			break;
		}
	}

	return 0;
}

void cadastros() { //Fun��o para cadastro
	int j, op;

	printf("\n========== Menu de Cadastros ==========\n");
	printf("|=====================================|\n");
	printf("|  C�digo     |        Opera��o       |\n");
	printf("|=====================================|\n");
	printf("|     01      |        Inclus�o       |\n");
	printf("|     02      |        Altera��o      |\n");
	printf("|     03      |        exclus�o       |\n");
	printf("=======================================\n");

	switch(op) {
		case 1:
			if(!gQuantidadeCliente) {
				lista_cliente[gQuantidadeCliente].cod_cliente = rand() % 10;
				printf("Informe o endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
			}else {
				lista_cliente[gQuantidadeCliente].cod_cliente = lista_cliente[gQuantidadeCliente].cod_cliente + 1;
				printf("Informe o endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
			}
			gQuantidadeCliente++;
		break;
		
		case 2:
			if(!gQuantidadeCliente) {
				printf("\n\a\tN�o existe nenhum cliente cadastrado at� o momento!\n");
				system("pause");
			}else {
				printf("\n\t======= Clientes cadastrados =======\n");
				printf("\t====================================\n");
				for(j=0; j<gQuantidadeCliente; j++) {
					printf("\t\t| 0%i | %d |\n", j);
				}
				printf("Informe qual cliente deseja alterar: ");
				scanf("%i", &j); setbuf(stdin, NULL);
				printf("Informe o novo endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o novo telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tAltera��o realizada com sucesso\n");
					printf("=======================================\n"); system("pause");
				system("cls");
			}
		break;
	}
}

void movimentacoes(int i) { //Fun��o para movimenta��o

}

void consultas(int i) { //Fun��o para consultas

}
