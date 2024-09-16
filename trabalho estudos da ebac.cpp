#include <stdio.h>//biblioteca de comunoca��o com o usu�rio
#include <stdlib.h>//bibilioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//funs��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/ strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/ strings
	
	printf("digita o CPF a ser cadastrado");//coletando informa��es do usu�rio	
	scanf("%s",cpf);//%s referese a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores da string
	
	FILE *file;//cria o arquivo
	file=fopen(arquivo, "w");//cria o arquivo eo "w significa escrever
	fprintf(file,cpf);//salva o valor da var�vel
	fclose(file);//fecha o arquivo
	
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
	printf("digite o nome a ser cadastrado:");
	scanf("%s",nome);
		
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file =fopen(arquivo,"a");	
	fprintf(file,sobrenome);
	fclose(file);
	
	 file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
		
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
setlocale(LC_ALL,"portuguese");
char cpf[40];
char conteudo[200];

printf("Digite o CPF a ser consultado");
scanf("%s",cpf);

FILE *file;
file=fopen(cpf,"r");

if(file==NULL)
{
	printf("N�o foi possivel abrir o arquivo n�o localizado!.\n");
}

while(fgets(conteudo, 200, file)!= NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
system ("pause");


}

int deletar()
{
	char cpf[40];

	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}
int main()
{
	int opcao=0;//definindo var�veis
	int laco=1;	
	
	for(laco=1;laco=1;)
	{
	
	
		system("cls"); 
		
		setlocale(LC_ALL,"portuguese");//definindoa linguagem
	
		printf("### Car�rio da EBAC###\n\n");//incio do menu
		printf("escolha a opc�o desejada do menu\n\n");
		printf("\t1-registrar nomes\n");
		printf("\t2-Consultar nomes\n");
		printf("\t3-Deletar nomes\n\n");
		printf("\t4-sair do sistema\n\n");
		printf("Op��o:");//fin do menu
	
		scanf("%d", &opcao);// armazenamento a escolha do usu�rio
	
		system("cls"); //responsavel por limpar atela
		
		switch(opcao) //inicio da sele��o do menu
		{
		case 1:	
        registro(); //chamar as fun��es
		break;
			
		case 2:
	    consulta();
		break;
			
		case 3:		
		deletar();
		break;
		
		case 4:
		printf("obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Esta opc�o n�o esta disponivel!\n");	
		system("pause");
		break;	
				
		} //fin da sle��o
	
	}
}
