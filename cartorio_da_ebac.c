#include <stdio.h> //bibliotecade comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/sting
		
	printf("Digite o CPF a ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s", cpf); //salva na string cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //acessa o arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,"\nCPF: "); //adiciona o cpf no arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file, "\nNome: "); //adiciona o nome no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s",nome); //salva na string nome
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file,nome); //salva o valor na vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file,"\nSobrenome: "); //adiciona o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s",sobrenome); //salva na string sobrenome
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file,sobrenome); //salva o valor na vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file,"\nCargo: "); //adiciona o cargo no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s",cargo); //salva na string cargo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informa��o
	fprintf(file,cargo); //salva o valor na vari�vel
	fprintf(file,"\n\n"); //acrescenta 2 pulos de linha
	fclose(file); //fecha o arquivo
	
	
	system("pause"); //pausa a tela para o usu�rio
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria o arquivo a ser consultado
	char conteudo[200]; //armazena os dados consultados
	
	printf("Digite o CPF a ser consultado: "); //coleta informa��o do usu�rio
	scanf("%s", cpf); //scaneia a vari�vel cpf
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //l� o arquivo cpf
	
	if(file == NULL) //valida��o para usu�rio n�o localizado/inexistente
	{
		printf("\n\nCPF N�O LOCALIZADO!\n"); //alerta ao usu�rio
	}
	
		printf("\n\nEstes s�o os dados do usu�rio: \n"); //mostra o resultado da busca ao usu�rio
		
	while(fgets(conteudo, 200, file) != NULL) //respons�vel por buscar as informa��es at� que o resultado seja nulo
	{
		printf("%s", conteudo); //scaneia o conte�do
	}
	
	system("pause"); //pausa o sistema
}

int deletar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	char cpf[40]; //cria o arquivo a ser deletado
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta informa��o do usu�rio
	scanf("%s",cpf); //scaneia a vari�vel cpf
	
	remove(cpf); //remove o usu�rio
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //l� o arquivo cpf
	
	if(file == NULL) //valida��o para usu�rio n�o localizado/inexistente
	{
		printf("\n\nEste usu�rio n�o se encontra no sistema!.\n"); //alerta ao usu�rio
		system("pause"); //pausa o sistema
	}
	
}


int main() //Fun��o respons�vel pelo in�cio do desenvolvimento
{
	int opcao=0; //definindo as vari�veis
	int laco=1; //definindo o valor
	
	for(laco=1;laco=1;) //definindo a repeti��o
	{

		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
		printf("*** Cart�rio da EBAC ***\n\n"); //in�cio do menu
	
		printf("Selecione a op��o desejada:\n\n\n "); //coleta a informa��o do usu�rio
	
		printf("\t1. Registrar Nomes\n"); //informa a op��o ao usu�rio
		printf("\t2. Consultar Nomes\n");  //informa a op��o ao usu�rio
		printf("\t3. Deletar Nomes\n\n\n");  //informa a op��o ao usu�rio
		printf("Op��o: "); //fim do menu
	
	
		scanf("%d", &opcao); //armazendando a escolha do usu�rio
	
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registrar(); //chamando a fun��o de registrar
			break;
			
			case 2:
			consultar(); //chamando a fun��o de consultar
			break;
			
			case 3:
			deletar(); //chamando a fun��o de deletar
			break;
			
			default:	
			printf("OP��O INDISPON�VEL\n"); //alerta ao usu�rio
			system("pause");
			break;
		} //fim da sele��o do menu
		
	}
	
}
