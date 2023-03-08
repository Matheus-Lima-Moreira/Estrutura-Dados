// -------------------------------------------------
// Disc.: ESTRUTURAS DE DADOS - IED-001
// Lab. : STRUCTS, ARQUIVOS-TEXTO, ARQUIVOS BINÁRIOS
// Ano/S: 2023/1S
// -------------------------------------------------

// Definições de Tipos e Constantes de uso geral
// ---------------------------------------------

// definição de constantes
#define SIM 1
#define NAO 0
#define ERRO -1

// definição (especificação ou explicação para o compilador) de 'struct' CLIENTE
typedef struct
{
	int codigo;
	char status;
	double renda;
} CLIENTE;