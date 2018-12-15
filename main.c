#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//Declara��o de macros
#define QUANT_NOTAS 5
#define QUANT_ITENS 2
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

//Declara��o de fun��es
void cadastros();
void movimentacoes();
void consultas(int i);
void insercaoDeMercadorias();

//Declara��o de vari�veis globais
int gQuantidadeCliente = 0;
int gQuantidadeProdutos = 0;
int gQuantidadeNotas = 0;

//Declara��o de estruturas
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

//Cria��o de fun��es
int main(void) { //Fun��o principal
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	int pause = 0, op = 2;

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
		pause = 1;
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
	
	printf("\n\nQual a op��o desejada: ");
	scanf("%i", &op); setbuf(stdin, NULL);

	switch(op) {
		case 1: // Cadastro de cliente
			if(!gQuantidadeCliente) {
				lista_cliente[gQuantidadeCliente].cod_cliente = rand() % 10;
				printf("Informe o endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tCliente cadastrado com sucesso!\n\n"); system("pause");
				system("cls");
			}else {
				lista_cliente[gQuantidadeCliente].cod_cliente = lista_cliente[gQuantidadeCliente].cod_cliente + 1;
				printf("Informe o endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tCliente cadastrado com sucesso!\n\n"); system("pause");
				system("cls");
			}
			gQuantidadeCliente++;
		break;
		
		case 2: //Altera��o de cliente
			if(!gQuantidadeCliente) {
				printf("\n\a\tN�o existe nenhum cliente cadastrado at� o momento!\n\n");
				system("pause");
			}else {
				printf("\n\t======= Clientes cadastrados =======\n");
				printf("\t====================================\n");
				for(j=0; j<gQuantidadeCliente; j++) {
					printf("\t\t| %02d | %d |\n", j, lista_cliente[j].cod_cliente);
				}
				printf("Informe qual cliente deseja alterar: ");
				scanf("%i", &j); setbuf(stdin, NULL);
				printf("Informe o novo endere�o do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o novo telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
					printf("\n\tAltera��o realizada com sucesso\n\n");
					printf("=======================================\n"); system("pause");
				system("cls");
			}
		break;

		case 3: //Exclus�o de cliente
			//TODO: Exlcuir cliente que n�o possui nota fiscal registrada
		break;
	}
}

void movimentacoes() { //Fun��o para movimenta��o
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

void consultas(int i) { //Fun��o para consultas

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
		lista_notas[gQuantidadeNotas].listaItensNotas[j].cod_produto = lista_produtos[i].cod_produto;
		lista_notas[gQuantidadeNotas].listaItensNotas[j].numero_NF = lista_notas[gQuantidadeNotas].numero_NF;
		if(j == 0) {
			while(j == 0 && !resp) {
				system("cls");
				printf("Esse cliente comprou mais algum produto?\n");
		  		printf("\n%s SIM\n", (op == 0) ? "->" : " ");
				printf("%s N�O\n", (op == 1) ? "->" : " ");
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
				printf("\n\tProduto j� cadastrado na nota.\n\tPor favor informe um produto diferente\n");
				system("pause");
			}else {
				j++;
			}
		}
	}
}
