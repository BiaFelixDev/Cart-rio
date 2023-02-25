#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro () //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //"%s" armazena os dados referentes �s string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo; "w": write
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informa��o adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //comando que leva o texto ao usu�rio
	scanf("%s", nome); //"%s" armazena os dados referentes �s string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informa��o adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //comando que leva o texto ao usu�rio
	scanf("%s", sobrenome); //"%s" armazena os dados referentes �s string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informa��o adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //comando que leva o texto ao usu�rio
	scanf("%s", cargo); //"%s" armazena os dados referentes �s string
	
	file = fopen (arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //mant�m os textos acima aparecendo para o usu�rio 
	
}

int consulta () //fun��o respons�vel por consultar os usu�rios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf [40];
	char conteudo [200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //comando que leva o texto ao usu�rio
	scanf("%s", cpf); //"%s" armazena os dados referentes �s string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo; "r": read
	
	if (file == NULL) //estrutura de decis�o
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //comando que leva o texto ao usu�rio
	}
	
	while (fgets(conteudo,200,file) != NULL) //operador de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //comando que leva o texto ao usu�rio
		printf("%s", conteudo); //"%s" armazena os dados referentes �s string
		printf("\n\n"); //pula linha
	}
	
	system("pause"); //mant�m o texto aparecendo para o usu�rio

}

int deletar () //fun��o respons�vel por deletar os usu�rios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf [40]; //cria��o de vari�veis/string
	
	printf("Digite o CPF a ser deletado: "); //comando que leva o texto ao usu�rio
	scanf("%s", cpf); //"%s" armazena os dados referentes �s string
	
	remove(cpf); //comando que deleta vari�veis
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo; "r": read
	
	if (file == NULL) //estrutura de decis�o
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); //comando que leva o texto ao usu�rio
		system("pause"); //mant�m o texto aparecendo para o usu�rio
	}
}

int main () //ponto de partida para a execu��o do programa
{
	int opcao=0; //definindo as vari�veis
	int laco=1; //definindo as vari�veis
	
	for(laco=1;laco=1;) //abertura do la�o de repeti��o
	{
		
		system("cls"); //respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("##### Registro de Nomes | EBAC #####\n\n"); //in�cio do menu
		printf("Selecione a op��o desejada do menu:\n\n"); //enunciado do menu
		printf("\t1: Registrar nomes\n"); //comando que leva a primeira op��o ao usu�rio
		printf("\t2: Consultar nomes\n"); //comando que leva a segunda op��o ao usu�rio
		printf("\t3: Deletar nomes\n\n"); //comando que leva a terceira op��o ao usu�rio
		printf("Op��o:"); //final do menu
		
		scanf("%d", &opcao); //"%d" armazena a escolha do usu�rio para a vari�vel do tipo inteira
  
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o
		{
			case 1: //primeiro caso/comando
			registro(); //chamada das fun��es
			break; //encerra o comando
			
			case 2: //segundo caso/comando
			consulta(); //chamada das fun��es
			break; //encerra o comando
			
			case 3: //terceiro caso/comando
			deletar(); //chamada das fun��es
			break; //encerra o comando
			
			default: //abrange as exce��es da vari�vel switch
			printf("Essa op��o n�o est� dispon�vel!\n"); //comando que leva o texto ao usu�rio
			system("pause"); //mant�m a mensagem acima aparecendo para o usu�rio
			break; //encerra o comando
		}	//fim da sele��o
	}
}
