// ------------------------------------------------
// Lab.  : VETORES - OPERAÇÕES DE BUSCA E ORDENAÇÃO
// Código: PROGRAMA PRINCIPAL
// Ano/S : 2023/1S
// ------------------------------------------------

// Atividade - Métodos de ordenação de vetores
// Programa para verificar tempo de execução dos algoritmos de ordenação:
// - Bolha     ("Bubble    sort") - versão esquerda->direita
// - Bolha     ("Bubble    sort") - versão direita->esquerda
// - Inserção  ("Insertion sort")
// - Seleção   ("Selection sort")
// - Mesclagem ("Merge     sort") - versão não recursiva
// - Mesclagem ("Merge     sort") - versão recursiva
// - Partição  ("Quick     sort") - versão recursiva

// arquivo com cabeçalhos, tipos e definições
#include "Atividade_HEADERS_TYPES_DEFINES.h"
  
// arquivo com prototypes de funções e procedimentos
#include "Atividade_PROTOTYPES.h"
  
// ------------------    
// Programa principal
// ------------------
int main()
{
   #ifndef AUTOMATICO
   int V1[8];        // primeiro vetor-exemplo
   #endif
   int T1[20000];    // caso grande com N elementos
   int T2[40000];    // caso grande com 2*N elementos
   
   // time_t start,end; // auxiliares para calculo da diferença de tempo com precisão de segundos
   // float diferenca;  // diferença de tempo com precisão de segundos
   
   clock_t start2,end2;// auxiliares para calculo da diferença de tempo com precisão de milissegundos
   float diferenca2;   // diferença de tempo com precisão de milissegundos
   
   // auxiliares para o controle da execução
   int metodo = 0;
   int teste  = 0;
   
   const char m1[] = "BOLHA (esquerda->direita)\0";
   const char m2[] = "BOLHA (direita->esquerda)\0";
   const char m3[] = "INSERÇÃO\0";
   const char m4[] = "SELEÇÃO\0";
   const char m5[] = "MESCLAGEM (não recursivo)\0";
   const char m6[] = "MESCLAGEM (recursivo)\0";
   const char m7[] = "QUICKSORT (recursivo)\0";
   
   #ifndef AUTOMATICO
   const char t1[] = "FIXO\0";
   #endif
   const char t2[] = "20000 ALEATÓRIO\0";
   const char t3[] = "20000 DECRESCENTE\0";
   const char t4[] = "40000 ALEATÓRIO\0";
   const char t5[] = "40000 DECRESCENTE\0";
   
   // para falar Português ...
   setlocale(LC_ALL,"Portuguese");
   
   #ifdef AUTOMATICO
   // impressão da linha separadora da tabela-resumo
   imprime_separador();
   // impressão do cabeçalho da tabela-resumo
   imprime_cabecalho();
   // impressão da linha separadora da tabela-resumo
   imprime_separador();
   #endif

   // loop principal do programa
   do {
	    // escolha do método de ordenação a ser executado
	    #ifndef AUTOMATICO
		metodo = escolhe_metodo();
		#else
	    metodo = escolhe_metodo_2(metodo);
	    teste = 1;
	    #endif
	   
 	    // análise da escolha do método
		switch( metodo ) {
			
			// ordenação por BOLHA (esquerda->direita) 
			// --------------------------------------- 
			case BOLHA_DIRETO   :
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m1 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m1 );
							bubble_sort( V1, 8, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m1 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m1 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							bubble_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m1 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m1 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m1 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m1 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m1 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m1 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
							
				break;

			// ordenação por BOLHA (direita->esquerda) 
			// --------------------------------------- 
			case BOLHA_INVERTIDO :
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m2 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m2 );
							bubble_sort_invertido( V1, 8, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m2 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m2 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							bubble_sort_invertido( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif

							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m2 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m2 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort_invertido( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m2 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m2 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort_invertido( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m2 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m2 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							bubble_sort_invertido( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;
							
			// ordenação por INSERÇÃO
			// ---------------------- 
			case INSERCAO:
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m3 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m3 );
							insertion_sort( V1, 8, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m3 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m3 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							insertion_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m3 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m3 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							insertion_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m3 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m3 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							insertion_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m3 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m3 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							insertion_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;
		
			// ordenação por SELEÇÃO
			// --------------------- 
			case SELECAO :
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m4 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m4 );
							selection_sort( V1, 8, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m4 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m4 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							selection_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m4 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m4 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							selection_sort( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m4 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m4 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							selection_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m4 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m4 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							selection_sort( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;
			
			// ordenação por MESCLAGEM NÃO RECURSIVO
			// ------------------------------------- 
			case MESCLAGEM_NAO_RECURSIVO :
				int i;            // auxiliar de percurso
				int T1A[10000];   // auxiliares para as metades do VETOR GRANDE_1
				int T1B[10000];   // a serem ordenadas separadamente
				int T2A[20000];   // auxiliares para as metades do VETOR GRANDE_2
				int T2B[20000];   // a serem ordenadas separadamente
				#ifndef AUTOMATICO
				int V1A[4];       // auxiliares para as metades do VETOR FIXO
				int V1B[4];       // a serem ordenadas separadamente
				#endif

				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m5 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m5 );
   		   	   	   	   	    // construção dos vetores auxiliares:
							// V1A (primeira metade) e V1B (segunda metade)
							for (i=0; i<4; i++) {
								V1A[i] = V1[i];
								V1B[i] = V1[i+4];
							}
		   	   	   	   	    // ordenação por MESCLAGEM - vetor V1
							// utilizando ordenacao por SELECAO para o vetor dividido
							selection_sort( V1A, 4, 1 ); // imprime passos intermediários
							selection_sort( V1B, 4, 1 ); // imprime passos intermediários
							// montagem do vetor V1 ordenado a partir das duas metades
							merge_sort( V1A, 4, V1B, 4, V1, 1 ); // imprime passos intermediários
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m5 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m5 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
   		   	   	   	   	    // construção dos vetores auxiliares:
							// T1A (primeira metade) e T1B (segunda metade)
							for (i=0; i<10000; i++) {
								T1A[i] = T1[i];
								T1B[i] = T1[i+10000];
							}
		   	   	   	   	    // ordenação por MESCLAGEM - vetor T1
							// utilizando ordenacao por SELECAO para o vetor dividido
							selection_sort( T1A, 10000, 0 ); // não imprime passos intermediários
							selection_sort( T1B, 10000, 0 ); // não imprime passos intermediários
							// montagem do vetor T1 ordenado a partir das duas metades
							merge_sort( T1A, 10000, T1B, 10000, T1, 0 ); // não imprime passos intermediários
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m5 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m5 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
   		   	   	   	   	    // construção dos vetores auxiliares:
							// T1A (primeira metade) e T1B (segunda metade)
							for (i=0; i<10000; i++) {
								T1A[i] = T1[i];
								T1B[i] = T1[i+10000];
							}
		   	   	   	   	    // ordenação por MESCLAGEM - vetor T1
							// utilizando ordenacao por SELECAO para o vetor dividido
							selection_sort( T1A, 10000, 0 ); // não imprime passos intermediários
							selection_sort( T1B, 10000, 0 ); // não imprime passos intermediários
							// montagem do vetor T1 ordenado a partir das duas metades
							merge_sort( T1A, 10000, T1B, 10000, T1, 0 ); // não imprime passos intermediários
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m5 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m5 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
   		   	   	   	   	    // construção dos vetores auxiliares:
							// T2A (primeira metade) e T2B (segunda metade)
							for (i=0; i<20000; i++) {
								T2A[i] = T2[i];
								T2B[i] = T2[i+20000];
							}
		   	   	   	   	    // ordenação por MESCLAGEM - vetor T2
							// utilizando ordenacao por SELECAO para o vetor dividido
							selection_sort( T2A, 20000, 0 ); // não imprime passos intermediários
							selection_sort( T2B, 20000, 0 ); // não imprime passos intermediários
							// montagem do vetor T2 ordenado a partir das duas metades
							merge_sort( T2A, 20000, T2B, 20000, T2, 0 ); // não imprime passos intermediários
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m5 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m5 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
   		   	   	   	   	    // construção dos vetores auxiliares:
							// T2A (primeira metade) e T2B (segunda metade)
							for (i=0; i<20000; i++) {
								T2A[i] = T2[i];
								T2B[i] = T2[i+20000];
							}
		   	   	   	   	    // ordenação por MESCLAGEM - vetor T2
							// utilizando ordenacao por SELECAO para o vetor dividido
							selection_sort( T2A, 20000, 0 ); // não imprime passos intermediários
							selection_sort( T2B, 20000, 0 ); // não imprime passos intermediários
							// montagem do vetor T2 ordenado a partir das duas metades
							merge_sort( T2A, 20000, T2B, 20000, T2, 0 ); // não imprime passos intermediários
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;
			
			// ordenação por MESCLAGEM RECURSIVO
			// --------------------------------- 
			case MESCLAGEM_RECURSIVO :
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m6 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m6 );
							merge_sort_r( V1, 8, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m6 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m6 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							merge_sort_r( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// verifica se não houve erro
							for (int kk=1;kk<20000;kk++) {
								if (T1[kk-1]>T1[kk]) {
									cout << "ERRO - Elemento " << kk-1 << " (valor " << T1[kk-1] << ") maior que elemento " << kk << " (valor " << T1[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m6 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m6 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							merge_sort_r( T1, 20000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<20000;kk++) {
								if (T1[kk-1]>T1[kk]) {
									cout << "ERRO - Elemento " << kk-1 << " (valor " << T1[kk-1] << ") maior que elemento " << kk << " (valor " << T1[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m6 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m6 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							merge_sort_r( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<40000;kk++) {
								if (T2[kk-1]>T2[kk]) {
									cout << "ERRO - Elemento " << kk-1 << " (valor " << T2[kk-1] << ") maior que elemento " << kk << " (valor " << T2[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m6 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m6 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							merge_sort_r( T2, 40000, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<40000;kk++) {
								if (T2[kk-1]>T2[kk]) {
									cout << "ERRO - Elemento " << kk-1 << " (valor " << T2[kk-1] << ") maior que elemento " << kk << " (valor " << T2[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;

			// ordenação por QUICKSORT (PARTIÇÃO)
			// ----------------------------------
			case QUICK_RECURSIVO :
				#ifndef AUTOMATICO
				cout << "\nEscolheu método " << m7 << " ! " << endl;
				#endif
				// escolha do tipo de teste a ser executado
				do {
					#ifndef AUTOMATICO
					teste = escolhe_teste();
					#else
					teste = escolhe_teste_2(teste);
					#endif
					// análise da escolha do teste e respectivo acionamento
					switch( teste ) {
						
						#ifndef AUTOMATICO
						case FIXO:
							cout << "\nEscolheu teste VETOR " << t1 << " !" << endl;
							monta_vetor_FIXO( V1, m7 );
							quick_sort( V1, 0, 7, 1 ); // imprime passos intermediários 
							cout << endl;
							break;
						#endif
						
						case GRANDE_1_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t2 << " !" << endl;
							#else
							imprime_nome_metodo( m7 );
							imprime_dados_teste( t2 );
							#endif
							monta_vetor_GRANDE_1_ALEATORIO( T1, m7 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// OU ...time (&start);
							quick_sort( T1, 0, 19999, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// OU ...time (&end);
							// verifica se não houve erro
							for (int kk=1;kk<20000;kk++) {
								if (T1[kk-1]>T1[kk]) {
									cout << "ERRO QUICK - Elemento " << kk-1 << " (valor " << T1[kk-1] << ") maior que elemento " << kk << " (valor " << T1[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							// OU ...diferenca  = difftime (end,start);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_1_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t3 << " !" << endl;
							#else
							imprime_nome_metodo( m7 );
							imprime_dados_teste( t3 );
							#endif
							monta_vetor_GRANDE_1_DECRESCENTE( T1, m7 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							quick_sort( T1, 0, 19999, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<20000;kk++) {
								if (T1[kk-1]>T1[kk]) {
									cout << "ERRO QUICK - Elemento " << kk-1 << " (valor " << T1[kk-1] << ") maior que elemento " << kk << " (valor " << T1[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_ALEATORIO:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t4 << " !" << endl;
							#else
							imprime_nome_metodo( m7 );
							imprime_dados_teste( t4 );
							#endif
							monta_vetor_GRANDE_2_ALEATORIO( T2, m7 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							quick_sort( T2, 0, 39999, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<40000;kk++) {
								if (T2[kk-1]>T2[kk]) {
									cout << "ERRO QUICK - Elemento " << kk-1 << " (valor " << T2[kk-1] << ") maior que elemento " << kk << " (valor " << T2[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						case GRANDE_2_DECRESCENTE:
							#ifndef AUTOMATICO
							cout << "\nEscolheu teste VETOR " << t5 << " !" << endl;
							#else
							imprime_nome_metodo( m7 );
							imprime_dados_teste( t5 );
							#endif
							monta_vetor_GRANDE_2_DECRESCENTE( T2, m7 );
							//cout << endl;
							#ifndef AUTOMATICO
							cout << "Ordenando ...";
							#endif
							// anota o horário (ou clock) logo antes de chamar o método 
							start2 = clock();
							// quick_sort 'normal' pode resultar em 'out of memory' 
							//quick_sort       ( T2, 0, 39999, 0 ); // não imprime passos intermediários
							// abordagem 'recursive tail' evita isso 
							quick_sort_tail_1( T2, 0, 39999, 0 ); // não imprime passos intermediários 
							//quick_sort_tail_2( T2, 0, 39999, 0 ); // não imprime passos intermediários 
							// anota o horário (ou clock) logo depois de chamar o método 
							end2 = clock();
							// verifica se não houve erro
							for (int kk=1;kk<40000;kk++) {
								if (T2[kk-1]>T2[kk]) {
									cout << "ERRO QUICK - Elemento " << kk-1 << " (valor " << T2[kk-1] << ") maior que elemento " << kk << " (valor " << T2[kk] << ") !!!" << endl;
									return -1; 
								}
							}   
							// calcula a diferença de horário (ou clock)
							diferenca2 = ((float)(end2-start2)/CLOCKS_PER_SEC);
							#ifndef AUTOMATICO
							cout << "Levou "<< diferenca2  << " segundos para calcular" << endl;
							// OU ...cout << "Levou "<< diferenca  << " segundos para calcular" << endl;
							#else
							imprime_tempo_teste( diferenca2 );
							imprime_separador();
							#endif
							break;
						
						#ifndef AUTOMATICO
						case MUDAR_METODO:
							cout << "\nEscolheu voltar à escolha do método de ordenação !" << endl;
							break;
						
						case SAIR:
							cout << "\nEscolheu SAIR !" << endl;
							metodo = SAIR;
							break;
						#endif
						
						default:
							#ifndef AUTOMATICO
							cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
							#endif
							break;
					} // fim do 'switch( teste )'
							
				} while ( teste != SAIR  &&  teste != MUDAR_METODO );
				
				break;
			

			#ifndef AUTOMATICO
			case SAIR    :
				cout << "\nEscolheu SAIR !\n" << endl;
				break;
			#endif
			
			default:
				#ifndef AUTOMATICO
				cout << "\nOpção INVÁLIDA !  Tente novamente...\n" << endl;
				#endif
				break;
		}

   } while ( metodo != SAIR );
   
   // identificação do autor do trabalho
   exibe_dados_autor();
   
   // finalização
   return 0;
}

