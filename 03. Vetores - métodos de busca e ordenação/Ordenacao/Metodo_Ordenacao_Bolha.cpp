// ------------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: M�TODO DA BOLHA (NORMAL E INVERTIDO)
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabe�alhos, tipos e defini��es
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- M�todo da BOLHA - Bubble Sort - Percurso Esquerda -> Direita --- 
// --------------------------------------------------------------------- 
void
  bubble_sort (int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
               int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			   int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			  )
  {
	int i, trocou;     // auxiliares 
    int barra = n;     // posi��o da barra, inicialmente ap�s o �ltimo elemento 
    
    // loop de passos 
	do {
		// sup�e que neste passo ainda n�o houve troca 
		trocou = 0;
		// traz a barra em uma posi��o 
		--barra;
        if ( imprimir ) cout << "Passo " << n-barra << endl;
        // loop de trocas dentro do passo, at� a barra 
		for (i = 0; i < barra; i++)
		{
			if (a[i] > a[i + 1])
			{
	  			// troca a posi��o dos dois elementos adjacentes 
	  			int t = a[i];
	  			a[i] = a[i + 1];
	  			a[i + 1] = t;
	  			trocou = 1;
			}
		}

        if ( imprimir ) {
           cout << "Valor    de V1: [ " ;
           for (i=0; i<n; i++) {
              cout << a[i] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	} while (trocou);
  }

// ---- M�todo da BOLHA - Bubble Sort - Percurso Direita -> Esquerda --- 
// --------------------------------------------------------------------- 
void
  bubble_sort_invertido (int a[],     // vetor (na pr�tica: ponteiro para o in�cio do vetor) 
                         int n,       // tamanho da por��o do vetor que ainda n�o est� ordenada 
			             int imprimir // chave para imprimir ou n�o os passos intermedi�rios
			            )
  {
	int i, trocou;     // auxiliares 
    int barra = -1;    // posi��o da barra, inicialmente antes do primeiro elemento 
	
	// loop de passos 
    do {
		// sup�e que neste passo ainda n�o houve troca 
		trocou = 0;
		// avan�a a barra em uma posi��o 
		++barra;
        if ( imprimir ) cout << "Passo " << (barra+1) << endl;
        // loop de trocas dentro do passo, at� a barra 
		for (i = n-1; i > barra; i--)
		{
			if (a[i] < a[i - 1])
			{
	  			// troca a posi��o dos dois elementos adjacentes 
	  			int t = a[i];
	  			a[i] = a[i - 1];
	  			a[i - 1] = t;
	  			trocou = 1;
			}
		}

        if ( imprimir ) {
           cout << "Valor    de V1: [ " ;
           for (i=0; i<n; i++) {
              cout << a[i] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	} while (trocou);
  }
