// ----------------------------------------------------------------------------------------------------------
// Disc.: IED-001 - ESTRUTURAS DE DADOS
// Lab. : ALOCAÇÃO DINÂMICA DE MEMÓRIA
// Ano/S: 2023/1S
// ----------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------
// Atividade 1
// Alocação dinâmica para 'int' e 'double'

int atividade_1() {
	
	printf("\n -----------------");
	printf("\n ALOCAÇÃO DINÂMICA");
	printf("\n -----------------\n");
	
	// declaração de variável auxiliar para percursos 'for'
	int k;

	// --------------------------------------------------------------------------------------------------------
	// PARTE 1 - INT - MEMÓRIA HEAP
			
	// alocação dinâmica para 'int'
	int * i_ptr;  // armazenará o endereço inicial da memória alocada dinamicamente
	int   i_qtd;  // armazenará a qtd de 'int' necessária (lido do teclado)
	
	// descobre quantos 'int' são necessários
	printf("\n Informe a qtd de INT que você quer alocar: ");
	scanf("%d",&i_qtd);
	
	// aloca memória dinamicamente, informando quantos BYTES são necessários
	// dependendo do compilador, o 'casting' (conversão de tipo do ponteiro) é opcional
	i_ptr = (int *) malloc( i_qtd * sizeof(int) );
	
	// teste para saber se alocação dinâmica falhou
	if ( i_ptr == NULL ) {
		printf("\n\n ERRO na ALOCAÇÃO DINÂMICA de int !!\n\n");
		return ERRO; // ERRO está definido em TYPES_DEFINES.h
	}
	
	// preenche a área dinamicamente alocada com números aleatórios entre 0 e 99
	for ( k = 0; k < i_qtd; k++ ) {
		i_ptr[k] = rand()%100; // i_ptr[k] é o mesmo que *(i_ptr + k)
	}
	
	// impressões
	printf("\n");
	printf(" Memória STACK\n");
	printf(" -------------\n");
	printf(" i_qtd (int)   - endereço #%p - qtd bytes %d - conteúdo %3d\n", &i_qtd, sizeof(i_qtd), i_qtd);
	printf(" i_ptr (int *) - endereço #%p - qtd bytes %d - conteúdo #%p\n", &i_ptr, sizeof(i_ptr), i_ptr);
	
	printf("\n");
	printf(" Memória HEAP\n");
	printf(" ------------\n");
	for ( k = 0; k < i_qtd; k++ ) {
		printf(" i_ptr[%d] (int) - endereço #%p - qtd bytes %d - conteúdo %3d\n", k, &(i_ptr[k]), sizeof(i_ptr[k]), i_ptr[k]);
	}
	printf(" ------------\n");
	
	// libera a memória alocada -> colocado no final deste código
	//free( i_ptr );
	
	// FIM DA PARTE 1 - INT
	// --------------------
	
	// PARTE 2 - DOUBLE - MEMÓRIA HEAP
	// -------------------------------
	
	// alocação dinâmica para 'double'
	double * d_ptr;  // armazenará o endereço inicial da memória alocada dinamicamente
	int      d_qtd;  // armazenará a qtd de 'double' necessária (lido do teclado)
	
	// descobre quantos 'double' são necessários
	printf("\n Informe a qtd de DOUBLE que você quer alocar: ");
	scanf("%d",&d_qtd);
	
	// aloca memória dinamicamente, informando quantos BYTES são necessários
	// dependendo do compilador, o 'casting' (conversão de tipo do ponteiro) é opcional
	d_ptr = (double *) malloc( d_qtd * sizeof(double) );
	
	// teste para saber se alocação dinâmica falhou
	if ( d_ptr == NULL ) {
		printf("\n\n ERRO na ALOCAÇÃO DINÂMICA de double !!\n\n");
		return ERRO;  // ERRO está definido em TYPES_DEFINES.h
	}
	
	// preenche a área dinamicamente alocada com números aleatórios entre 0 e 0.999
	for ( k = 0; k < d_qtd; k++ ) {
		d_ptr[k] = (double) (rand()%1000)/1000.0;   // d_ptr[k] é o mesmo que *(d_ptr + k)
	}
	
	// impressões
	printf("\n");
	printf(" Memória STACK\n");
	printf(" -------------\n");
	printf(" d_qtd (int)      - endereço #%p - qtd bytes %d - conteúdo %3d\n", &d_qtd, sizeof(d_qtd), d_qtd);
	printf(" d_ptr (double *) - endereço #%p - qtd bytes %d - conteúdo #%p\n", &d_ptr, sizeof(d_ptr), d_ptr);
	
	printf("\n");
	printf(" Memória HEAP\n");
	printf(" ------------\n");
	for ( k = 0; k < d_qtd; k++ ) {
		printf(" d_ptr[%d] (double) - endereço #%p - qtd bytes %d - conteúdo %5.3f\n", k, &(d_ptr[k]), sizeof(d_ptr[k]), d_ptr[k]);
	}
	printf(" ------------\n");
	
	// libera a memória alocada -> colocado no final deste código
	//free( d_ptr );
	
	// FIM DA PARTE 2 - DOUBLE
	// -----------------------

	// libera a memória alocada (recomendado: ordem inversa à da alocação)
	free( d_ptr );
	free( i_ptr );	
	
	// finalização
	return SUCESSO;  // SUCESSO está definido em TYPES_DEFINES.h
}