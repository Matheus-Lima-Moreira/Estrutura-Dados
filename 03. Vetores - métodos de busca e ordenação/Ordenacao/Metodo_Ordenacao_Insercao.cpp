// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: MÉTODO DE INSERÇÃO
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- Método da INSERÇÃO - Insertion Sort --- 
// -------------------------------------------- 
void
  insertion_sort (int a[],     // vetor (na prática: ponteiro para o início do vetor) 
                  int n,       // tamanho da porção do vetor que ainda não está ordenada 
			      int imprimir // chave para imprimir ou não os passos intermediários
				 )
  {
	int p, i;          // auxiliares de posição 
	int barra = 1;     // posição da barra, inicialmente depois do primeiro elemento 
    
    // loop de passos 
	for (p = 1; p < n; p++)
	{
	    if ( imprimir ) cout << "Passo " << p << endl;
        // transfere o elemento ao lado direito da barra para o lado esquerdo da barra (ordenados) 
        //elemento = a[barra];
        for (i = barra; i > 0  &&  a[i-1] > a[i]; i--) // percorre o vetor para trás dentro da barra 
		{
	  		// troca a posição dos dois elementos adjacentes 
	  		int t = a[i];
	  		a[i] = a[i - 1];
	  		a[i - 1] = t;
	  	}
	  	
		// avança a barra em uma posição 
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
