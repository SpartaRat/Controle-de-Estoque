#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include<time.h>
#include<conio.h>

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
void consultas();
void insercaoDeMercadorias();
int menuPrincipal();
void cadastroProduto();

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
	int quantidadeItensNota;
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
		op = menuPrincipal();
		switch(op) {
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
				consultas();
			break;

			case 4:
				if(gQuantidadeProdutos < 6){
					cadastroProduto();
				}else {
					printf("\a\n\tNão é possivel cadastrar mais produtos!\n");
				}
			break;
			
			case 5:
				pause = 1;
				printf("\n\tPrograma finalizado com sucesso...\n\n");
			break;

			default:
				printf("\a\n\t\tOpção Inválida...\n");
		}
		printf("\t");
		system("pause");
		system("cls");
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
				printf("\n\tCliente cadastrado com sucesso!\n\n");
				gQuantidadeCliente++;
			}else if(gQuantidadeCliente < 3 && gQuantidadeCliente != 0){
				lista_cliente[gQuantidadeCliente].cod_cliente = lista_cliente[gQuantidadeCliente - 1].cod_cliente + 3;
				printf("Informe o endereço do cliente: ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].endereco); setbuf(stdin, NULL);
				printf("Informe o telefone do cliente((dd) 9xxxx-xxxx): ");
				scanf("%[^\n]s", lista_cliente[gQuantidadeCliente].telefone); setbuf(stdin, NULL);
				system("cls");
				printf("\n\tCliente cadastrado com sucesso!\n\n");
				gQuantidadeCliente++;
			}else {
				printf("\a\n\tLimite máximo de cadastro atingido!\n\n");
			}
		break;
		
		case 2: //Alteração de cliente
			if(!gQuantidadeCliente) {
				printf("\n\a\tNão existe nenhum cliente cadastrado até o momento!\n\n");
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
				printf("=======================================\n");
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
					gQuantidadeCliente--;
				}
			}
		break;
	}
}

