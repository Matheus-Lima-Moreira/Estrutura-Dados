// ------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCAÇÃO DINÂMICA DE MEMÓRIA
// Ano/S: 2023/1S
// ------------------------------------

// Atividade 3
// Alocação dinâmica de 'struct' com campos que também exigem alocação dinâmica
// ----------------------------------------------------------------------------

int atividade_3() {
	
	// definição do tipo CLIENTE -> já feita em TYPES_DEFINES.h
	/*
	typedef struct {
		int     codigo;
		char    status;
		double  ticket;
		float * ultimas_compras;
	} CLIENTE;
	*/
	
	// declaração de variáveis
	CLIENTE * cli_ptr;
	int k, i;  // auxiliares de percurso 'for'
	
	// alocação dinâmica de DOIS CLIENTEs (com 'casting')
	cli_ptr = (CLIENTE *) malloc( 2 * sizeof(CLIENTE) );
	
	// teste para saber se alocação dinâmica falhou
	if ( cli_ptr == NULL ) {
		printf("\n\n ERRO na ALOCAÇÃO DINÂMICA de CLIENTE !!\n\n");
		return ERRO;  // ERRO está definido em TYPES_DEFINES.h
	}
	
	// atribuições de valores aos campos dos CLIENTEs
	cli_ptr[0].codigo = 1;
	cli_ptr[0].status = 'A';
	cli_ptr[0].ticket = 1000.0;
	cli_ptr[0].ultimas_compras = (float *) malloc( 6 * sizeof(float) );
  
	// teste para saber se alocação dinâmica falhou
	if ( cli_ptr[0].ultimas_compras == NULL ) {
		printf("\n\n ERRO na ALOCAÇÃO DINÂMICA de ultimas_compras do CLIENTE 0 !!\n\n");
		return ERRO;  // ERRO está definido em TYPES_DEFINES.h
	}
	
	// preenche a área dinamicamente alocada com números aleatórios entre 100 e 499
	for ( k = 0; k < 6; k++ ) {
		cli_ptr[0].ultimas_compras[k] = 100 + rand()%400;
	}
	
	cli_ptr[1].codigo = 2;
	cli_ptr[1].status = 'B';
	cli_ptr[1].ticket  = 2000.0;
	cli_ptr[1].ultimas_compras = (float *) malloc( 6 * sizeof(float) );
	// teste para saber se alocação dinâmica falhou
	if ( cli_ptr[1].ultimas_compras == NULL ) {
		printf("\n\n ERRO na ALOCAÇÃO DINÂMICA de ultimas_compras do CLIENTE 1 !!\n\n");
		return ERRO;  // ERRO está definido em TYPES_DEFINES.h
	}
	
	// preenche a área dinamicamente alocada com números aleatórios entre 100 e 499
	for ( k = 0; k < 6; k++ ) {
		cli_ptr[1].ultimas_compras[k] = 100 + rand()%400;
	}
	
	// impressões das variáveis "fixas"
	printf("\n\n");
	printf(" Memória STACK\n");
	printf(" -------------\n");
	printf(" cli_ptr (CLIENTE *) - endereço #%p - qtd bytes %d - conteúdo #%p\n", &cli_ptr, sizeof(cli_ptr), cli_ptr);
	printf(" k      (int)        - endereço #%p - qtd bytes %d - conteúdo %d\n",  &k,       sizeof(k),       k     );
	printf(" i      (int)        - endereço #%p - qtd bytes %d - conteúdo %d\n",  &i,       sizeof(i),       i     );
	
	// impressões dos conteúdos dos CLIENTEs
	printf("\n");
	printf(" Memória HEAP\n");
	printf(" ------------\n");
	
	// as impressões são as mesmas para os dois CLIENTEs, portanto é possível usar 'for'
	for ( i = 0; i < 2; i++ ) {
		printf(" cli_ptr[%d] (CLIENTE) - endereço #%p\n",                                i, &(cli_ptr[i]) );
		printf(" cli_ptr[%d].codigo    - endereço #%p - qtd bytes %d - conteúdo %d\n",   i, &(cli_ptr[i].codigo), sizeof(cli_ptr[i].codigo), cli_ptr[i].codigo);
		printf(" cli_ptr[%d].status    - endereço #%p - qtd bytes %d - conteúdo %c\n",   i, &(cli_ptr[i].status), sizeof(cli_ptr[i].status), cli_ptr[i].status);
		printf(" cli_ptr[%d].ticket    - endereço #%p - qtd bytes %d - conteúdo %.2f\n", i, &(cli_ptr[i].ticket), sizeof(cli_ptr[i].ticket), cli_ptr[i].ticket);
		printf(" cli_ptr[%d].ults_comp - endereço #%p - qtd bytes %d - conteúdo #%p\n",  i, &(cli_ptr[i].ultimas_compras), sizeof(cli_ptr[i].ultimas_compras), cli_ptr[i].ultimas_compras);
		printf("\n");
		for ( k = 0; k < 6; k++ ) {
			printf(" cli_ptr[%d].ults_comp[%d] - endereço #%p - qtd bytes %d - conteúdo %.2f\n",
		              	    i, k, &(cli_ptr[i].ultimas_compras[k]), sizeof(cli_ptr[i].ultimas_compras[k]), cli_ptr[i].ultimas_compras[k]);
    	}
    	printf("\n");
	}

	// liberação da área alocada da mais recente para a mais antiga
	free( cli_ptr[1].ultimas_compras );
	free( cli_ptr[0].ultimas_compras );
	free( cli_ptr );
	
	// finalização
	return SUCESSO;  // SUCESSO está definido em TYPES_DEFINES.h
}