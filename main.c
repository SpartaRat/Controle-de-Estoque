#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//Declaração de macros
#define QUANT_NOTAS 10
#define QUANT_ITENS 6

//Declaração de funções
void cadastro(int i);

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
	setlocale(LC_ALL,"portugues");

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

void cadastro(int i) { //Função para cadastro

}

void movimentacao(int i) { //Função para movimentação

}

void consultas(int i) { //Função para consultas

}
