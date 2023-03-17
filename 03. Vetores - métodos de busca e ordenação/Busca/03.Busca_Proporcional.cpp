// ---------------------------------------------
// Nome : COLOQUE AQUI O SEU NOME COMPLETO
// R.A. : COLOQUE AQUI O SEU NÚMERO DE MATRÍCULA
// Turma: (   ) M     (   ) T     (   ) N
// ---------------------------------------------

// -----------------------------------------------
// Lab. : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Ano/S: 2021/1S
// -----------------------------------------------

// Exemplos de métodos de busca - proporcional
// (aproximação por reta)
// Busca retorna indicador de sucesso e posição (STRUCT)

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using std::cout;
using std::endl;
using std::cin;

#define QTD_TESTES 10

typedef struct {     // struct é criada como variável "global" para ser visível para todos os métodos e o 'main' 
    int posicao;
 	int achou;
} RESULTADO;

// BUSCA PROPORCIONAL - Aproximação por Reta 
// ----------------------------------------- 
void busca_Proporcional_R ( int   v[], // nome do vetor 
                            int   n,   // comprimento do vetor a ser utilizado nas buscas 
			                int   c,   // valor procurado 
                            float a,   //inclinação da reta de aproximação 
                            int   b,   // ponto de intercepção do eixo y (na prática, igual a v[0]) 
                            RESULTADO * res, // ponteiro para struct que armazena posicao e indicador de sucesso 
				            int   imprimir)
{
	//int achou =  0; // auxiliar para indicar se achou ou não o valor procurado 
	int     i;      // auxiliar de percurso do vetor, indica também a posição onde achou o valor 
    int     i_est;  // posição (primeira estimativa) do elemento procurado 

    // estimativa da posição do elemento procurado 
    //i_est = (int) ((c - b) / a);
    
    i_est = ( (c < b) ? 0 : (int) ((c - b) / a) );  // previne o caso em que i_est é negativo
    i_est = ( (i_est >= n) ? n-1 : i_est );         // previne o caso em que i_est está além do vetor
    
    cout << " Primeira posição analisada: " << i_est << " - valor " << v[i_est] << endl;

    // se encontrolu logo na posição estimada, pode finalizar 
    if ( c == v[i_est] ) {
        //achou = 1;
	    res->posicao = i_est;
	    res->achou = 1;
	    cout << " Posição " << res->posicao << " - valor " << v[res->posicao] << " - Achou... " << res->achou << endl;
        return;
    }

    // se o valor procurado é menor, é preciso voltar no vetor 
    if ( c < v[i_est] ) {
        for ( i=i_est-1; c < v[i] && i >= 0; i-- ) {
            //if ( c == v[i] ) {
              //  achou = 1;
            //}
            cout << " Posição " << i << " - valor " << v[i] << " - Achou... " << ((c == v[i]) ? 1 : 0) << endl;
        }
    }
    // se o valor procurado é maior, é preciso avançar no vetor 
    else {        // necessariamente tem-se aqui  c > v[i_est] 
        for ( i=i_est+1; c > v[i] && i < n; i++ ) {
            //if ( c == v[i] ) {
             //   achou = 1;
            //}
            cout << " Posição " << i << " - valor " << v[i] << " - Achou... " << ((c == v[i]) ? 1 : 0) << endl;
        }
    }
    res->posicao = i;
    if ( i >= 0 && i < n ) {
    	if ( c == v[i] ) {
       	   res->achou = 1;
    	}
    	cout << " Posição " << res->posicao << " - valor " << v[res->posicao] << " - Achou... " << res->achou << endl;		
	}
	else {
    	cout << " Posição " << res->posicao << " - Achou... " << res->achou << endl;		
	}
	if ( ! res->achou ) {
		cout << " Elemento não encontrado !" << endl;		
	}      
        
	return;
}

int main()
{

	// início: declarações dos vetores - alocação dinâmica 
	int   t1;    // tamanho do vetor 
	int * v1;    // ponteiro para o início do vetor na memória heap 

    char v;      // auxiliar para leituras de valores a partir do teclado 
    int  chave;  // auxiliar para buscas - valor procurado 
    RESULTADO r;

    int   intercepcao;  // parâmetros da reta de aproximação 
    float inclinacao;

    time_t start; // auxiliares para calculo da diferença de tempo com precisão de milissegundos 

	// para falar Português ...
	setlocale(LC_ALL,"Portuguese");
	
	// loop de testes 
	int repetir = 1;
	while ( repetir ) {
		
	    // criação do vetor para teste da busca proporcional 
        cout << endl;
        cout << " Informe o tamanho do vetor para testes da busca proporcional : ";
        cin  >> t1;
        cout << endl;
	
	    // alocação dinâmica 
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << " Problema na alocacao dinamica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }

	    // preenchimento do vetor com valores aleatórios 
	    //srand( (unsigned)1000000 ); // inicializa semente do gerador randomico de modo fixo 
	    srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico 

        // valor da posição inicial do vetor: número entre 0 e 10 
        v1[0] = rand()%10 ;
        for( int i=1 ; i < t1 ; i++ ) {
        	// sempre valores positivos, variação média entre 2 e 3, sem valores repetidos
    	    v1[i] = v1[i-1] + ( rand()%4 ) + 1; 
        }

        // cálculo e impressão dos parâmetros da reta de aproximação 
        intercepcao = v1[0];
        inclinacao  = (float) (v1[t1-1] - v1[0]) / (t1-1);

        cout << endl;
        cout << " Os parametros da reta sao: " << endl;
        cout << " Primeiro elemento do vetor : " << v1[0] << endl;
        cout << " Ultimo   elemento do vetor : " << v1[t1-1] << endl;
        cout << " a (inclinacao)  : " << inclinacao << endl;
        cout << " b (intercepcao) : " << intercepcao << endl;
        cout << " Pressione qualquer tecla para continuar ...";
        cin  >> v;
        cout << endl;

        // loop de buscas no mesmo vetor 
        for ( int j=0; j < QTD_TESTES; j++ ) {
        	// estabelecimento da chave de forma aleatória 
		    //chave = ( rand()%t1 ) + ( rand()%10 );  // valores positivos entre 0 e 9, numa posição qualquer do vetor
			////chave = rand()%(v1[t1-1]) + rand()%3;  

			cout << endl;
        	cout << " Informe o valor a ser buscado no vetor (entre 0 e " << v1[t1-1]+10 << ") : ";
        	cin  >> chave;
        	cout << endl;
	

            cout << endl;
            cout << " Vai chamar a busca para encontrar o valor " << chave << endl;

    	    // acionamento da busca proporcional 
    	    r.posicao = -1;
    	    r.achou = 0;
            busca_Proporcional_R( v1, t1, chave, inclinacao, intercepcao, &r, 0 );  // último número indica impressões intermediárias (1) ou não (0) 
            cout << " Ultima posicao : " << r.posicao << " - Achou ... " << r.achou << endl;
            cout << " Pressione qualquer tecla para continuar ...";
            cin  >> v;
            cout << endl;
        
        }

        // libera memória alocada para o vetor 
        free ( v1 );
        
        // decide se continua os testes ou não 
        cout << endl;
        cout << " Pressione S se quiser reiniciar os testes ou qualquer outra tecla para terminar. Depois, pressione <Enter> : ";
        cin  >> v;
        if ( v != 's' && v != 'S' )
            repetir = 0;
	}

    cout << endl;
   
    //cout << " Pressione qualquer tecla e depois <Enter> para sair: ";
    //cin  >> v;

    return 0;
}