void cadastroProduto() {
	system("cls");
	if(!gQuantidadeProdutos) {
		lista_produtos[gQuantidadeProdutos].cod_produto = rand() % 10000;
	}else {
		lista_produtos[gQuantidadeProdutos].cod_produto = lista_produtos[gQuantidadeProdutos-1].cod_produto + 10;
	}
	printf("Faça uma pequena descrição desse produto: ");
	scanf("%[^\n]s", lista_produtos[gQuantidadeProdutos].descricao); setbuf(stdin, NULL);
	printf("Informe a unidade: ");
	scanf("%[^\n]s", lista_produtos[gQuantidadeProdutos].unidade); setbuf(stdin, NULL);
	printf("Informe o preço unitário: ");
	scanf("%f", &lista_produtos[gQuantidadeProdutos].preco_unitario); setbuf(stdin, NULL);
	printf("Informe a quantidade em estoque: ");
	scanf("%i", &lista_produtos[gQuantidadeProdutos].quant_estoque); setbuf(stdin, NULL);
 	gQuantidadeProdutos++;
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

void consultas() { //Função para consultas
	int operacao = 1, i, j, k, found = 0, key;
	float min, max, totalNota = 0, valor;

	while(1) {
		system("cls");
		printf("\nInfome a opção desejada:\n");
		printf("\n========== Menu de Consultas ===============\n");
		printf("|==========================================|\n");
		printf("|    Código   |           Operação         |\n");
		printf("|==========================================|\n");
		printf("|     %s      |      Pesquisa por preço    |\n", (operacao == 1) ? "->" : "01");
		printf("|     %s      |     Pesquisa por cliente   |\n", (operacao == 2) ? "->" : "02");
		printf("|     %s      | Pesquisa por valor da nota |\n", (operacao == 3) ? "->" : "03");
		printf("|     %s      | Voltar para menu principal |\n", (operacao == 4) ? "->" : "04");
		printf("============================================\n");
 		key = getch();
		if(key == KEY_UP && operacao > 1) {
			operacao--;
		}else if(key == KEY_DOWN && operacao < 4) {
			operacao++;
		}else if(key == KEY_ESC) {
			break;
		}else if(key == KEY_ENTER) {
			break;
		}
	}
	
	switch(operacao) {
		case 1: //Pesquisa por faixa de preço
			if(gQuantidadeProdutos) {
				printf("\tInforme uma faixa de preço para consulta: ");
				printf("Preço minimo: ");
				scanf("%f", &min); setbuf(stdin, NULL);
				printf("Preço máximo: ");
				scanf("%f", &max); setbuf(stdin, NULL);
				for(i=0; i<gQuantidadeProdutos; i++) {
					if(lista_produtos[i].preco_unitario >= min && lista_produtos[i].preco_unitario <= max) {
						found = 1;
						printf("| Código do produto: %d | Quantidade em estoque: %d | Preço unitário: R$%.2f\n", lista_produtos[i].cod_produto, lista_produtos[i].quant_estoque, lista_produtos[i].preco_unitario);
					}
				}
				if(!found) {
					printf("\a\tNão foi encontrado nenhum produto dentro dessa faixa de preço\n");
				}
			}else {
				printf("\n\tNão existe nenhum produto registrado...\n");
			}
		break;
		
		case 2: //Pesquisa por cliente
			if(gQuantidadeCliente && gQuantidadeNotas) {
				printf("\n\t======= Clientes cadastrados =======\n");
				printf("\t====================================\n");
				for(i=0; i<gQuantidadeCliente; i++) {
					printf("\t\t| %02d | %d |\n", i, lista_cliente[i].cod_cliente);
				}
				printf("\t====================================\n");
				printf("Informe o cliente que deseja ver os dados: ");
				scanf("%i", &i); setbuf(stdin, NULL); system("cls");
				for(j=0; j<gQuantidadeNotas; j++) {
					if(lista_notas[j].cod_cliente == lista_cliente[i].cod_cliente) {
						found = 1;
						printf("\n========= Nota fiscal: %d ===========\n", lista_notas[j].numero_NF);
						printf("\tItens da nota: \n");
						for(k=0; k<lista_notas[j].quantidadeItensNota; k++) {
							printf("\t| Código: %d | Preço de venda: R$%.2f reais | Quantidade: %d\n", lista_notas[j].listaItensNotas[k].cod_produto, lista_notas[j].listaItensNotas[k].preco_venda, lista_notas[j].listaItensNotas[k].quantidade);
							totalNota += (lista_notas[j].listaItensNotas[k].preco_venda * lista_notas[j].listaItensNotas[k].quantidade);
						}
						printf("Valor total: R$%.2f reais\n", totalNota);
						printf("=======================================\n\n");
					}
				}
				if(!found) {
					printf("\nNão foi encontrado nenhuma nota no nome do cliente selecionado...\n");
				}else {
					found = 0;
				}
			}else {
				printf("\n\tNão existe nenhum cliente cadastro...\n");
			}
		break;
		
		case 3: //Pesquisa por valor da nota
			if(gQuantidadeNotas) {
				printf("Informe um valor para consulta de notas: ");
				scanf("%f", &valor); setbuf(stdin, NULL); system("cls");
				for(i=0; i<gQuantidadeNotas; i++) {
					for(j=0; j<lista_notas[i].quantidadeItensNota; j++) {
						totalNota += (lista_notas[i].listaItensNotas[j].preco_venda * lista_notas[i].listaItensNotas[j].quantidade);
					}
					if(totalNota > valor) {
						printf("\n========= Nota fiscal: %d ===========\n", lista_notas[i].numero_NF);
						printf("\tItens da nota: \n");
						for(j=0; j<lista_notas[i].quantidadeItensNota; j++) {
							printf("\t| Código: %d | Preço de venda: R$%.2f reais | Quantidade: %d\n", lista_notas[i].listaItensNotas[j].cod_produto, lista_notas[i].listaItensNotas[j].preco_venda, lista_notas[i].listaItensNotas[j].quantidade);
						}
						printf("Valor total: R$%.2f reais\n", totalNota);
						printf("=======================================\n");
					}
					totalNota = 0;
				}
			}else {
				printf("\n\tNão existe nenhuma nota cadastrada...\n");
			}
		break;
		
		case 4:
			system("cls");
		break;
		
		default:
			printf("\a\tOpção Inválida\n");
			system("pause");
	}
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
			lista_notas[gQuantidadeNotas].quantidadeItensNota = j;
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
						lista_notas[gQuantidadeNotas].quantidadeItensNota = j;
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
					lista_notas[gQuantidadeNotas].quantidadeItensNota = j;
				}
			}
		}else {
			printf("\n\tErro: Produto não reconhecido\n");
		}
	}
	gQuantidadeNotas++;
}

int menuPrincipal() {
	int op = 1, key, resp;
	while(1) {
		system("cls");
		printf("\nInforme a opção desejada:\n");
		printf("\n========== Menu de Cadastros ==========\n");
		printf("|=====================================|\n");
		printf("|  Código     |        Operação       |\n");
		printf("|=====================================|\n");
		printf("|     %s      |        Cadastro       |\n", (op == 1) ? "->" : "01");
		printf("|     %s      |      Movimentação     |\n", (op == 2) ? "->" : "02");
		printf("|     %s      |        Consulta       |\n", (op == 3) ? "->" : "03");
		printf("|     %s      |    Cadastro Produto   |\n", (op == 4) ? "->" : "04");
		printf("|     %s      |          Sair         |\n", (op == 5) ? "->" : "05");
		printf("=======================================\n");
		key = getch();
		if(key == KEY_UP && op > 1) {
			op--;
		}else if(key == KEY_DOWN && op < 5) {
			op++;
		}else if(key == KEY_ESC) {
			system("cls");
			return 5;
		}else if(key == KEY_ENTER) {
			resp = op;
			system("cls");
			return resp;
		}
	}
}
