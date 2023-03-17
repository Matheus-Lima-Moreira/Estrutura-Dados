// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: MÉTODO QUICK SORT RECURSIVO (com TAIL)
// Ano/S : 2023/1S
// ------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

/* ---- Método da PARTIÇÃO - Quick Sort - Versão Recursiva ---- */
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

// Recursão comum
// A função recebe um vetor v[p..r], com p <= r+1,
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

// Recursão em 'cauda' (TAIL) - versão 1
// Utiliza loop 'while' e só chama um de cada vez
void quick_sort_tail_1(int arr[], int low, int high, int imprimir) 
{ 
	while (low < high) 
	{ 
		// pi é o índice (posição) da partição
		// arr[p] is now at right place
		int pi = separa(arr, low, high, imprimir); 

		// Ordena SEPARADAMENTE elementos 'antes' e 'depois' da partição 
		quick_sort_tail_1(arr, low, pi - 1, imprimir); 

		low = pi+1; 
	} 
} 
// See below link for complete running code 
// https://ide.geeksforgeeks.org/qrlM31 

// Recursão em 'cauda' (TAIL) - versão 2
// Requer espaço auxiliar O(Log n) no pior caso !
void quick_sort_tail_2(int arr[], int low, int high, int imprimir) 
{ 
	while (low < high) 
	{ 
		// pi é o índice (posição) da partição
		// arr[p] is now at right place
		int pi = separa(arr, low, high, imprimir); 

		// Se parte à esquerda é menor, tratá-la recursivamente
		// e lidar com a parte à dreita iterativamente 'while' 
		if (pi - low < high - pi) 
		{ 
			quick_sort_tail_2(arr, low, pi - 1, imprimir); 
			low = pi + 1; 
		} 

		// Caso contrário: recursão à direita, iteração à esquerda 
		else
		{ 
			quick_sort_tail_2(arr, pi + 1, high, imprimir); 
			high = pi - 1; 
		} 
	} 
} 
// See below link for complete running code 
// https://ide.geeksforgeeks.org/LHxwPk 
