// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: FUNÇÕES E PROCEDIMENTOS AUXILIARES
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// Procedimento para identificar o autor do trabalho
// -------------------------------------------------
void exibe_dados_autor() {
	printf("\n");
	printf("---------------------------------------------------\n");
    printf("Disc.: IED-001 - ESTRUTURAS DE DADOS\n"); 
    printf("Lab. : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO\n"); 
	printf("---------------------------------------------------\n");
	printf("Trabalho elaborado por: CARLOS MAGNUS CARLSON FILHO\n");
	printf("RA: 121 048 AAS P NNN\n");
	printf("Turma: ADS Tarde - 2023/1S\n");
	printf("---------------------------------------------------\n");
	return;   // desnecessário porque o procedimento é 'void'
}

#ifdef AUTOMATICO
// Procedimento para imprimir linha separadora da tabela-resumo
// ------------------------------------------------------------
void imprime_separador() {
    cout << "+---------------------------+-------------------+-----------+" << endl;
    return;
}

// Procedimento para imprimir cabeçalho da tabela-resumo
// -----------------------------------------------------
void imprime_cabecalho() {
    cout << "| MÉTODO                    | TESTE             | TEMPO (s) |" << endl;
    return;
}

// Procedimento para imprimir nome do método na tabela-resumo
// ----------------------------------------------------------
void imprime_nome_metodo( const char * metodo ) {
	int i;
	char folga[32] = "\0";
	for ( i = 0; i < abs((26-strlen(metodo))); i++) {
		strcat(folga," ");
	}
	
	cout << "| " << metodo << folga;
	return;
}

// Procedimento para imprimir dados do teste na tabela-resumo
// ----------------------------------------------------------
void imprime_dados_teste( const char * teste ) {
	int i;
	char folga[16] = "\0";
	for ( i = 0; i < abs((18-strlen(teste))); i++) {
		strcat(folga," ");
	}
	
	cout << "| " << teste << folga;
	return;
}

// Procedimento para imprimir tempo do teste na tabela-resumo
// ----------------------------------------------------------
void imprime_tempo_teste( float tempo ) {
	
	cout << "|  " << setw(6) << fixed << setprecision(3) << tempo << "   |" << endl;
	return;
}

#endif

#ifndef AUTOMATICO
// Função que retorna o método escolhido para o teste
// --------------------------------------------------
int escolhe_metodo() {
	
	// declaração de variáveis
	int escolha;
	
	// exibição das opções
	cout << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Escolha do método de ordenação a ser executado:" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "1 - Bolha direto    (bubble sort) - esquerda->direita" << endl;
	cout << "2 - Bolha invertido (bubble sort) - direita->esquerda" << endl;
	cout << "3 - Inserção     (insertion sort)" << endl;
	cout << "4 - Seleção      (selection sort)" << endl;
	cout << "5 - Mesclagem    (merge sort)     - não recursivo" << endl;
	cout << "6 - Mesclagem    (merge sort)     - recursivo" << endl;
	cout << "7 - Partição     (quick sort)     - recursivo" << endl;
	cout << "9 - Sair do programa" << endl;
		
	// obtenção, via teclado, da escolha do usuário
	cout << endl;
	cout << "Informe a opção desejada: ";
	cin >> escolha;
	
	// retorna a opção escolhida
	return escolha;
}
#endif

// Função que retorna o método escolhido para o teste - versão AUTOMATICO
// ----------------------------------------------------------------------
int escolhe_metodo_2( int metodo_atual ) {
	return ++metodo_atual;
}

#ifndef AUTOMATICO
// Função que retorna o tipo de teste
// - vetor fixo
// - vetor grande 1 preenchido aleatoriamente
// - vetor grande 1 preenchido com valores decrescentes
// - vetor grande 2 preenchido aleatoriamente
// - vetor grande 2 preenchido com valores decrescentes
// ----------------------------------------------------
int escolhe_teste() {
	
	// declaração de variáveis
	int escolha;
	
	// exibição das opções
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Escolha do tipo de teste a ser executado:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1 - Vetor fixo para validação do método de ordenação" << endl;
	cout << "2 - Vetor grande 1 (20000 elementos) preenchido aleatoriamente" << endl;
	cout << "3 - Vetor grande 2 (40000 elementos) preenchido aleatoriamente" << endl;
	cout << "4 - Vetor grande 1 (20000 elementos) preenchido com valores decrescentes" << endl;
	cout << "5 - Vetor grande 2 (40000 elementos) preenchido com valores decrescentes" << endl;
	cout << "8 - Voltar à escolha do método de ordenação" << endl;
	cout << "9 - Sair do programa" << endl;
		
	// obtenção, via teclado, da escolha do usuário
	cout << endl;
	cout << "Informe a opção desejada: ";
	cin >> escolha;
	
	// retorna a opção escolhida
	return escolha;
}
#endif

