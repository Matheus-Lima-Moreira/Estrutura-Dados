// -------------------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCA��O DIN�MICA DE MEM�RIA 
// Ano/S: 2023/1S
// -------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------
// arquivos de cabe�alhos ('header')

// AMBIENTE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // usa para 'system' e para 'rand'
#include <time.h> // usa para inicializar o gerador rand�mico

// PR�PRIOS
#include "TYPES_DEFINES.h"

// -------------------------------------------------------------------------------------------
// fun��es e procedimentos

// procedimento para identificar o autor do trabalho
void exibe_dados_autor() {
	printf("\n");
	printf(" ------------------------------------\n");
  printf(" Disc.: IED-001 - ESTRUTURAS DE DADOS\n"); 
  printf(" Lab. : ALOCA��O DIN�MICA DE MEM�RIA \n"); 
	printf(" ------------------------------------\n");
	printf(" Autor: MATHEUS DE LIMA MOREIRA\n");
	printf(" R.A. : 121 048 221 2 016\n");
	printf(" Turma: ADS Tarde - 2023/1S\n");
	printf(" ------------------------------------\n");
	return; // desnecess�rio porque o procedimento � 'void'
}

// -------------------------------------------------------------------------------------------
// Atividade 1
// Aloca��o din�mica para 'int' e 'double'
#include "A1.c"

// -------------------------------------------------------------------------------------------
// Atividade 3
// Aloca��o din�mica de 'struct' com campos que tamb�m exigem aloca��o din�mica
#include "A3.c"

// --------------------------------------------------------------------------------------------
// programa principal
int main() {
	
	// para falar Portugu�s ...
	setlocale(LC_ALL,"Portuguese");
	
	// inicializa��o da 'semente' do gerador rand�mico
	srand(time(NULL));
	
	// declara��o de vari�veis
	int escolha; // op��o digitada pelo usu�rio
	int retorno; // retorno das fun��es acionadas
	
	// menu de escolha da Atividade a ser executada
	do {
		// apresenta��o do menu
		system("cls"); 
		printf("\n Menu de op��es:");
		printf("\n ---------------");
		printf("\n  1 - Atividade 1: Aloca��o din�mica de mem�ria para 'int' e 'double'");
		printf("\n  3 - Atividade 3: Aloca��o din�mica de 'struct' com campos que tamb�m exigem aloca��o din�mica");
		printf("\n  9 - Sair ...\n");
		
		// coleta da op��o desejada pelo usu�rio
		printf("\n Digite a op��o desejada: ");
		scanf ("%d",&escolha);
		
		// execu��o da a��o desejada
		switch ( escolha ) {
			case 1:
				printf(" Atividade 1 ...\n");

				// acionamento da Atividade 1
				retorno = atividade_1();

				// teste do resultado
				if ( retorno == ERRO ) {
					printf("\n ERRO na execu��o da ATIVIDADE 1 !  -  Verifique ...\n");
				} else {
					printf("\n ATIVIDADE 1 executada com SUCESSO !\n");
				}

				// identifica��o do autor do trabalho
				exibe_dados_autor();
				break;			
			case 3:
				printf(" Atividade 3 ...\n");

				// acionamento da Atividade 3
				retorno = atividade_3();

				// teste do resultado
				if ( retorno == ERRO ) {
					printf("\n ERRO na execu��o da ATIVIDADE 3 !  -  Verifique ...\n");
				} else {
					printf("\n ATIVIDADE 3 executada com SUCESSO !\n");
				}
				// identifica��o do autor do trabalho
				exibe_dados_autor();
				break;
			case 9:
				printf(" Sair !\n");
				break;
			default:
				printf(" Op��o inv�lida !\n");
				break;   // desnecess�rio neste caso				
		}
		printf("\n");
		system("pause");
		
	} while ( escolha != 9 );
		
	// finaliza��o
	return 0;
}