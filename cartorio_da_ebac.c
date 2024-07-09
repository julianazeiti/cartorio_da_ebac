#include <stdio.h> //bibliotecade comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/sting
		
	printf("Digite o CPF a ser cadastrado: "); //coleta informação do usuário
	scanf("%s", cpf); //salva na string cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //acessa o arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,"\nCPF: "); //adiciona o cpf no arquivo
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file, "\nNome: "); //adiciona o nome no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coleta informação do usuário
	scanf("%s",nome); //salva na string nome
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file,nome); //salva o valor na variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file,"\nSobrenome: "); //adiciona o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: "); //coleta informação do usuário
	scanf("%s",sobrenome); //salva na string sobrenome
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file,sobrenome); //salva o valor na variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file,"\nCargo: "); //adiciona o cargo no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo ser cadastrado: "); //coleta informação do usuário
	scanf("%s",cargo); //salva na string cargo
	
	file = fopen(arquivo, "a"); //abri o arquivo para adicionar nova informação
	fprintf(file,cargo); //salva o valor na variável
	fprintf(file,"\n\n"); //acrescenta 2 pulos de linha
	fclose(file); //fecha o arquivo
	
	
	system("pause"); //pausa a tela para o usuário
}

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria o arquivo a ser consultado
	char conteudo[200]; //armazena os dados consultados
	
	printf("Digite o CPF a ser consultado: "); //coleta informação do usuário
	scanf("%s", cpf); //scaneia a variável cpf
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //lê o arquivo cpf
	
	if(file == NULL) //validação para usuário não localizado/inexistente
	{
		printf("\n\nCPF NÃO LOCALIZADO!\n"); //alerta ao usuário
	}
	
		printf("\n\nEstes são os dados do usuário: \n"); //mostra o resultado da busca ao usuário
		
	while(fgets(conteudo, 200, file) != NULL) //responsável por buscar as informações até que o resultado seja nulo
	{
		printf("%s", conteudo); //scaneia o conteúdo
	}
	
	system("pause"); //pausa o sistema
}

int deletar() //Função responsável por consultar os usuários no sistema
{
	char cpf[40]; //cria o arquivo a ser deletado
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta informação do usuário
	scanf("%s",cpf); //scaneia a variável cpf
	
	remove(cpf); //remove o usuário
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //lê o arquivo cpf
	
	if(file == NULL) //validação para usuário não localizado/inexistente
	{
		printf("\n\nEste usuário não se encontra no sistema!.\n"); //alerta ao usuário
		system("pause"); //pausa o sistema
	}
	
}


int main() //Função responsável pelo início do desenvolvimento
{
	int opcao=0; //definindo as variáveis
	int laco=1; //definindo o valor
	
	for(laco=1;laco=1;) //definindo a repetição
	{

		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
		printf("*** Cartório da EBAC ***\n\n"); //início do menu
	
		printf("Selecione a opção desejada:\n\n\n "); //coleta a informação do usuário
	
		printf("\t1. Registrar Nomes\n"); //informa a opção ao usuário
		printf("\t2. Consultar Nomes\n");  //informa a opção ao usuário
		printf("\t3. Deletar Nomes\n\n\n");  //informa a opção ao usuário
		printf("Opção: "); //fim do menu
	
	
		scanf("%d", &opcao); //armazendando a escolha do usuário
	
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registrar(); //chamando a função de registrar
			break;
			
			case 2:
			consultar(); //chamando a função de consultar
			break;
			
			case 3:
			deletar(); //chamando a função de deletar
			break;
			
			default:	
			printf("OPÇÃO INDISPONÍVEL\n"); //alerta ao usuário
			system("pause");
			break;
		} //fim da seleção do menu
		
	}
	
}
