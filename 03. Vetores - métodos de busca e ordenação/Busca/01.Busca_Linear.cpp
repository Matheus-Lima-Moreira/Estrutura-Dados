// -----------------------------------------------
// Lab. : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Ano/S: 2023/1S
// -----------------------------------------------

// Atividade - métodos de busca - linear
// Permite verificar que o tempo é linear com o tamanho do vetor, isto é,
// se o vetor dobra de tamanho, o tempo tende a dobrar também

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
    printf("Lab. : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO \n"); 
	printf("---------------------------------------------------\n");
	printf("Trabalho elaborado por: CARLOS MAGNUS CARLSON FILHO\n");
	printf("RA: 121 048 AAS P NNN\n");
	printf("Turma: ADS Tarde - 2023/1S\n");
	printf("---------------------------------------------------\n");
	return;   // desnecessário porque o procedimento é 'void'
}

// BUSCA LINEAR
// ------------
int busca_Linear ( int a[], // nome do vetor
                   int n,   // comprimento do vetor a ser utilizado nas buscas
			       int c,   // valor procurado
				   int imprimir)
{
	int achou =  0; // auxiliar para indicar se achou ou não o valor procurado
	int     i;      // auxiliar de percurso do vetor, indica também a posição onde achou o valor

    // loop de comparações, enquanto não acabar o vetor e enquanto não encontrar o que procura
	for ( i=0; i < n && !achou; i++ ) {
		if ( c == a[i] ) {
			achou = 1;
		}
		if (imprimir) {
			cout << " Posição " << i << " - valor " << a[i] << " - Achou... " << achou << endl;
		}
	}
	if ( !achou ) return  -1;
	else          return i-1; // devido ao i++ do 'for'
}

int main()
{

	// início: declarações dos vetores - alocação dinâmica
	int   t1;    // tamanho do vetor
	int * v1;    // ponteiro para o início do vetor na memória heap

    char v;      // auxiliar para leituras de valores a partir do teclado
    int  chave;  // auxiliar para buscas - valor procurado
    int  posicao;// auxiliar para buscas - posição onde está o elemento de valor procurado

    clock_t start,end; // auxiliares para calculo da diferença de tempo com precisão de milissegundos
    float diferenca;   // diferença de tempo com precisão de milissegundos
    
    // para falar Português ...
    setlocale(LC_ALL,"Portuguese");

	// loop infinito de testes
	int repetir = 1;
	while ( repetir ) {
		
	    // criação do vetor para teste da busca linear
        cout << endl;
        cout << " Informe o tamanho do vetor para teste da busca linear : ";
        cin  >> t1;
        cout << endl;
	
	    // alocação dinâmica
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << " Problema na alocação dinâmica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }
	    
	    // preenchimento do vetor com valores aleatórios
	    srand( (unsigned)1000000 ); // inicializa semente do gerador randomico
	    //srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico
        for( int i=0 ; i < t1 ; i++ ) {
    	    v1[i] = 1 + ( rand()%(10*t1) );  // valores positivos entre 1 e 10*t1
    	    if ( v1[i] == VALOR_PROIBIDO )
    	        v1[i]++;
        }
        
        // acionamento da busca linear procurando um valor que NÃO ESTÁ armazenado no vetor
        // (finalidade: medir o tempo)
        chave = VALOR_PROIBIDO;
    
        cout << endl;
        cout << " Procurando por busca linear ... " << endl;
        
        // coleta as medidas de horário (ou clock) antes e depois do acionamento
        start = clock();
        posicao = busca_Linear( v1, t1, chave, 1 );  // último número indica impressões intermediárias (1) ou não (0)
        end = clock();
        
        // impressão do resultado
		if ( posicao != -1 ) {
             cout << " Valor " << chave << " encontrado na posição " << posicao << " do vetor ! ";
        }
        else {
            cout << " Valor " << chave << " não foi encontrado no vetor ! ";
        }
   	    cout << endl;
   	    
   	    // cálculo e impressão do tempo líquido de execução do método de busca
        diferenca = ((float)(end-start)/CLOCKS_PER_SEC);
        cout << " Levou "<< diferenca  << " segundos para terminar !" << endl;
    
        cout << endl;

        // libera memória alocada para o vetor
        free ( v1 );
        
        // decide se continua os testes ou não
        cout << " Pressione S se quiser continuar ou qualquer outra tecla para terminar. Depois, pressione <Enter> : ";
        cin  >> v;
        if ( v != 's' && v != 'S' )
            repetir = 0;
	}

    cout << endl;
   
    //cout << " Pressione qualquer tecla e depois <Enter> para sair: ";
    //cin  >> v;
    
    // identificação do autor do trabalho
    exibe_dados_autor();
    
    // finalização
    return 0;
}