// Função que retorna o tipo de teste - versão AUTOMATICO
// ------------------------------------------------------
int escolhe_teste_2 ( int teste_atual ) {
	return ++teste_atual;
}

#ifndef AUTOMATICO
// Procedimento que monta o VETOR FIXO e o imprime antes da ordenação
// ------------------------------------------------------------------
void monta_vetor_FIXO( int V1[], const char * m ) {
	
	int i;
	
	cout << endl;
	cout << "------------------------------------ " << endl;
	cout << "Inicializando dados do vetor V1 para: " << m << endl;
	cout << "------------------------------------ " << endl;
	cout << endl;
   
	V1[0] = 89;
	V1[1] = 44;
	V1[2] = 75;
	V1[3] = 66;
	V1[4] = 11;
	V1[5] = 38;
	V1[6] = 93;
	V1[7] = 56;

	cout << "Valor    de V1: [ " ;
	for ( i=0; i<8; i++ ) {
		cout <<  V1[i] << "  ";
	}
	cout << " ]"  << endl;;
	cout << endl;
	
	return;
}
#endif

// Procedimento que monta o VETOR GRANDE 1 e o preenche com números decrescentes
// -----------------------------------------------------------------------------
void monta_vetor_GRANDE_1_DECRESCENTE ( int T1[], const char * m ) {
	
	int i;
	
	#ifndef AUTOMATICO
	cout << endl;
	cout << "------------------------------------ " << endl;
	cout << "Inicializando dados do vetor T1 para: " << m << endl;
	cout << "------------------------------------ " << endl;
	cout << endl;
	#endif

	for ( i = 0; i < 20000; i++ ) {
		T1[i] = 20000-i;
	}
	
	#ifndef AUTOMATICO
	//cout << "Você escolheu gerar vetores com números decrescentes !" << endl;
	cout << "Primeiro elemento de T1: " << T1[0] << endl;
	cout << "Último   elemento de T1: " << T1[19999] << endl;
	#endif
	
	return;
}

// Procedimento que monta o VETOR GRANDE 2 e o preenche com números decrescentes
// -----------------------------------------------------------------------------
void monta_vetor_GRANDE_2_DECRESCENTE ( int T2[], const char * m ) {
	
	int i;
	
	#ifndef AUTOMATICO
	cout << endl;
	cout << "------------------------------------ " << endl;
	cout << "Inicializando dados do vetor T2 para: " << m << endl;
	cout << "------------------------------------ " << endl;
	cout << endl;
	#endif

	for ( i = 0; i < 40000; i++ ) {
		T2[i] = 40000-i;
	}
	
	#ifndef AUTOMATICO
	//cout << "Você escolheu gerar vetores com números decrescentes !" << endl;
	cout << "Primeiro elemento de T2: " << T2[0] << endl;
	cout << "Último   elemento de T2: " << T2[39999] << endl;
	#endif
	
	return;
}

// Procedimento que monta o VETOR GRANDE 1 e o preenche com números aleatórios
// ---------------------------------------------------------------------------
void monta_vetor_GRANDE_1_ALEATORIO( int T1[], const char * m ) {
	
	int i;
	time_t hora; // auxiliar para cálculo de tempo

	#ifndef AUTOMATICO
	cout << endl;
	cout << "------------------------------------ " << endl;
	cout << "Inicializando dados do vetor T1 para: " << m << endl;
	cout << "------------------------------------ " << endl;
	cout << endl;
	#endif
	
	srand( (unsigned)time(&hora) ); // inicializa semente do gerador randomico 
    for( i = 0; i < 20000; i++ ) {
		 T1[i] = 1 + (rand()%20000);
	}
	
	#ifndef AUTOMATICO
	//cout << "Voce escolheu gerar vetores com numeros aleatorios !" << endl;
	cout << "Primeiro elemento de T1: " << T1[0] << endl;
	cout << "Ultimo   elemento de T1: " << T1[19999] << endl;
	#endif
	
	return;
}

// Procedimento que monta o VETOR GRANDE 2 e o preenche com números aleatórios
// ---------------------------------------------------------------------------
void monta_vetor_GRANDE_2_ALEATORIO( int T2[], const char * m ) {
	
	int i;
	time_t hora; // auxiliar para cálculo de tempo
	
	#ifndef AUTOMATICO
	cout << endl;
	cout << "------------------------------------ " << endl;
	cout << "Inicializando dados do vetor T2 para: " << m << endl;
	cout << "------------------------------------ " << endl;
	cout << endl;
	#endif

	srand( (unsigned)time(&hora) ); // inicializa semente do gerador randomico 
    for( i = 0; i < 40000; i++ ) {
		 T2[i] = 1 + (rand()%40000);
	}
	
	#ifndef AUTOMATICO
	//cout << "Você escolheu gerar vetores com numeros aleatorios !" << endl;
	cout << "Primeiro elemento de T2: " << T2[0] << endl;
	cout << "Último   elemento de T2: " << T2[39999] << endl;
	#endif
	
	return;
}
