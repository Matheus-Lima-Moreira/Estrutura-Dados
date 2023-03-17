// ---------------------------------------------
// Nome : COLOQUE AQUI O SEU NOME COMPLETO
// R.A. : COLOQUE AQUI O SEU N�MERO DE MATR�CULA
// Turma: (   ) M     (   ) T     (   ) N
// ---------------------------------------------

// -----------------------------------------------
// Lab. : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// Ano/S: 2021/1S
// -----------------------------------------------

// Exemplos de m�todos de busca - bin�ria
// Permite avaliar a esperan�a (m�dia) de compara��es

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

// impress�o de cabe�alho (s� depende do tamanho do vetor) 
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

// impress�o de uma linha (um passo da busca) 
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

// BUSCA BIN�RIA 
// ------------- 
int busca_Binaria ( int a[], // nome do vetor 
                    int n,   // comprimento do vetor a ser utilizado nas buscas 
			        int c,   // valor procurado 
				    int imprimir)
{
  	int inicial = 0;      // menor posi��o do vetor a ser analisado (ajustada durante a busca)
  	int final   = n - 1;  // maior posi��o do vetor a ser analisado (ajustada durante a busca)
  	int meio;             // posi��o central do vetor a ser analisado (calculado durante a busca)
  	
  	// impress�o do cabe�alho (auxiliar) 
  	if ( imprimir ) {
		  imprimeCabecalho( n );
    }
    
    // loop de compara��es, enquanto n�o acabar o vetor e enquanto n�o encontrar o que procura 
	while ( inicial <= final ) {
		// calcula a posi��o central
		meio = ( inicial + final ) / 2;
		// imprime os dados da busca no momento
		if ( imprimir ) {
			imprimeLinha( a, inicial, meio, final, n );
		}
		// se n�o encontrou, decide qual das metades do vetor ser� utilizada no pr�ximo passo
		if ( c == a[meio] ) {
			return meio;
		}
		else {
			if ( c < a[meio] ) {  // utilizar� a metade "de baixo"
				final = meio - 1;
			}
			else {                // utilizar� a metade "de cima"
				inicial = meio + 1;
			}
		}
	}
	
	// se est� aqui � porque n�o encontrou o que buscava
	return -1;
}

// PROGRAMA PRINCIPAL 
// ------------------ 
int main()
{

	// in�cio: declara��es do vetor - aloca��o din�mica 
	int   t1;    // tamanho do vetor 
	int * v1;    // ponteiro para o in�cio do vetor na mem�ria heap 

    char v;      // auxiliar para leituras de valores a partir do teclado 
    int  chave;  // auxiliar para buscas - valor procurado 
    int  posicao;// auxiliar para buscas - posi��o onde est� o elemento de valor procurado 

    int resultado[QTD_TESTES]; // vetor para medir a posicao media em que as chaves s�o encontradas 

    time_t start; // auxiliares para calculo da diferen�a de tempo com precis�o de milissegundos 

	// para falar Portugu�s ... 
	setlocale(LC_ALL,"Portuguese");
	
	// loop infinito de testes 
	int repetir = 1;
	while ( repetir ) {
		
	    // cria��o do vetor para teste da busca linear 
        cout << endl;
        cout << "Informe o tamanho do vetor para testes da busca bin�ria : ";
        cin  >> t1;
        cout << endl;
	
	    // aloca��o din�mica 
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << "Problema na aloca��o din�mica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }
	    
	    // preenchimento do vetor com valores aleat�rios por�m crescentes 
	    //srand( (unsigned)1000000 ); // inicializa semente do gerador randomico de modo fixo 
	    srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico 
        // valor da posi��o inicial do vetor: n�mero entre 0 e 10 
        v1[0] = rand()%5 ;
        for( int i=1 ; i < t1 ; i++ ) {
    	    v1[i] = v1[i-1] + ( rand()%4 ) + 1;  // sempre valores positivos, sem repeti��o 
        }
        
		// loop de buscas no mesmo vetor 
        for ( int j=0; j < QTD_TESTES; j++ ) {
        	// estabelecimento da chave de forma aleat�ria 
		    chave = 1 + ( rand()%(v1[t1-1]+4) );  // valores positivos entre 1 e t1+10 
		    //chave = ( rand()%t1 ) + ( rand()%10 );  // valores positivos entre 0 e 9, numa posi��o qualquer do vetor  
		    
            cout << "\n-----\nTeste " << setw(3) << j+1 << " - Valor procurado: " << chave << endl;
    	    // acionamento da busca linear 
            posicao = busca_Binaria( v1, t1, chave, 1 );  // �ltimo n�mero indica impress�es intermedi�rias (1) ou n�o (0) 
        
		    if ( posicao >= 0 ) {
                //cout << " Valor " << chave << " encontrado na posicao " << posicao << " do vetor ! ";
                //if ( j%10000 == 0 ) cout << " Sim !  Encontrado na posicao " << posicao << endl;
                cout << " Sim !  Encontrado na posi��o " << posicao << endl;
                resultado[j] = posicao;
            }
            else {
                //cout << " Valor " << chave << " nao foi encontrado no vetor ! ";
                //if ( j%10000 == 0 ) cout << " N�o encontrado ... " << endl;
                cout << " N�o encontrado ... " << endl;
                //j--; // se quiser faze estat�stica somente das buscas em que a chave foi encontrada 
            }
    
        }

        // libera mem�ria alocada para o vetor 
        free ( v1 );
                
        // decide se continua os testes ou n�o 
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



