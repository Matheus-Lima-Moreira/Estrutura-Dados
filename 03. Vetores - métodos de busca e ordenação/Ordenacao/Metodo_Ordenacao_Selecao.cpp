// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: MÉTODO DE SELEÇÃO
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- Método da SELEÇÃO - Selection Sort --- 
// ------------------------------------------- 
void
  selection_sort (int a[],     // vetor (na prática: ponteiro para o início do vetor) 
                  int n,       // tamanho da porção do vetor que ainda não está ordenada 
			      int imprimir // chave para imprimir ou não os passos intermediários
			     )
  {
	int p, i, i_menor; // auxiliares de posição 
	int menor;         // auxiliar de menor valor 
    int barra = 0;     // posição da barra, inicialmente antes do primeiro elemento 
    
    // loop de passos 
	for (p = 1; p < n; p++)
	{
	    if ( imprimir ) cout << "Passo " << p << endl;
        // encontra o menor valor dentre os elementos não ordenados 
        menor = a[barra];
        i_menor = barra;
		for (i = barra+1; i < n; i++)
		{
			if (a[i] < menor)
			{
	  			menor = a[i];
	  			i_menor = i;
	  	    }
	  	}
	  	
		// troca o menor com o elemento ao lado direito da barra 
		a[i_menor] = a[barra];
	  	a[barra]   = menor;

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
