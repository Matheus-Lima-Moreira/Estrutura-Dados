// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: MÉTODO DA BOLHA (NORMAL E INVERTIDO)
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

// ---- Método da BOLHA - Bubble Sort - Percurso Esquerda -> Direita --- 
// --------------------------------------------------------------------- 
void
  bubble_sort (int a[],     // vetor (na prática: ponteiro para o início do vetor) 
               int n,       // tamanho da porção do vetor que ainda não está ordenada 
			   int imprimir // chave para imprimir ou não os passos intermediários
			  )
  {
	int i, trocou;     // auxiliares 
    int barra = n;     // posição da barra, inicialmente após o último elemento 
    
    // loop de passos 
	do {
		// supõe que neste passo ainda não houve troca 
		trocou = 0;
		// traz a barra em uma posição 
		--barra;
        if ( imprimir ) cout << "Passo " << n-barra << endl;
        // loop de trocas dentro do passo, até a barra 
		for (i = 0; i < barra; i++)
		{
			if (a[i] > a[i + 1])
			{
	  			// troca a posição dos dois elementos adjacentes 
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

// ---- Método da BOLHA - Bubble Sort - Percurso Direita -> Esquerda --- 
// --------------------------------------------------------------------- 
void
  bubble_sort_invertido (int a[],     // vetor (na prática: ponteiro para o início do vetor) 
                         int n,       // tamanho da porção do vetor que ainda não está ordenada 
			             int imprimir // chave para imprimir ou não os passos intermediários
			            )
  {
	int i, trocou;     // auxiliares 
    int barra = -1;    // posição da barra, inicialmente antes do primeiro elemento 
	
	// loop de passos 
    do {
		// supõe que neste passo ainda não houve troca 
		trocou = 0;
		// avança a barra em uma posição 
		++barra;
        if ( imprimir ) cout << "Passo " << (barra+1) << endl;
        // loop de trocas dentro do passo, até a barra 
		for (i = n-1; i > barra; i--)
		{
			if (a[i] < a[i - 1])
			{
	  			// troca a posição dos dois elementos adjacentes 
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
