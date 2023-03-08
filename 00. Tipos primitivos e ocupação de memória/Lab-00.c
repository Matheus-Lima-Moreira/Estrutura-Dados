// arquivos de cabeçalhos
#include <stdio.h>
#include <locale.h>

// programa principal
int main() {

	setlocale(LC_ALL,"Portuguese");
	
	// declarações de variáveis
	int x1 = 3;
	int x2 = -48;
	
	float f1 = 35.98;
	float f2 = -7.36;
	
	double d1 = 25.71;
	double d2 = -9.32;
	
	char c1 = 'A';
	char c2 = 'B';
	
	bool b1 = true;
	bool b2 = false;
	
	// exibição de conteúdos e endereços
	printf("\nTIPO INTEIRO\n");
	printf(  "------------\n");
	
	printf("Variável x1 - endereço #%p - qtd bytes %d - conteúdo %4d\n", &x1, sizeof(x1), x1 );
	printf("Variável x2 - endereço #%p - qtd bytes %d - conteúdo %4d\n", &x2, sizeof(x2), x2 );
	
	printf("\nTIPO FLOAT\n");
	printf(  "----------\n");
	
	printf("Variável f1 - endereço #%p - qtd bytes %d - conteúdo %.3f\n", &f1, sizeof(f1), f1 );
	printf("Variável f2 - endereço #%p - qtd bytes %d - conteúdo %.3f\n", &f2, sizeof(f2), f2 );
	
	printf("\nTIPO DOUBLE\n");
	printf(  "-----------\n");
	
	printf("Variável d1 - endereço #%p - qtd bytes %d - conteúdo %.3f\n", &d1, sizeof(d1), d1 );
	printf("Variável d2 - endereço #%p - qtd bytes %d - conteúdo %.3f\n", &d2, sizeof(d2), d2 );
	
	printf("\nTIPO CHAR\n");
	printf(  "---------\n");
	
	printf("Variável c1 - endereço #%p - qtd bytes %d - conteúdo %c\n", &c1, sizeof(c1), c1 );
	printf("Variável c2 - endereço #%p - qtd bytes %d - conteúdo %c\n", &c2, sizeof(c2), c2 );
	
	printf("\nTIPO BOOLEAN\n");
	printf(  "------------\n");
	
	printf("Variável b1 - endereço #%p - qtd bytes %d - conteúdo %d\n", &b1, sizeof(b1), b1 ); // modo 1
	printf("Variável b2 - endereço #%p - qtd bytes %d - conteúdo %s\n", &b2, sizeof(b2), (b2 ? "true" : "false") ); // modo 2
	
	// finalização
	return 0;
}