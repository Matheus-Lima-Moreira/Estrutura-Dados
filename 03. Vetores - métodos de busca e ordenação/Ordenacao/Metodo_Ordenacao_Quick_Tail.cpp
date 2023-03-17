// ------------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: M�TODO QUICK SORT RECURSIVO (com TAIL)
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabe�alhos, tipos e defini��es
#include "Atividade_HEADERS_TYPES_DEFINES.h"

/* ---- M�todo da PARTI��O - Quick Sort - Vers�o Recursiva ---- */
/* ------------------------------------------------------------ */
// Recebe vetor v[p..r] com p < r. Rearranja os elementos do vetor e
// devolve j em p..r tal que v[p..j-1] <= v[j] < v[j+1..r].

int
separa( int v[], int p, int r, int imprimir)
{
   int c = v[p], i = p+1, j = r, t;
   while (/*A*/ i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1                 
   v[p] = v[j], v[j] = c;

        if ( imprimir ) {
           cout << "Valor    de V1: [ " ;
           for (i=0; i<8; i++) {
              cout << v[i] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }



   return j; 
}

// Recurs�o comum
// A fun��o recebe um vetor v[p..r], com p <= r+1,
// e rearranja o vetor em ordem crescente.

void 
quick_sort( int v[], int p, int r, int imprimir)
{
   int j;                         // 1
   if (p < r) {                   // 2
      j = separa( v, p, r, imprimir);       // 3
      quick_sort( v, p, j-1, imprimir);      // 4
      quick_sort( v, j+1, r, imprimir);      // 5
   }
   return;
}

// Recurs�o em 'cauda' (TAIL) - vers�o 1
// Utiliza loop 'while' e s� chama um de cada vez
void quick_sort_tail_1(int arr[], int low, int high, int imprimir) 
{ 
	while (low < high) 
	{ 
		// pi � o �ndice (posi��o) da parti��o
		// arr[p] is now at right place
		int pi = separa(arr, low, high, imprimir); 

		// Ordena SEPARADAMENTE elementos 'antes' e 'depois' da parti��o 
		quick_sort_tail_1(arr, low, pi - 1, imprimir); 

		low = pi+1; 
	} 
} 
// See below link for complete running code 
// https://ide.geeksforgeeks.org/qrlM31 

// Recurs�o em 'cauda' (TAIL) - vers�o 2
// Requer espa�o auxiliar O(Log n) no pior caso !
void quick_sort_tail_2(int arr[], int low, int high, int imprimir) 
{ 
	while (low < high) 
	{ 
		// pi � o �ndice (posi��o) da parti��o
		// arr[p] is now at right place
		int pi = separa(arr, low, high, imprimir); 

		// Se parte � esquerda � menor, trat�-la recursivamente
		// e lidar com a parte � dreita iterativamente 'while' 
		if (pi - low < high - pi) 
		{ 
			quick_sort_tail_2(arr, low, pi - 1, imprimir); 
			low = pi + 1; 
		} 

		// Caso contr�rio: recurs�o � direita, itera��o � esquerda 
		else
		{ 
			quick_sort_tail_2(arr, pi + 1, high, imprimir); 
			high = pi - 1; 
		} 
	} 
} 
// See below link for complete running code 
// https://ide.geeksforgeeks.org/LHxwPk 
