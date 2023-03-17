// ------------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: M�TODO DE INSER��O
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabe�alhos, tipos e defini��es
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- M�todo da INSER��O - Insertion Sort --- 
// -------------------------------------------- 
void
  insertion_sort (int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                  int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			      int imprimir // chave para imprimir ou n�o os passos intermedi�rios
				 )
  {
	int p, i;          // auxiliares de posi��o 
	int barra = 1;     // posi��o da barra, inicialmente depois do primeiro elemento 
    
    // loop de passos 
	for (p = 1; p < n; p++)
	{
	    if ( imprimir ) cout << "Passo " << p << endl;
        // transfere o elemento ao lado direito da barra para o lado esquerdo da barra (ordenados) 
        //elemento = a[barra];
        for (i = barra; i > 0  &&  a[i-1] > a[i]; i--) // percorre o vetor para tr�s dentro da barra 
		{
	  		// troca a posi��o dos dois elementos adjacentes 
	  		int t = a[i];
	  		a[i] = a[i - 1];
	  		a[i - 1] = t;
	  	}
	  	
		// avan�a a barra em uma posi��o 
		barra++;
		
        if ( imprimir ) {
           cout << "Valor    de V1: [ " ;
           for (i=0; i<n; i++) {
              cout << a[i] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	}
  }  
