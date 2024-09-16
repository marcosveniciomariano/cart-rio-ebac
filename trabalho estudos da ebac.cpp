#include <stdio.h>//biblioteca de comunocação com o usuário
#include <stdlib.h>//bibilioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro()//funsção responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/ strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/ strings
	
	printf("digita o CPF a ser cadastrado");//coletando informações do usuário	
	scanf("%s",cpf);//%s referese a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores da string
	
	FILE *file;//cria o arquivo
	file=fopen(arquivo, "w");//cria o arquivo eo "w significa escrever
	fprintf(file,cpf);//salva o valor da varável
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
	printf("Não foi possivel abrir o arquivo não localizado!.\n");
}

while(fgets(conteudo, 200, file)!= NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
system ("pause");


}

int deletar()
{
	char cpf[40];

	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
}
int main()
{
	int opcao=0;//definindo varáveis
	int laco=1;	
	
	for(laco=1;laco=1;)
	{
	
	
		system("cls"); 
		
		setlocale(LC_ALL,"portuguese");//definindoa linguagem
	
		printf("### Carório da EBAC###\n\n");//incio do menu
		printf("escolha a opcão desejada do menu\n\n");
		printf("\t1-registrar nomes\n");
		printf("\t2-Consultar nomes\n");
		printf("\t3-Deletar nomes\n\n");
		printf("\t4-sair do sistema\n\n");
		printf("Opção:");//fin do menu
	
		scanf("%d", &opcao);// armazenamento a escolha do usuário
	
		system("cls"); //responsavel por limpar atela
		
		switch(opcao) //inicio da seleção do menu
		{
		case 1:	
        registro(); //chamar as funções
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
		printf("Esta opcão não esta disponivel!\n");	
		system("pause");
		break;	
				
		} //fin da sleção
	
	}
}
