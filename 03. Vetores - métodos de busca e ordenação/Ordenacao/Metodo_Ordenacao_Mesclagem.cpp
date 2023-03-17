// --------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: MÉTODO MERGE SORT SIMPLIFICADO E RECURSIVO
// Ano/S : 2023/1S
// --------------------------------------------------

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"

/* ---- Método da MESCLAGEM - Merge Sort --- */
/* ----------------------------------------- */
void
  merge_sort (int a[],     /* vetor (na prática: ponteiro para o início do vetor) - primeira metade */
              int na,      /* tamanho da primeira metade - já está ordenada */
              int b[],     /* vetor (na prática: ponteiro para o início do vetor) - segunda metade */
              int nb,      /* tamanho da segunda metade  - já está ordenada */
              int f[],     /* vetor que será efetivamente ordenado, recebendo os valores mesclados das duas metades */
			  int imprimir /* chave para imprimir ou não os passos intermediários */)
  {
	int i=0, j=0, p = 0;       /* auxiliares de posição: i (primeira metade), j(segunda metade), p (vetor final) */

    
    /* loop de passos */
	while ( p < (na+nb) )
	{
	    if ( imprimir ) cout << "Passo " << (p+1) << endl;
        
        if ( a[i] <= b[j] ) {
			f[p] = a[i];
			i++;
			if ( i == na ) {
				while ( j < nb ) {
					p++;
					f[p] = b[j];
					j++;
				}
			}
		}
		else {
			f[p] = b[j];
			j++;
			if ( j == nb ) {
				while ( i < na ) {
					p++;
					f[p] = a[i];
					i++;
				}
			}
		}
		
        p++;
        
        	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impressão */
		   cout << "Valor    de V1: [ " ;
           for (pp=0; pp<(na+nb); pp++) {
              cout << f[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	}
  }

/* ---- Método da MESCLAGEM - Merge Sort - Versão Recursiva ---- */
/* ------------------------------------------------------------- */
void
  merge_sort_r ( int f[],     /* vetor que será efetivamente ordenado, recebendo os valores mesclados das duas metades */
                 int nf,      /* tamanho do vetor f */
			     int imprimir /* chave para imprimir ou não os passos intermediários */)
  {

	/* impressão opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impressão */
		   cout << "ENTRADA - Valor    de f: [ " ;
           for (pp=0; pp<nf; pp++) {
              cout << f[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	/* CASO BASE: nf == 1 (nada a fazer) */
	if ( nf == 1 )
		return;
	
	/* RECURSÃO */
	int * a;    /* vetor (na prática: ponteiro para o início do vetor) - primeira metade */
	int na;     /* tamanho da primeira metade - já está ordenada */
	int * b;    /* vetor (na prática: ponteiro para o início do vetor) - segunda metade */
	int nb;     /* tamanho da segunda metade  - já está ordenada */
	int i, j, p;/* auxiliares de posição: i (primeira metade), j(segunda metade), p (vetor final) */

    /* cria a primeira metade do vetor */
    na = nf / 2;
    a = (int *) malloc(na*sizeof(int));
	for (i=0; i<na; i++) {
		a[i] = f[i];
	}
	/* impressão opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impressão */
		   cout << "ENTRADA - Valor    de a: [ " ;
           for (pp=0; pp<na; pp++) {
              cout << a[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	
    /* cria a segunda metade do vetor */
    nb = nf - na;
    b = (int *) malloc(nb*sizeof(int));
	for (j=na; j<nf; j++) {
		b[j-na] = f[j];
	}
	/* impressão opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impressão */
		   cout << "ENTRADA - Valor    de b: [ " ;
           for (pp=0; pp<nb; pp++) {
              cout << b[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	
	/* aciona a ordenação recursiva para cada metade */
	merge_sort_r( a, na, imprimir );
	merge_sort_r( b, nb, imprimir ); 

    /* mescla as metades, reconstruindo f */
    /* loop de passos */
    i = 0;
    j = 0;
    p = 0;
	while ( p < nf )
	{
	    if ( imprimir ) cout << "Passo " << (p+1) << endl;
        
        if ( a[i] <= b[j] ) {
			f[p] = a[i];
			i++;
			if ( i == na ) {
				while ( j < nb ) {
					p++;
					f[p] = b[j];
					j++;
				}
			}
		}
		else {
			f[p] = b[j];
			j++;
			if ( j == nb ) {
				while ( i < na ) {
					p++;
					f[p] = a[i];
					i++;
				}
			}
		}
		
        p++;
                	
	}
	/* impressão opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impressão */
		   cout << "SAIDA - Valor    de f: [ " ;
           for (pp=0; pp<nf; pp++) {
              cout << f[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

		return;
  }
