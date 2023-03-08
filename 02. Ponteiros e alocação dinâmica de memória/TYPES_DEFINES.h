// ------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCAÇÃO DINÂMICA DE MEMÓRIA
// Ano/S: 2023/1S
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Definições de Tipos e Constantes de uso geral

// definições de constantes
#define SUCESSO 0
#define ERRO -1
#define SIM 1
#define NAO 0

// definição (especificação ou explicação para o compilador) de 'struct' CLIENTE
typedef struct {
	int codigo;
	char status;
	double ticket;
	float *ultimas_compras;
} CLIENTE;
