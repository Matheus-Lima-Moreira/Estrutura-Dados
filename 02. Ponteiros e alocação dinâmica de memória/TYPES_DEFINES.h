// ------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCA��O DIN�MICA DE MEM�RIA
// Ano/S: 2023/1S
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Defini��es de Tipos e Constantes de uso geral

// defini��es de constantes
#define SUCESSO 0
#define ERRO -1
#define SIM 1
#define NAO 0

// defini��o (especifica��o ou explica��o para o compilador) de 'struct' CLIENTE
typedef struct {
	int codigo;
	char status;
	double ticket;
	float *ultimas_compras;
} CLIENTE;
