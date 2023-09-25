#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o em espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por c�piar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
    fprintf(file, cpf); //Salvo o valor da vari�vel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    
    
    
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite por CPF a ser consultado: "); //Consultando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //Arquivo n�o encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: "); //Deletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) //Arquivo n�o encontrado
    {
    	printf("O usu�rio n�o se encontra no sistema!\n");
    	system("pause");
    	
    	
	}

}

int main () 
    {
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    	
    	system("cls");
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); //Fim do menu
    
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
        system("cls"); //Respons�vel por limpar a tela
        
        
        switch(opcao) //In�cio da sele��o do menu
        {
        	case 1:
        	registro(); //Chamada de fun��es, registrar 
    	    break;
    	    
    	    case 2:
    	    consulta(); //Chamada de fun��es, consultar
    	    break;
    	    
    	    case 3:
    	    deletar(); //Chamada de func��es, deletar
    	    break; 
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;   	    
			  
    	    default:
    	    printf("Essa op��o n�o est� dispon�vel\n");
    	    system("pause");
    	    break;
    	    	
       }
        		
	}
}
       
    	
    	
    	
    	
    	
    	
    	
    	
    	
	
