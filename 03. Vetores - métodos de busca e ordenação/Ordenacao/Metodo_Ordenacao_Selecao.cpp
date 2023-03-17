// ------------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: M�TODO DE SELE��O
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabe�alhos, tipos e defini��es
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- M�todo da SELE��O - Selection Sort --- 
// ------------------------------------------- 
void
  selection_sort (int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                  int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			      int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			     )
  {
	int p, i, i_menor; // auxiliares de posi��o 
	int menor;         // auxiliar de menor valor 
    int barra = 0;     // posi��o da barra, inicialmente antes do primeiro elemento 
    
    // loop de passos 
	for (p = 1; p < n; p++)
	{
	    if ( imprimir ) cout << "Passo " << p << endl;
        // encontra o menor valor dentre os elementos n�o ordenados 
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
