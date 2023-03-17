// -----------------------------------------------
// Lab. : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// Ano/S: 2023/1S
// -----------------------------------------------

// Atividade - m�todos de busca - linear
// Permite verificar que o tempo � linear com o tamanho do vetor, isto �,
// se o vetor dobra de tamanho, o tempo tende a dobrar tamb�m

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using std::cout;
using std::endl;
using std::cin;

#define VALOR_PROIBIDO 12345

// procedimento para identificar o autor do trabalho
// -------------------------------------------------
void exibe_dados_autor() {
	printf("\n");
	printf("---------------------------------------------------\n");
    printf("Lab. : VETORES - OPERA��ES DE BUSCA E ORDENA��O \n"); 
	printf("---------------------------------------------------\n");
	printf("Trabalho elaborado por: CARLOS MAGNUS CARLSON FILHO\n");
	printf("RA: 121 048 AAS P NNN\n");
	printf("Turma: ADS Tarde - 2023/1S\n");
	printf("---------------------------------------------------\n");
	return;   // desnecess�rio porque o procedimento � 'void'
}

// BUSCA LINEAR
// ------------
int busca_Linear ( int a[], // nome do vetor
                   int n,   // comprimento do vetor a ser utilizado nas buscas
			       int c,   // valor procurado
				   int imprimir)
{
	int achou =  0; // auxiliar para indicar se achou ou n�o o valor procurado
	int     i;      // auxiliar de percurso do vetor, indica tamb�m a posi��o onde achou o valor

    // loop de compara��es, enquanto n�o acabar o vetor e enquanto n�o encontrar o que procura
	for ( i=0; i < n && !achou; i++ ) {
		if ( c == a[i] ) {
			achou = 1;
		}
		if (imprimir) {
			cout << " Posi��o " << i << " - valor " << a[i] << " - Achou... " << achou << endl;
		}
	}
	if ( !achou ) return  -1;
	else          return i-1; // devido ao i++ do 'for'
}

int main()
{

	// in�cio: declara��es dos vetores - aloca��o din�mica
	int   t1;    // tamanho do vetor
	int * v1;    // ponteiro para o in�cio do vetor na mem�ria heap

    char v;      // auxiliar para leituras de valores a partir do teclado
    int  chave;  // auxiliar para buscas - valor procurado
    int  posicao;// auxiliar para buscas - posi��o onde est� o elemento de valor procurado

    clock_t start,end; // auxiliares para calculo da diferen�a de tempo com precis�o de milissegundos
    float diferenca;   // diferen�a de tempo com precis�o de milissegundos
    
    // para falar Portugu�s ...
    setlocale(LC_ALL,"Portuguese");

	// loop infinito de testes
	int repetir = 1;
	while ( repetir ) {
		
	    // cria��o do vetor para teste da busca linear
        cout << endl;
        cout << " Informe o tamanho do vetor para teste da busca linear : ";
        cin  >> t1;
        cout << endl;
	
	    // aloca��o din�mica
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << " Problema na aloca��o din�mica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }
	    
	    // preenchimento do vetor com valores aleat�rios
	    srand( (unsigned)1000000 ); // inicializa semente do gerador randomico
	    //srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico
        for( int i=0 ; i < t1 ; i++ ) {
    	    v1[i] = 1 + ( rand()%(10*t1) );  // valores positivos entre 1 e 10*t1
    	    if ( v1[i] == VALOR_PROIBIDO )
    	        v1[i]++;
        }
        
        // acionamento da busca linear procurando um valor que N�O EST� armazenado no vetor
        // (finalidade: medir o tempo)
        chave = VALOR_PROIBIDO;
    
        cout << endl;
        cout << " Procurando por busca linear ... " << endl;
        
        // coleta as medidas de hor�rio (ou clock) antes e depois do acionamento
        start = clock();
        posicao = busca_Linear( v1, t1, chave, 1 );  // �ltimo n�mero indica impress�es intermedi�rias (1) ou n�o (0)
        end = clock();
        
        // impress�o do resultado
		if ( posicao != -1 ) {
             cout << " Valor " << chave << " encontrado na posi��o " << posicao << " do vetor ! ";
        }
        else {
            cout << " Valor " << chave << " n�o foi encontrado no vetor ! ";
        }
   	    cout << endl;
   	    
   	    // c�lculo e impress�o do tempo l�quido de execu��o do m�todo de busca
        diferenca = ((float)(end-start)/CLOCKS_PER_SEC);
        cout << " Levou "<< diferenca  << " segundos para terminar !" << endl;
    
        cout << endl;

        // libera mem�ria alocada para o vetor
        free ( v1 );
        
        // decide se continua os testes ou n�o
        cout << " Pressione S se quiser continuar ou qualquer outra tecla para terminar. Depois, pressione <Enter> : ";
        cin  >> v;
        if ( v != 's' && v != 'S' )
            repetir = 0;
	}

    cout << endl;
   
    //cout << " Pressione qualquer tecla e depois <Enter> para sair: ";
    //cin  >> v;
    
    // identifica��o do autor do trabalho
    exibe_dados_autor();
    
    // finaliza��o
    return 0;
}



