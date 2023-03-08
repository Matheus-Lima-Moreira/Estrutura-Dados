// ----------------------------------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCA��O DIN�MICA DE MEM�RIA
// Ano/S: 2023/1S
// ----------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------
// Atividade 1
// Aloca��o din�mica para 'int' e 'double'

int atividade_1() {
	
	printf("\n -----------------");
	printf("\n ALOCA��O DIN�MICA");
	printf("\n -----------------\n");
	
	// declara��o de vari�vel auxiliar para percursos 'for'
	int k;

	// --------------------------------------------------------------------------------------------------------
	// PARTE 1 - INT - MEM�RIA HEAP
			
	// aloca��o din�mica para 'int'
	int * i_ptr;  // armazenar� o endere�o inicial da mem�ria alocada dinamicamente
	int   i_qtd;  // armazenar� a qtd de 'int' necess�ria (lido do teclado)
	
	// descobre quantos 'int' s�o necess�rios
	printf("\n Informe a qtd de INT que voc� quer alocar: ");
	scanf("%d",&i_qtd);
	
	// aloca mem�ria dinamicamente, informando quantos BYTES s�o necess�rios
	// dependendo do compilador, o 'casting' (convers�o de tipo do ponteiro) � opcional
	i_ptr = (int *) malloc( i_qtd * sizeof(int) );
	
	// teste para saber se aloca��o din�mica falhou
	if ( i_ptr == NULL ) {
		printf("\n\n ERRO na ALOCA��O DIN�MICA de int !!\n\n");
		return ERRO; // ERRO est� definido em TYPES_DEFINES.h
	}
	
	// preenche a �rea dinamicamente alocada com n�meros aleat�rios entre 0 e 99
	for ( k = 0; k < i_qtd; k++ ) {
		i_ptr[k] = rand()%100; // i_ptr[k] � o mesmo que *(i_ptr + k)
	}
	
	// impress�es
	printf("\n");
	printf(" Mem�ria STACK\n");
	printf(" -------------\n");
	printf(" i_qtd (int)   - endere�o #%p - qtd bytes %d - conte�do %3d\n", &i_qtd, sizeof(i_qtd), i_qtd);
	printf(" i_ptr (int *) - endere�o #%p - qtd bytes %d - conte�do #%p\n", &i_ptr, sizeof(i_ptr), i_ptr);
	
	printf("\n");
	printf(" Mem�ria HEAP\n");
	printf(" ------------\n");
	for ( k = 0; k < i_qtd; k++ ) {
		printf(" i_ptr[%d] (int) - endere�o #%p - qtd bytes %d - conte�do %3d\n", k, &(i_ptr[k]), sizeof(i_ptr[k]), i_ptr[k]);
	}
	printf(" ------------\n");
	
	// libera a mem�ria alocada -> colocado no final deste c�digo
	//free( i_ptr );
	
	// FIM DA PARTE 1 - INT
	// --------------------
	
	// PARTE 2 - DOUBLE - MEM�RIA HEAP
	// -------------------------------
	
	// aloca��o din�mica para 'double'
	double * d_ptr;  // armazenar� o endere�o inicial da mem�ria alocada dinamicamente
	int      d_qtd;  // armazenar� a qtd de 'double' necess�ria (lido do teclado)
	
	// descobre quantos 'double' s�o necess�rios
	printf("\n Informe a qtd de DOUBLE que voc� quer alocar: ");
	scanf("%d",&d_qtd);
	
	// aloca mem�ria dinamicamente, informando quantos BYTES s�o necess�rios
	// dependendo do compilador, o 'casting' (convers�o de tipo do ponteiro) � opcional
	d_ptr = (double *) malloc( d_qtd * sizeof(double) );
	
	// teste para saber se aloca��o din�mica falhou
	if ( d_ptr == NULL ) {
		printf("\n\n ERRO na ALOCA��O DIN�MICA de double !!\n\n");
		return ERRO;  // ERRO est� definido em TYPES_DEFINES.h
	}
	
	// preenche a �rea dinamicamente alocada com n�meros aleat�rios entre 0 e 0.999
	for ( k = 0; k < d_qtd; k++ ) {
		d_ptr[k] = (double) (rand()%1000)/1000.0;   // d_ptr[k] � o mesmo que *(d_ptr + k)
	}
	
	// impress�es
	printf("\n");
	printf(" Mem�ria STACK\n");
	printf(" -------------\n");
	printf(" d_qtd (int)      - endere�o #%p - qtd bytes %d - conte�do %3d\n", &d_qtd, sizeof(d_qtd), d_qtd);
	printf(" d_ptr (double *) - endere�o #%p - qtd bytes %d - conte�do #%p\n", &d_ptr, sizeof(d_ptr), d_ptr);
	
	printf("\n");
	printf(" Mem�ria HEAP\n");
	printf(" ------------\n");
	for ( k = 0; k < d_qtd; k++ ) {
		printf(" d_ptr[%d] (double) - endere�o #%p - qtd bytes %d - conte�do %5.3f\n", k, &(d_ptr[k]), sizeof(d_ptr[k]), d_ptr[k]);
	}
	printf(" ------------\n");
	
	// libera a mem�ria alocada -> colocado no final deste c�digo
	//free( d_ptr );
	
	// FIM DA PARTE 2 - DOUBLE
	// -----------------------

	// libera a mem�ria alocada (recomendado: ordem inversa � da aloca��o)
	free( d_ptr );
	free( i_ptr );	
	
	// finaliza��o
	return SUCESSO;  // SUCESSO est� definido em TYPES_DEFINES.h
}