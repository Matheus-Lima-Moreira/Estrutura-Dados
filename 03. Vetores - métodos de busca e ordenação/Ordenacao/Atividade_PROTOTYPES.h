// -----------------------------------------------
// Lab. : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: PROTOTYPES DE FUN��ES E PROCEDIMENTOS
// Ano/S: 2023/1S
// -----------------------------------------------

// Procedimento para identificar o autor do trabalho
// -------------------------------------------------
void exibe_dados_autor( void );

#ifdef AUTOMATICO

// Procedimento para imprimir linha separadora da tabela-resumo
// ------------------------------------------------------------
void imprime_separador( void );

// Procedimento para imprimir cabe�alho da tabela-resumo
// -----------------------------------------------------
void imprime_cabecalho( void );

// Procedimento para imprimir nome do m�todo na tabela-resumo
// ----------------------------------------------------------
void imprime_nome_metodo( const char * metodo );

// Procedimento para imprimir dados do teste na tabela-resumo
// ----------------------------------------------------------
void imprime_dados_teste( const char * teste );

// Procedimento para imprimir tempo do teste na tabela-resumo
// ----------------------------------------------------------
void imprime_tempo_teste( float tempo );

#endif

#ifndef AUTOMATICO

// Fun��o que retorna o m�todo escolhido para o teste
// --------------------------------------------------
int escolhe_metodo( void );

#endif

// Fun��o que retorna o m�todo escolhido para o teste - vers�o AUTOMATICO
// ----------------------------------------------------------------------
int escolhe_metodo_2( int metodo_atual );

#ifndef AUTOMATICO

// Fun��o que retorna o tipo de teste
// - vetor fixo
// - vetor grande 1 preenchido aleatoriamente
// - vetor grande 1 preenchido com valores decrescentes
// - vetor grande 2 preenchido aleatoriamente
// - vetor grande 2 preenchido com valores decrescentes
// ----------------------------------------------------
int escolhe_teste( void );

#endif

// Fun��o que retorna o tipo de teste - vers�o AUTOMATICO
// ------------------------------------------------------
int escolhe_teste_2 ( int teste_atual );

#ifndef AUTOMATICO

// Procedimento que monta o VETOR FIXO e o imprime antes da ordena��o
// ------------------------------------------------------------------
void monta_vetor_FIXO( int V1[], const char * m );
#endif

// Procedimento que monta o VETOR GRANDE 1 e o preenche com n�meros decrescentes
// -----------------------------------------------------------------------------
void monta_vetor_GRANDE_1_DECRESCENTE ( int T1[], const char * m );

// Procedimento que monta o VETOR GRANDE 2 e o preenche com n�meros decrescentes
// -----------------------------------------------------------------------------
void monta_vetor_GRANDE_2_DECRESCENTE ( int T2[], const char * m );

// Procedimento que monta o VETOR GRANDE 1 e o preenche com n�meros aleat�rios
// ---------------------------------------------------------------------------
void monta_vetor_GRANDE_1_ALEATORIO( int T1[], const char * m );

// Procedimento que monta o VETOR GRANDE 2 e o preenche com n�meros aleat�rios
// ---------------------------------------------------------------------------
void monta_vetor_GRANDE_2_ALEATORIO( int T2[], const char * m );

// ---- M�todo da BOLHA - Bubble Sort - Percurso Esquerda -> Direita --- 
// --------------------------------------------------------------------- 
void bubble_sort ( int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                   int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			       int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			     );

// ---- M�todo da BOLHA - Bubble Sort - Percurso Direita -> Esquerda --- 
// --------------------------------------------------------------------- 
void bubble_sort_invertido ( int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                             int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			                 int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			               );

// ---- M�todo da SELE��O - Selection Sort --- 
// ------------------------------------------- 
void selection_sort ( int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                      int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			          int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			        );

// ---- M�todo da INSER��O - Insertion Sort --- 
// -------------------------------------------- 
void insertion_sort ( int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                      int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			          int imprimir // chave para imprimir ou n�o os passos intermedi�rios
				    );

/* ---- M�todo da MESCLAGEM - Merge Sort --- */
/* ----------------------------------------- */
void merge_sort ( int a[],     /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - primeira metade */
                  int na,      /* tamanho da primeira metade - j� est� ordenada */
                  int b[],     /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - segunda metade */
                  int nb,      /* tamanho da segunda metade  - j� est� ordenada */
                  int f[],     /* vetor que ser� efetivamente ordenado, recebendo os valores mesclados das duas metades */
			      int imprimir /* chave para imprimir ou n�o os passos intermedi�rios */
				);

/* ---- M�todo da MESCLAGEM - Merge Sort - Vers�o Recursiva ---- */
/* ------------------------------------------------------------- */
void merge_sort_r ( int f[],     /* vetor que ser� efetivamente ordenado, recebendo os valores mesclados das duas metades */
                    int nf,      /* tamanho do vetor f */
			        int imprimir /* chave para imprimir ou n�o os passos intermedi�rios */
				  );

/* ---- M�todo da PARTI��O - Quick Sort - Vers�o Recursiva ---- */
/* ------------------------------------------------------------ */
// Recebe vetor v[p..r] com p < r. Rearranja os elementos do vetor e
// devolve j em p..r tal que v[p..j-1] <= v[j] < v[j+1..r].

int separa( int v[], int p, int r, int imprimir );

// Recurs�o comum
// A fun��o recebe um vetor v[p..r], com p <= r+1,
// e rearranja o vetor em ordem crescente.

void quick_sort( int v[], int p, int r, int imprimir );

// Recurs�o em 'cauda' (TAIL) - vers�o 1
// Utiliza loop 'while' e s� chama um de cada vez
void quick_sort_tail_1( int arr[], int low, int high, int imprimir ); 

// Recurs�o em 'cauda' (TAIL) - vers�o 2
// Requer espa�o auxiliar O(Log n) no pior caso !
void quick_sort_tail_2( int arr[], int low, int high, int imprimir ); 
