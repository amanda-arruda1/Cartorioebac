#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocaçào de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string 

int registro() //Função responsável por cadastrar os usuários no sistema 
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
    FILE *file; //Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o aquivo e o "a" significa atualizar 
	fprintf(file, ","); //Salva o arquivo e a vírgula é utilizada para separar as infomações 
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); 
	fprintf( file, nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //Função responsável por consultar o usuário no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Consultando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informaçòes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}	

int deletar() //Função responsável por deletar o usuário do sistema 
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado:"); //Localizando o CPF a ser deletado 
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("\nO usuário não se encontra no sistema!\n");
    	system("pause");
	}
}

int main()
{

	int opcao=0; //Definindo variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	    printf("### Cartório da EBAC ###\n\n"); 
	    printf("Escolha a opção desejada do menu:\n\n"); //Início do menu
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n"); 
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Opção:"); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário 
	
	    system("cls"); //Responsável por limpar a tela
	    
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível\n");
		    system("pause");
			break;	
		}
	}
}

