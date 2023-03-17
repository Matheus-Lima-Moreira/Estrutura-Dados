// ---------------------------------------------
// Nome : COLOQUE AQUI O SEU NOME COMPLETO
// R.A. : COLOQUE AQUI O SEU N�MERO DE MATR�CULA
// Turma: (   ) M     (   ) T     (   ) N
// ---------------------------------------------

// -----------------------------------------------
// Lab. : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// Ano/S: 2021/1S
// -----------------------------------------------

// Exemplos de m�todos de busca - proporcional
// (aproxima��o por reta)
// Busca retorna indicador de sucesso e posi��o (STRUCT)

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

using std::cout;
using std::endl;
using std::cin;

#define QTD_TESTES 10

typedef struct {     // struct � criada como vari�vel "global" para ser vis�vel para todos os m�todos e o 'main' 
    int posicao;
 	int achou;
} RESULTADO;

// BUSCA PROPORCIONAL - Aproxima��o por Reta 
// ----------------------------------------- 
void busca_Proporcional_R ( int   v[], // nome do vetor 
                            int   n,   // comprimento do vetor a ser utilizado nas buscas 
			                int   c,   // valor procurado 
                            float a,   //inclina��o da reta de aproxima��o 
                            int   b,   // ponto de intercep��o do eixo y (na pr�tica, igual a v[0]) 
                            RESULTADO * res, // ponteiro para struct que armazena posicao e indicador de sucesso 
				            int   imprimir)
{
	//int achou =  0; // auxiliar para indicar se achou ou n�o o valor procurado 
	int     i;      // auxiliar de percurso do vetor, indica tamb�m a posi��o onde achou o valor 
    int     i_est;  // posi��o (primeira estimativa) do elemento procurado 

    // estimativa da posi��o do elemento procurado 
    //i_est = (int) ((c - b) / a);
    
    i_est = ( (c < b) ? 0 : (int) ((c - b) / a) );  // previne o caso em que i_est � negativo
    i_est = ( (i_est >= n) ? n-1 : i_est );         // previne o caso em que i_est est� al�m do vetor
    
    cout << " Primeira posi��o analisada: " << i_est << " - valor " << v[i_est] << endl;

    // se encontrolu logo na posi��o estimada, pode finalizar 
    if ( c == v[i_est] ) {
        //achou = 1;
	    res->posicao = i_est;
	    res->achou = 1;
	    cout << " Posi��o " << res->posicao << " - valor " << v[res->posicao] << " - Achou... " << res->achou << endl;
        return;
    }

    // se o valor procurado � menor, � preciso voltar no vetor 
    if ( c < v[i_est] ) {
        for ( i=i_est-1; c < v[i] && i >= 0; i-- ) {
            //if ( c == v[i] ) {
              //  achou = 1;
            //}
            cout << " Posi��o " << i << " - valor " << v[i] << " - Achou... " << ((c == v[i]) ? 1 : 0) << endl;
        }
    }
    // se o valor procurado � maior, � preciso avan�ar no vetor 
    else {        // necessariamente tem-se aqui  c > v[i_est] 
        for ( i=i_est+1; c > v[i] && i < n; i++ ) {
            //if ( c == v[i] ) {
             //   achou = 1;
            //}
            cout << " Posi��o " << i << " - valor " << v[i] << " - Achou... " << ((c == v[i]) ? 1 : 0) << endl;
        }
    }
    res->posicao = i;
    if ( i >= 0 && i < n ) {
    	if ( c == v[i] ) {
       	   res->achou = 1;
    	}
    	cout << " Posi��o " << res->posicao << " - valor " << v[res->posicao] << " - Achou... " << res->achou << endl;		
	}
	else {
    	cout << " Posi��o " << res->posicao << " - Achou... " << res->achou << endl;		
	}
	if ( ! res->achou ) {
		cout << " Elemento n�o encontrado !" << endl;		
	}      
        
	return;
}

int main()
{

	// in�cio: declara��es dos vetores - aloca��o din�mica 
	int   t1;    // tamanho do vetor 
	int * v1;    // ponteiro para o in�cio do vetor na mem�ria heap 

    char v;      // auxiliar para leituras de valores a partir do teclado 
    int  chave;  // auxiliar para buscas - valor procurado 
    RESULTADO r;

    int   intercepcao;  // par�metros da reta de aproxima��o 
    float inclinacao;

    time_t start; // auxiliares para calculo da diferen�a de tempo com precis�o de milissegundos 

	// para falar Portugu�s ...
	setlocale(LC_ALL,"Portuguese");
	
	// loop de testes 
	int repetir = 1;
	while ( repetir ) {
		
	    // cria��o do vetor para teste da busca proporcional 
        cout << endl;
        cout << " Informe o tamanho do vetor para testes da busca proporcional : ";
        cin  >> t1;
        cout << endl;
	
	    // aloca��o din�mica 
	    v1 = (int *) malloc ( t1 * sizeof (int) );
	    if ( v1 == 0 ) {
		    cout << endl;   
            cout << " Problema na alocacao dinamica !!! Pressione qualquer tecla e depois <Enter> para sair: ";
            cin  >> v;
            return -1;
	    }

	    // preenchimento do vetor com valores aleat�rios 
	    //srand( (unsigned)1000000 ); // inicializa semente do gerador randomico de modo fixo 
	    srand( (unsigned)time(&start) ); // inicializa semente do gerador randomico 

        // valor da posi��o inicial do vetor: n�mero entre 0 e 10 
        v1[0] = rand()%10 ;
        for( int i=1 ; i < t1 ; i++ ) {
        	// sempre valores positivos, varia��o m�dia entre 2 e 3, sem valores repetidos
    	    v1[i] = v1[i-1] + ( rand()%4 ) + 1; 
        }

        // c�lculo e impress�o dos par�metros da reta de aproxima��o 
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
        	// estabelecimento da chave de forma aleat�ria 
		    //chave = ( rand()%t1 ) + ( rand()%10 );  // valores positivos entre 0 e 9, numa posi��o qualquer do vetor
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
            busca_Proporcional_R( v1, t1, chave, inclinacao, intercepcao, &r, 0 );  // �ltimo n�mero indica impress�es intermedi�rias (1) ou n�o (0) 
            cout << " Ultima posicao : " << r.posicao << " - Achou ... " << r.achou << endl;
            cout << " Pressione qualquer tecla para continuar ...";
            cin  >> v;
            cout << endl;
        
        }

        // libera mem�ria alocada para o vetor 
        free ( v1 );
        
        // decide se continua os testes ou n�o 
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



