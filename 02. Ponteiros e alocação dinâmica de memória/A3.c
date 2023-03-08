// ------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCA��O DIN�MICA DE MEM�RIA
// Ano/S: 2023/1S
// ------------------------------------

// Atividade 3
// Aloca��o din�mica de 'struct' com campos que tamb�m exigem aloca��o din�mica
// ----------------------------------------------------------------------------

int atividade_3() {
	
	// defini��o do tipo CLIENTE -> j� feita em TYPES_DEFINES.h
	/*
	typedef struct {
		int     codigo;
		char    status;
		double  ticket;
		float * ultimas_compras;
	} CLIENTE;
	*/
	
	// declara��o de vari�veis
	CLIENTE * cli_ptr;
	int k, i;  // auxiliares de percurso 'for'
	
	// aloca��o din�mica de DOIS CLIENTEs (com 'casting')
	cli_ptr = (CLIENTE *) malloc( 2 * sizeof(CLIENTE) );
	
	// teste para saber se aloca��o din�mica falhou
	if ( cli_ptr == NULL ) {
		printf("\n\n ERRO na ALOCA��O DIN�MICA de CLIENTE !!\n\n");
		return ERRO;  // ERRO est� definido em TYPES_DEFINES.h
	}
	
	// atribui��es de valores aos campos dos CLIENTEs
	cli_ptr[0].codigo = 1;
	cli_ptr[0].status = 'A';
	cli_ptr[0].ticket = 1000.0;
	cli_ptr[0].ultimas_compras = (float *) malloc( 6 * sizeof(float) );
  
	// teste para saber se aloca��o din�mica falhou
	if ( cli_ptr[0].ultimas_compras == NULL ) {
		printf("\n\n ERRO na ALOCA��O DIN�MICA de ultimas_compras do CLIENTE 0 !!\n\n");
		return ERRO;  // ERRO est� definido em TYPES_DEFINES.h
	}
	
	// preenche a �rea dinamicamente alocada com n�meros aleat�rios entre 100 e 499
	for ( k = 0; k < 6; k++ ) {
		cli_ptr[0].ultimas_compras[k] = 100 + rand()%400;
	}
	
	cli_ptr[1].codigo = 2;
	cli_ptr[1].status = 'B';
	cli_ptr[1].ticket  = 2000.0;
	cli_ptr[1].ultimas_compras = (float *) malloc( 6 * sizeof(float) );
	// teste para saber se aloca��o din�mica falhou
	if ( cli_ptr[1].ultimas_compras == NULL ) {
		printf("\n\n ERRO na ALOCA��O DIN�MICA de ultimas_compras do CLIENTE 1 !!\n\n");
		return ERRO;  // ERRO est� definido em TYPES_DEFINES.h
	}
	
	// preenche a �rea dinamicamente alocada com n�meros aleat�rios entre 100 e 499
	for ( k = 0; k < 6; k++ ) {
		cli_ptr[1].ultimas_compras[k] = 100 + rand()%400;
	}
	
	// impress�es das vari�veis "fixas"
	printf("\n\n");
	printf(" Mem�ria STACK\n");
	printf(" -------------\n");
	printf(" cli_ptr (CLIENTE *) - endere�o #%p - qtd bytes %d - conte�do #%p\n", &cli_ptr, sizeof(cli_ptr), cli_ptr);
	printf(" k      (int)        - endere�o #%p - qtd bytes %d - conte�do %d\n",  &k,       sizeof(k),       k     );
	printf(" i      (int)        - endere�o #%p - qtd bytes %d - conte�do %d\n",  &i,       sizeof(i),       i     );
	
	// impress�es dos conte�dos dos CLIENTEs
	printf("\n");
	printf(" Mem�ria HEAP\n");
	printf(" ------------\n");
	
	// as impress�es s�o as mesmas para os dois CLIENTEs, portanto � poss�vel usar 'for'
	for ( i = 0; i < 2; i++ ) {
		printf(" cli_ptr[%d] (CLIENTE) - endere�o #%p\n",                                i, &(cli_ptr[i]) );
		printf(" cli_ptr[%d].codigo    - endere�o #%p - qtd bytes %d - conte�do %d\n",   i, &(cli_ptr[i].codigo), sizeof(cli_ptr[i].codigo), cli_ptr[i].codigo);
		printf(" cli_ptr[%d].status    - endere�o #%p - qtd bytes %d - conte�do %c\n",   i, &(cli_ptr[i].status), sizeof(cli_ptr[i].status), cli_ptr[i].status);
		printf(" cli_ptr[%d].ticket    - endere�o #%p - qtd bytes %d - conte�do %.2f\n", i, &(cli_ptr[i].ticket), sizeof(cli_ptr[i].ticket), cli_ptr[i].ticket);
		printf(" cli_ptr[%d].ults_comp - endere�o #%p - qtd bytes %d - conte�do #%p\n",  i, &(cli_ptr[i].ultimas_compras), sizeof(cli_ptr[i].ultimas_compras), cli_ptr[i].ultimas_compras);
		printf("\n");
		for ( k = 0; k < 6; k++ ) {
			printf(" cli_ptr[%d].ults_comp[%d] - endere�o #%p - qtd bytes %d - conte�do %.2f\n",
		              	    i, k, &(cli_ptr[i].ultimas_compras[k]), sizeof(cli_ptr[i].ultimas_compras[k]), cli_ptr[i].ultimas_compras[k]);
    	}
    	printf("\n");
	}

	// libera��o da �rea alocada da mais recente para a mais antiga
	free( cli_ptr[1].ultimas_compras );
	free( cli_ptr[0].ultimas_compras );
	free( cli_ptr );
	
	// finaliza��o
	return SUCESSO;  // SUCESSO est� definido em TYPES_DEFINES.h
}