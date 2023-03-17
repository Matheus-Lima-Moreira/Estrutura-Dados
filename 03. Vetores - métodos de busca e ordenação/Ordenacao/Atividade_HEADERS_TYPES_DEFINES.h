// -----------------------------------------------
// Lab.  : VETORES - OPERA��ES DE BUSCA E ORDENA��O
// C�digo: HEADERS, TYPES e DEFINES
// Ano/S : 2023/1S
// -----------------------------------------------

// arquivos de cabe�alhos
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// aliases C++ para entrada e sa�da
using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::fixed;

// defini��o de constantes gen�ricas
#define SIM      1
#define NAO      0
#define SUCESSO  0
#define ERRO    -1

// defini��o de constantes para escolha do m�todo de ordena��o
#define BOLHA_DIRETO            1
#define BOLHA_INVERTIDO         2
#define INSERCAO                3
#define SELECAO                 4
#define MESCLAGEM_NAO_RECURSIVO 5
#define MESCLAGEM_RECURSIVO     6
#define QUICK_RECURSIVO         7
#define MUDAR_METODO            8
#define SAIR                    9

// defini��o de constantes para escolha do tipo de teste do m�todo de ordena��o
#define FIXO                 1
#define GRANDE_1_ALEATORIO   2
#define GRANDE_2_ALEATORIO   3
#define GRANDE_1_DECRESCENTE 4
#define GRANDE_2_DECRESCENTE 5

// defini��o de indicador de execu��o automatica (sem di�logos)
#define AUTOMATICO SIM
