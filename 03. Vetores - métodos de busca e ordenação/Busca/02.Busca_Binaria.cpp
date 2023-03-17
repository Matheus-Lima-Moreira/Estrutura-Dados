// ---------------------------------------------
// Nome : COLOQUE AQUI O SEU NOME COMPLETO
// R.A. : COLOQUE AQUI O SEU NÚMERO DE MATRÍCULA
// Turma: (   ) M     (   ) T     (   ) N
// ---------------------------------------------

// -----------------------------------------------
// Lab. : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Ano/S: 2021/1S
// -----------------------------------------------

// Exemplos de métodos de busca - binária
// Permite avaliar a esperança (média) de comparações

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <locale>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

#define QTD_TESTES 10

// impressão de cabeçalho (só depende do tamanho do vetor) 
void imprimeCabecalho ( int n ) {
	int i;
	cout << "\nSubscritos:\n";
	for ( i = 0; i < n; i++ ) {
		cout << setw(3) << i << ' ';
	}
	cout << '\n';
	for ( i = 1; i < 4*n; i++ ) {
		cout << '-';
	}
	cout << endl;
}

// impressão de uma linha (um passo da busca) 
void imprimeLinha( int a[], int inicial, int meio, int final, int n ) {
	int i;
	for ( i = 0; i < n; i++ ) {
		if ( i < inicial || i > final ) {
			cout << "    ";
		}
		else {
			if ( i == meio ) {
				cout << setw(3) << a[i] << '*';
			}
			else {
				cout << setw(3) << a[i] << ' ';
			}
		}
	}
	cout << endl;
}

// BUSCA BINÁRIA 
// ------------- 
int busca_Binaria ( int a[], // nome do vetor 
                    int n,   // comprimento do vetor a ser utilizado nas buscas 
			        int c,   // valor procurado 
				    int imprimir)
{
  	int inicial = 0;      // menor posição do vetor a ser analisado (ajustada durante a busca)
  	int final   = n - 1;  // maior posição do vetor a ser analisado (ajustada durante a busca)
  	int meio;             // posição central do vetor a ser analisado (calculado durante a busca)
  	
  	// impressão do cabeçalho (auxiliar) 
  	if ( imprimir ) {
		  imprimeCabecalho( n );
    }
    
    // loop de comparações, enquanto não acabar o vetor e enquanto não encontrar o que procura 
	while ( inicial <= final ) {
		// calcula a posição central
		meio = ( inicial + final ) / 2;
		// imprime os dados da busca no momento
		if ( imprimir ) {
			imprimeLinha( a, inicial, meio, final, n );
		}
		// se não encontrou, decide qual das metades do vetor será utilizada no próximo passo
		if ( c == a[meio] ) {
			return meio;
		}
		else {
			if ( c < a[meio] ) {  // utilizará a metade "de baixo"
				final = meio - 1;
			}
			else {                // utilizará a metade "de cima"
				inicial = meio + 1;
			}
		}
	}
	
	// se está aqui é porque não encontrou o que buscava
	return -1;
}

// PROGRAMA PRINCIPAL 
// ------------------ 
int main()
{

	// início: declarações do vetor - alocação dinâmica 
	int   t1;    // tamanho do vetor 
	int * v1;    // ponteiro para o início do vetor na memória heap 

    char v;      // auxiliar para leituras de valores a partir do teclado 
    int  chave;  // auxiliar para buscas - valor procurado 
    int  posicao;// auxiliar para buscas - posição onde está o elemento de valor procurado 

    int resultado[QTD_TESTES]; // vetor para medir a posicao media em que as chaves são encontradas 

    time_t start; // auxiliares para calculo da diferença de tempo com precisão de milissegundos 

	// para falar Português ... 
	setlocale(LC_ALL,"Portuguese");
	
	// loop infinito de testes 
	int repetir = 1;
	while ( repetir ) {
		
	    // criação do vetor para teste da busca linear 
        cout << endl;
        cout << "Informe o tamanho do vetor para testes da busca binária : ";
        cin  >> t1;
        cout << endl;
	
	    // alocação dinâmica 
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << "Problema na alocação dinâmica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }
	    
	    // preenchimento do vetor com valores aleatórios porém crescentes 
	    //srand( (unsigned)1000000 ); // inicializa semente do gerador randomico de modo fixo 
	    srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico 
        // valor da posição inicial do vetor: número entre 0 e 10 
        v1[0] = rand()%5 ;
        for( int i=1 ; i < t1 ; i++ ) {
    	    v1[i] = v1[i-1] + ( rand()%4 ) + 1;  // sempre valores positivos, sem repetição 
        }
        
		// loop de buscas no mesmo vetor 
        for ( int j=0; j < QTD_TESTES; j++ ) {
        	// estabelecimento da chave de forma aleatória 
		    chave = 1 + ( rand()%(v1[t1-1]+4) );  // valores positivos entre 1 e t1+10 
		    //chave = ( rand()%t1 ) + ( rand()%10 );  // valores positivos entre 0 e 9, numa posição qualquer do vetor  
		    
            cout << "\n-----\nTeste " << setw(3) << j+1 << " - Valor procurado: " << chave << endl;
    	    // acionamento da busca linear 
            posicao = busca_Binaria( v1, t1, chave, 1 );  // último número indica impressões intermediárias (1) ou não (0) 
        
		    if ( posicao >= 0 ) {
                //cout << " Valor " << chave << " encontrado na posicao " << posicao << " do vetor ! ";
                //if ( j%10000 == 0 ) cout << " Sim !  Encontrado na posicao " << posicao << endl;
                cout << " Sim !  Encontrado na posição " << posicao << endl;
                resultado[j] = posicao;
            }
            else {
                //cout << " Valor " << chave << " nao foi encontrado no vetor ! ";
                //if ( j%10000 == 0 ) cout << " Não encontrado ... " << endl;
                cout << " Não encontrado ... " << endl;
                //j--; // se quiser faze estatística somente das buscas em que a chave foi encontrada 
            }
    
        }

        // libera memória alocada para o vetor 
        free ( v1 );
                
        // decide se continua os testes ou não 
        cout << endl;
        cout << "\n Pressione S se quiser continuar ou qualquer outra tecla para terminar. Depois, pressione <Enter> : ";
        cin  >> v;
        if ( v != 's' && v != 'S' )
            repetir = 0;
	}

    cout << endl;
   
    //cout << " Pressione qualquer tecla e depois <Enter> para sair: ";
    //cin  >> v;

    return 0;
}



