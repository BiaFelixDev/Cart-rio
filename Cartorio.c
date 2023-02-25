#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro () //função responsável por cadastrar os usuários no sistema
{
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem
	
	//início da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //"%s" armazena os dados referentes às string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo; "w": write
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informação adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //comando que leva o texto ao usuário
	scanf("%s", nome); //"%s" armazena os dados referentes às string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informação adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //comando que leva o texto ao usuário
	scanf("%s", sobrenome); //"%s" armazena os dados referentes às string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //informação adicionada
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //comando que leva o texto ao usuário
	scanf("%s", cargo); //"%s" armazena os dados referentes às string
	
	file = fopen (arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //mantém os textos acima aparecendo para o usuário 
	
}

int consulta () //função responsável por consultar os usuários cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//início da criação de variáveis/string
	char cpf [40];
	char conteudo [200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //comando que leva o texto ao usuário
	scanf("%s", cpf); //"%s" armazena os dados referentes às string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo; "r": read
	
	if (file == NULL) //estrutura de decisão
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); //comando que leva o texto ao usuário
	}
	
	while (fgets(conteudo,200,file) != NULL) //operador de repetição
	{
		printf("\nEssas são as informações do usuário: "); //comando que leva o texto ao usuário
		printf("%s", conteudo); //"%s" armazena os dados referentes às string
		printf("\n\n"); //pula linha
	}
	
	system("pause"); //mantém o texto aparecendo para o usuário

}

int deletar () //função responsável por deletar os usuários cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf [40]; //criação de variáveis/string
	
	printf("Digite o CPF a ser deletado: "); //comando que leva o texto ao usuário
	scanf("%s", cpf); //"%s" armazena os dados referentes às string
	
	remove(cpf); //comando que deleta variáveis
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo; "r": read
	
	if (file == NULL) //estrutura de decisão
	{
		printf("O usuário não se encontra no sistema!\n"); //comando que leva o texto ao usuário
		system("pause"); //mantém o texto aparecendo para o usuário
	}
}

int main () //ponto de partida para a execução do programa
{
	int opcao=0; //definindo as variáveis
	int laco=1; //definindo as variáveis
	
	for(laco=1;laco=1;) //abertura do laço de repetição
	{
		
		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("##### Registro de Nomes | EBAC #####\n\n"); //início do menu
		printf("Selecione a opção desejada do menu:\n\n"); //enunciado do menu
		printf("\t1: Registrar nomes\n"); //comando que leva a primeira opção ao usuário
		printf("\t2: Consultar nomes\n"); //comando que leva a segunda opção ao usuário
		printf("\t3: Deletar nomes\n\n"); //comando que leva a terceira opção ao usuário
		printf("Opção:"); //final do menu
		
		scanf("%d", &opcao); //"%d" armazena a escolha do usuário para a variável do tipo inteira
  
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção
		{
			case 1: //primeiro caso/comando
			registro(); //chamada das funções
			break; //encerra o comando
			
			case 2: //segundo caso/comando
			consulta(); //chamada das funções
			break; //encerra o comando
			
			case 3: //terceiro caso/comando
			deletar(); //chamada das funções
			break; //encerra o comando
			
			default: //abrange as exceções da variável switch
			printf("Essa opção não está disponível!\n"); //comando que leva o texto ao usuário
			system("pause"); //mantém a mensagem acima aparecendo para o usuário
			break; //encerra o comando
		}	//fim da seleção
	}
}
