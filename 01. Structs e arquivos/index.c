// -------------------------------------------------
// Disc.: ESTRUTURAS DE DADOS - IED-001
// Lab. : STRUCTS, ARQUIVOS-TEXTO, ARQUIVOS BINÁRIOS
// Ano/S: 2023/1S
// -------------------------------------------------

// arquivos de cabeçalhos ('header') - AMBIENTE
#include <locale.h>
#include <stdio.h>

// arquivos de cabeçalhos ('header') - PRÓPRIOS
#include "Lab_Structs_TYPES_DEFINES.h"

// -------------------------------------------------------------------------
//                           funções e procedimentos
// -------------------------------------------------------------------------

// Uso geral - exibição de dados do autor do trabalho
// --------------------------------------------------
void exibe_dados_autor()
{
    // identificação do autor do trabalho
    printf("\n");
    printf("---------------------------------\n");
    printf("ESTRUTURAS DE DADOS - 2023/1S\n");
    printf("Lab.: STRUCTS e ARQUIVOS\n");
    printf("---------------------------------\n");
    printf("Nome: MATHEUS DE LIMA MOREIRA\n");
    printf("R.A.: 121 048 221 2 016\n");
    printf("---------------------------------\n");

    // finalização (desnecessário neste caso, pois é procedimento 'void')
    return;
}

// Atividade 1 - memória para tipos primitivos e 'structs'
// -------------------------------------------------------
void mapeia_memoria()
{
    // declaração de tipo primitivo - INTEIRO
    int x1;
    int x2;

    // atribuição de valor
    x1 = 3;
    x2 = 8;

    // impressões: conteúdo, qtd bytes na memória, endereço
    printf("\nTipo INTEIRO");
    printf("\n------------\n");
    printf("int x1 - endereço #%p - qtd. bytes %d - conteúdo %d\n", &x1,
           sizeof(x1), x1);
    printf("int x2 - endereço #%p - qtd. bytes %d - conteúdo %d\n", &x2,
           sizeof(x2), x2);
    printf("\n");

    // declaração de tipo primitivo - FLOAT (real de precisão simples)
    float f1;
    float f2;

    // atribuição de valor
    f1 = 3.45;
    f2 = 8.794;

    // impressões: conteúdo, qtd bytes na memória, endereço
    printf("\nTipo FLOAT");
    printf("\n----------\n");
    printf("float f1 - endereço #%p - qtd. bytes %d - conteúdo %f\n", &f1,
           sizeof(f1), f1);
    printf("float f2 - endereço #%p - qtd. bytes %d - conteúdo %f\n", &f2,
           sizeof(f2), f2);
    printf("\n");

    // declaração de tipo primitivo - DOUBLE (real de precisão dupla)
    double d1;
    double d2;

    // atribuição de valor
    d1 = 9.754;
    d2 = 1.238;

    // impressões: conteúdo, qtd bytes na memória, endereço
    printf("\nTipo DOUBLE");
    printf("\n-----------\n");
    printf("double d1 - endereço #%p - qtd. bytes %d - conteúdo %lf\n", &d1,
           sizeof(d1), d1);
    printf("double d2 - endereço #%p - qtd. bytes %d - conteúdo %lf\n", &d2,
           sizeof(d2), d2);
    printf("\n");

    // declaração de tipo primitivo - CHAR (caracter isolado)
    char c1;
    char c2;

    // atribuição de valor
    c1 = 'A';
    c2 = 'B';

    // impressões: conteúdo, qtd bytes na memória, endereço
    printf("\nTipo CHAR");
    printf("\n---------\n");
    printf("char c1 - endereço #%p - qtd. bytes %d - conteúdo %c\n", &c1,
           sizeof(c1), c1);
    printf("char c2 - endereço #%p - qtd. bytes %d - conteúdo %c\n", &c2,
           sizeof(c2), c2);
    printf("\n");

    // definição (especificação ou explicação para o compilador) de 'struct'
    // NÃO PRECISA MAIS, PORQUE FOI FEITO NO ARQUIVO INCLUÍDO -> TYPES_DEFINES.h
    /*
        typedef struct {
            int    codigo;
            char   status;
            double renda;
        } CLIENTE;
    */

    // declaração de variável do tipo CLIENTE
    CLIENTE cli1;
    CLIENTE cli2;

    // atribuição de valores
    cli1.codigo = 1;
    cli1.renda = 1000.0;
    cli1.status = 'F';

    cli2.codigo = 2;
    cli2.renda = 2000.0;
    cli2.status = 'G';

    // impressões: conteúdo, qtd bytes na memória, endereço
    printf("\nTipo CLIENTE (struct)");
    printf("\n---------------------\n");
    printf("CLIENTE cli1 - endereço #%p - qtd. bytes %d\n", &cli1,
           sizeof(cli1));
    printf("CLIENTE cli2 - endereço #%p - qtd. bytes %d\n", &cli2,
           sizeof(cli2));
    printf("\n");

    // impressão campo a campo - CLIENTE cli1
    printf("campo cli1.codigo - endereço #%p - qtd. bytes %d - conteúdo %d\n",
           &(cli1.codigo), sizeof(cli1.codigo), cli1.codigo);
    printf("campo cli1.status - endereço #%p - qtd. bytes %d - conteúdo %c\n",
           &(cli1.status), sizeof(cli1.status), cli1.status);
    printf("campo cli1.renda  - endereço #%p - qtd. bytes %d - conteúdo %lf\n",
           &(cli1.renda), sizeof(cli1.renda), cli1.renda);
    printf("\n");

    // impressão campo a campo - CLIENTE cli2
    printf("campo cli2.codigo - endereço #%p - qtd. bytes %d - conteúdo %d\n",
           &(cli2.codigo), sizeof(cli2.codigo), cli2.codigo);
    printf("campo cli2.status - endereço #%p - qtd. bytes %d - conteúdo %c\n",
           &(cli2.status), sizeof(cli2.status), cli2.status);
    printf("campo cli2.renda  - endereço #%p - qtd. bytes %d - conteúdo %lf\n",
           &(cli2.renda), sizeof(cli2.renda), cli2.renda);
    printf("\n");

    // finalização (desnecessário neste caso, pois é procedimento 'void')
    return;
}

