// -----------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: HEADERS, TYPES e DEFINES
// Ano/S : 2023/1S
// -----------------------------------------------

// arquivos de cabeçalhos
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// aliases C++ para entrada e saída
using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::fixed;

// definição de constantes genéricas
#define SIM      1
#define NAO      0
#define SUCESSO  0
#define ERRO    -1

// definição de constantes para escolha do método de ordenação
#define BOLHA_DIRETO            1
#define BOLHA_INVERTIDO         2
#define INSERCAO                3
#define SELECAO                 4
#define MESCLAGEM_NAO_RECURSIVO 5
#define MESCLAGEM_RECURSIVO     6
#define QUICK_RECURSIVO         7
#define MUDAR_METODO            8
#define SAIR                    9

// definição de constantes para escolha do tipo de teste do método de ordenação
#define FIXO                 1
#define GRANDE_1_ALEATORIO   2
#define GRANDE_2_ALEATORIO   3
#define GRANDE_1_DECRESCENTE 4
#define GRANDE_2_DECRESCENTE 5

// definição de indicador de execução automatica (sem diálogos)
#define AUTOMATICO SIM
