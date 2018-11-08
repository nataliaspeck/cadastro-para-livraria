#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TRUE 1

/* cadastro livraria */

struct livro { // declara��o de struct com 10 vari�veis
	char titulo [60];
	char editora[30];
	char autor[60];
	char genero[30];
	char encadernacao[30];
	int ano;
	int edicao;
	int paginas;
	int regnum;
	double preco;		
};

struct livro livros [100]; // vetor de structs 
int n=0; // contador para �ndice do vetor de structs
char numstr[40]; // vari�vel para leitura de n�meros
char buscar[60];
int i=0;
/* adiciona um novo livro ao banco de dados*/

novonome (){ 
	printf("\nRegistro %d.\nInsira o t�tulo: ", n+1);
	gets (livros[n].titulo); // l� a string
	strupr(livros[n].titulo);
	printf ("Insira a editora: ");
	gets (livros[n].editora);
	printf ("Insira o autor: ");
	gets (livros[n].autor);
	printf ("Insira o g�nero: ");
	gets (livros[n].genero);
	printf ("Insira o tipo de encaderna��o: ");
	gets (livros[n].encadernacao);
	printf ("Insira o n�mero do registro (at� 3 digitos): ");
	gets (numstr); //l� n�mero
	livros[n].regnum=atoi(numstr); //fun��o que transformar uma string em um inteiro correspondente
	while (livros[n].regnum > 999){
		printf ("ERRO! Insira um n�mero do registro v�lido (at� 3 digitos): ");
		gets (numstr); 
		livros[n].regnum=atoi(numstr); 
	}
	printf ("Insira o n�mero de p�ginas: ");
	gets (numstr);
	livros[n].paginas=atoi(numstr);
	printf ("Insira o ano de publica��o: ");
	gets (numstr);
	livros[n].ano=atoi(numstr);
	while (livros[n].ano < 0){
		printf ("ERRO! Insira um ano de publica��o v�lido:");
		gets (numstr);
		livros[n].ano=atoi(numstr);	
	}
	printf ("Insira a edi��o: ");
	gets (numstr);
	livros[n].edicao=atoi(numstr);
	while (livros[n].edicao < 0){
		printf ("ERRO! Insira uma edi��o v�lida:");
		gets (numstr);
		livros[n].edicao=atoi(numstr);
	}
	printf("Digite pre�o: ");
	gets (numstr);
	livros[n++].preco=atof(numstr); //fun��o que transformar uma string em um float correspondente e incrementa o contador
}

busca(){
	if (n<1){ //se o contador for 0, n�o haver� listagem
	printf ("\nLista vazia!\n"); 
	return;
	}
	printf ("\nInsira o t�tulo do livro a ser pesquisado:\n");
	gets (buscar);
	strupr(buscar);
	for (i = 0; i < n; i++){
		if (strcmp (buscar, livros[i].titulo) == 0){
				printf("\nRegistro numero: %d\n", i+1);
				printf("\n			T�tulo:%s\n", livros[i].titulo);
				printf("\n			Editora:%s\n", livros[i].editora);
				printf("\n			Autor:%s\n", livros[i].autor);
				printf("\n			G�nero:%s\n", livros[i].genero);
				printf("\n			Encaderna��o:%s\n", livros[i].encadernacao);
				printf("\n			Ano:%d\n", livros[i].ano);
				printf("\n			N�mero de p�ginas:%d\n",livros[i].paginas);
				printf("\n			Edi��o:%d\n", livros[i].edicao);  
				printf("\n			Numero do reg. : %d\n", livros[i].regnum);
				printf ("\n			Preco: %4.2f\n",livros[i].preco);
				printf ("\n");
		}
	}
}

/* lista os dados de todos os livros */

listatudo (){ 
	int j;
	if (n<1){ //se o contador for 0, n�o haver� listagem
	printf ("\nLista vazia !"); 
	return;
	}
	for(j=0;j<n;j++){
	printf("\nRegistro numero: %d\n", j+1);
	printf("\n			T�tulo:%s\n", livros[j].titulo);
	printf("\n			Editora:%s\n", livros[j].editora);
	printf("\n			Autor:%s\n", livros[j].autor);
	printf("\n			G�nero:%s\n", livros[j].genero);
	printf("\n			Encaderna��o:%s\n", livros[j].encadernacao);
	printf("\n			Ano:%d\n", livros[j].ano);
	printf("\n			N�mero de p�ginas:%d\n",livros[j].paginas);
	printf("\n			Edi��o:%d\n", livros[j].edicao);  
	printf("\n			Numero do reg. : %d\n", livros[j].regnum);
	printf("\n			Preco: %4.2f\n",livros[j].preco);
	printf("\n");
	}
}

/* grava matriz de estruturas em arquivo */

garq(){
	FILE *fptr;
	if (n<1){
	printf("\nN�o � poss�vel gravar lista vazia !n"); 
	return;
	}
	if(( fptr = fopen ("livros.txt","wb")) == NULL){
	printf("\nN�o � poss�vel abrir arquivo livros.rec\n");	
	}else {
		fwrite(livros,sizeof(livros[0]),n,fptr);
		fclose(fptr);
		printf("\n%d registros gravados.\n",n);	
	}
}

/* le registros do arquivo para a matriz */

larq(){
	FILE *fptr;
	if((fptr = fopen ("livros.txt","rb")) == NULL){
	printf("\nN�o � poss�vel arquivo livros.rec.n");
	}else{
		while(fread(&livros[n],sizeof(livros[n]),1,fptr) == 1)
		n++;
		fclose(fptr);
		printf("\nArquivo lido!\n");
		printf("\nO total de livros agora e: %d.\n", n - 1);
	}
}

int main(int argc, char *argv[]) {
	system ("color F0");
	setlocale(LC_ALL, "Portuguese");
	char ch;
		printf ("********************************************************************************");
		printf ("\n");
		printf ("                                CADASTRO LIVRARIA                               ");
		printf ("\n");
		printf ("********************************************************************************");
		printf ("\n");
	while(TRUE){
		printf("\n\t\t\tDigite 'A' para adicionar um livro\n");
		printf ("\n\t\t\tDigite 'I' para imprimir todos os livros\n");
		printf("\n\t\t\tDigite 'G' para gravar arquivo\n");
		printf("\n\t\t\tDigite 'L' para ler arquivo\n");
		printf ("\n\t\t\tDigite 'B' para busca por t�tulo\n");
		fflush(stdin);
		ch=getchar();
		getchar();
	switch(ch){
	case 'A': novonome ();break;
	case 'I': listatudo ();break;
	case 'G': garq ();break;
	case 'L': larq();break;
	case 'B': busca();break;
	default : puts("\nDigite somente op��o v�lida\n");
		}
	}
	system ("pause");
	return 0;
}
