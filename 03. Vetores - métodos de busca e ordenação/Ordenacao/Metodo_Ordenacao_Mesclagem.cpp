// --------------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: M�TODO MERGE SORT SIMPLIFICADO E RECURSIVO
// Ano/S : 2023/1S
// --------------------------------------------------

// arquivo com cabe�alhos, tipos e defini��es
#include "Atividade_HEADERS_TYPES_DEFINES.h"

/* ---- M�todo da MESCLAGEM - Merge Sort --- */
/* ----------------------------------------- */
void
  merge_sort (int a[],     /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - primeira metade */
              int na,      /* tamanho da primeira metade - j� est� ordenada */
              int b[],     /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - segunda metade */
              int nb,      /* tamanho da segunda metade  - j� est� ordenada */
              int f[],     /* vetor que ser� efetivamente ordenado, recebendo os valores mesclados das duas metades */
			  int imprimir /* chave para imprimir ou n�o os passos intermedi�rios */)
  {
	int i=0, j=0, p = 0;       /* auxiliares de posi��o: i (primeira metade), j(segunda metade), p (vetor final) */

    
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
		   int pp;                    /* auxiliar de impress�o */
		   cout << "Valor    de V1: [ " ;
           for (pp=0; pp<(na+nb); pp++) {
              cout << f[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	}
  }

/* ---- M�todo da MESCLAGEM - Merge Sort - Vers�o Recursiva ---- */
/* ------------------------------------------------------------- */
void
  merge_sort_r ( int f[],     /* vetor que ser� efetivamente ordenado, recebendo os valores mesclados das duas metades */
                 int nf,      /* tamanho do vetor f */
			     int imprimir /* chave para imprimir ou n�o os passos intermedi�rios */)
  {

	/* impress�o opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impress�o */
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
	
	/* RECURS�O */
	int * a;    /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - primeira metade */
	int na;     /* tamanho da primeira metade - j� est� ordenada */
	int * b;    /* vetor (na pr�tica: ponteiro para o in�cio do vetor) - segunda metade */
	int nb;     /* tamanho da segunda metade  - j� est� ordenada */
	int i, j, p;/* auxiliares de posi��o: i (primeira metade), j(segunda metade), p (vetor final) */

    /* cria a primeira metade do vetor */
    na = nf / 2;
    a = (int *) malloc(na*sizeof(int));
	for (i=0; i<na; i++) {
		a[i] = f[i];
	}
	/* impress�o opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impress�o */
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
	/* impress�o opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impress�o */
		   cout << "ENTRADA - Valor    de b: [ " ;
           for (pp=0; pp<nb; pp++) {
              cout << b[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

	
	/* aciona a ordena��o recursiva para cada metade */
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
	/* impress�o opcional */	
        if ( imprimir ) {
		   int pp;                    /* auxiliar de impress�o */
		   cout << "SAIDA - Valor    de f: [ " ;
           for (pp=0; pp<nf; pp++) {
              cout << f[pp] << "  ";
           }
           cout << " ]"  << endl;;
           cout << endl;
        }

		return;
  }
