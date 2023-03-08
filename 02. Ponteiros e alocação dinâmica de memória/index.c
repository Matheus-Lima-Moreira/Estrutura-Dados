// -------------------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCAÇÃO DINÂMICA DE MEMÓRIA 
// Ano/S: 2023/1S
// -------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------
// arquivos de cabeçalhos ('header')

// AMBIENTE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // usa para 'system' e para 'rand'
#include <time.h> // usa para inicializar o gerador randômico

// PRÓPRIOS
#include "TYPES_DEFINES.h"

// -------------------------------------------------------------------------------------------
// funções e procedimentos

// procedimento para identificar o autor do trabalho
void exibe_dados_autor() {
	printf("\n");
	printf(" ------------------------------------\n");
  printf(" Disc.: IED-001 - ESTRUTURAS DE DADOS\n"); 
  printf(" Lab. : ALOCAÇÃO DINÂMICA DE MEMÓRIA \n"); 
	printf(" ------------------------------------\n");
	printf(" Autor: MATHEUS DE LIMA MOREIRA\n");
	printf(" R.A. : 121 048 221 2 016\n");
	printf(" Turma: ADS Tarde - 2023/1S\n");
	printf(" ------------------------------------\n");
	return; // desnecessário porque o procedimento é 'void'
}

// -------------------------------------------------------------------------------------------
// Atividade 1
// Alocação dinâmica para 'int' e 'double'
#include "A1.c"

// -------------------------------------------------------------------------------------------
// Atividade 3
// Alocação dinâmica de 'struct' com campos que também exigem alocação dinâmica
#include "A3.c"

// --------------------------------------------------------------------------------------------
// programa principal
int main() {
	
	// para falar Português ...
	setlocale(LC_ALL,"Portuguese");
	
	// inicialização da 'semente' do gerador randômico
	srand(time(NULL));
	
	// declaração de variáveis
	int escolha; // opção digitada pelo usuário
	int retorno; // retorno das funções acionadas
	
	// menu de escolha da Atividade a ser executada
	do {
		// apresentação do menu
		system("cls"); 
		printf("\n Menu de opções:");
		printf("\n ---------------");
		printf("\n  1 - Atividade 1: Alocação dinâmica de memória para 'int' e 'double'");
		printf("\n  3 - Atividade 3: Alocação dinâmica de 'struct' com campos que também exigem alocação dinâmica");
		printf("\n  9 - Sair ...\n");
		
		// coleta da opção desejada pelo usuário
		printf("\n Digite a opção desejada: ");
		scanf ("%d",&escolha);
		
		// execução da ação desejada
		switch ( escolha ) {
			case 1:
				printf(" Atividade 1 ...\n");

				// acionamento da Atividade 1
				retorno = atividade_1();

				// teste do resultado
				if ( retorno == ERRO ) {
					printf("\n ERRO na execução da ATIVIDADE 1 !  -  Verifique ...\n");
				} else {
					printf("\n ATIVIDADE 1 executada com SUCESSO !\n");
				}

				// identificação do autor do trabalho
				exibe_dados_autor();
				break;			
			case 3:
				printf(" Atividade 3 ...\n");

				// acionamento da Atividade 3
				retorno = atividade_3();

				// teste do resultado
				if ( retorno == ERRO ) {
					printf("\n ERRO na execução da ATIVIDADE 3 !  -  Verifique ...\n");
				} else {
					printf("\n ATIVIDADE 3 executada com SUCESSO !\n");
				}
				// identificação do autor do trabalho
				exibe_dados_autor();
				break;
			case 9:
				printf(" Sair !\n");
				break;
			default:
				printf(" Opção inválida !\n");
				break;   // desnecessário neste caso				
		}
		printf("\n");
		system("pause");
		
	} while ( escolha != 9 );
		
	// finalização
	return 0;
}