// Atividade 3 - gravação de arquivo-texto
// ---------------------------------------
int grava_arquivo_texto()
{
    // declarações de variáveis
    int x1;
    float f1;
    char c1;
    FILE *arquivo; // dá acesso ao arquivo físico

    // atribuições de valores
    x1 = 1750;
    f1 = 209.47;
    c1 = 'A';

    // abertura do arquivo no modo GRAVAÇÃO
    // atenção
    // 1. se o arquivo não existe, este comando CRIA o arquivo
    // 2. se o arquivo já existe, este comando LIMPA o arquivo
    arquivo = fopen("Ativ_3.txt", "w");

    // se o comanddo de abertura falhou, retornar -1
    if (arquivo == NULL)
    {
        return -1;
    }

    // gravação dos valores das variáveis
    fprintf(arquivo, "%d %f %c", x1, f1, c1);

    // fechamento do arquivo
    fclose(arquivo);

    // finalização
    return 0;
}

// Atividade 4 - leitura de arquivo-texto
// --------------------------------------
int le_arquivo_texto()
{
    // finalização
    return 0;
}

// Atividade 5 - gravação de arquivo binário
// -----------------------------------------
int grava_arquivo_binario()
{
    // declarações de variáveis
    CLIENTE cli;
    FILE *arquivo; // dá acesso ao arquivo físico

    // atribuições de valores
    cli.codigo = 1750;
    cli.renda = 2000.4;
    cli.status = 'Z';

    // abertura do arquivo no modo GRAVAÇÃO
    // atenção
    // 1. se o arquivo não existe, este comando CRIA o arquivo
    // 2. se o arquivo já existe, este comando LIMPA o arquivo
    arquivo = fopen("Ativ_5.txt", "w");

    // se o comanddo de abertura falhou, retornar -1
    if (arquivo == NULL)
    {
        return -1;
    }

    // gravação dos valores das variáveis
    fwrite(&cli, sizeof(cli), 1, arquivo);

    // fechamento do arquivo
    fclose(arquivo);

    // finalização
    return 0;
}

// Atividade 6 - leitura de arquivo binário
// ----------------------------------------
int le_arquivo_binario()
{
    // finalização
    return 0;
}

// programa principal
// ------------------
int main()
{
    // para falar Português ...
    setlocale(LC_ALL, "Portuguese");

    // declaração de variáveis
    int escolha;
    int retorno;

    // menu de escolha da Atividade a ser executada
    do
    {
        // apresentação do menu
        printf("\nMenu de opções:\n");
        printf("---------------\n");
        printf("1 - Atividade 1: Memória para tipos primitivos e structs\n");
        printf("3 - Atividade 3: Gravação de arquivo-texto\n");
        printf("4 - Atividade 4: Leitura  de arquivo-texto\n");
        printf("5 - Atividade 5: Gravação de arquivo binário\n");
        printf("6 - Atividade 6: Leitura  de arquivo binário\n");
        printf("9 - Sair ...\n");

        // coleta da opção desejada pelo usuário
        printf("\nInforme o que deseja fazer: ");
        scanf("%d", &escolha);

        // execução da ação desejada
        switch (escolha)
        {
        case 1:
            printf("\nAtividade 1 ...\n");
            // código da Atividade 1
            mapeia_memoria();
            // identificação do autor do trabalho
            exibe_dados_autor();
            break;

            /* opção inválida neste Lab
            case 2:
                printf("\nAtividade 2 ...\n");
                // código da Atividade 2
                break;
            */

        case 3:
            printf("\nAtividade 3 ...\n");
            // código da Atividade 3
            retorno = grava_arquivo_texto();
            if (retorno == -1)
            {
                printf(
                    "\nERRO na abertura do arquivo-texto para GRAVAÇÃO "
                    "!!!\n");
            }
            else
            {
                printf("\nArquivo-texto gravado com sucesso !!!\n");
            }
            break;
        case 4:
            printf("\nAtividade 4 ... AINDA NÃO IMPLEMENTADA !\n");
            // código da Atividade 4
            break;
        case 5:
            printf("\nAtividade 5 ...\n");
            // código da Atividade 5
            retorno = grava_arquivo_binario();
            if (retorno == -1)
            {
                printf(
                    "\nERRO na abertura do arquivo-binário para GRAVAÇÃO "
                    "!!!\n");
            }
            else
            {
                printf("\nArquivo-binário gravado com sucesso !!!\n");
            }
            break;
        case 6:
            printf("\nAtividade 6 ... AINDA NÃO IMPLEMENTADA !\n");
            // código da Atividade 6
            break;
        case 9:
            printf("\nSair !\n");
            break;
        default:
            printf("\nOpção inválida !\n");
            break; // desnecessário neste caso
        }

    } while (escolha != 9);

    // finalização
    return 0;
}