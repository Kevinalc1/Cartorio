#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro()//fun��o responsavel pelo cadastro no sistema
{
	char arquivo[40];//string conjunto de variaveis
	char cpf[40];//variavel cpf
	char nome[40];//variavel nome
	char sobrenome[40];//variavel sobrenome
	char cargo[40];//variavel cargo
	
	printf("Digite o CPF: ");// coleta de inform��es
	scanf("%s", cpf);//%s referese ao armazanemanto da string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file;//cira o arquivo no banco de dados
	file = fopen(arquivo, "r");//tenta abrir o arquivo para leitura
	
	if(file != NULL)// se o arquivo j� existir (ou seja n�o � NULL)
	{
		printf("CPF j� cadastrado no sistema. \n");//mensagem que indica que o cpf ja esta cadastrado
		fclose(file);//fecha o arquivo previamente aberto para leitura
		system("pause");//pausa a tela
		return 0;//sai da fun��o sem registrar novamente
	}
	
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Nome: ");//coleta a informa��o nome
	scanf("%s",nome);//armazena os dados coletado a string
	
	file = fopen(arquivo,"a");//abre o arquivo e adiciona
	fprintf(file,nome);//acrescenta o nome ao registro
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Sobrenome: ");//coleta a informa��o sobrenome
	scanf("%s", sobrenome);// armazena os dados coletados a string
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file, sobrenome);//acrescenta o sobrenome ao registro
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Cargo: ");//coleta a informa�ao cargo
	scanf("%s", cargo);//armazena os dados coletados a string
	
	printf("Registro feito com sucesso! \n");//mensagem final referente a um registro concluido
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file, cargo); //acrescenta o cargo ao registro
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa a tela	
	
}

int consulta()//Fun��o responsavel pela consulta de registros
{
	setlocale(LC_ALL, "Portuguese");//linguagem para o portugu�s
	
	char cpf[40];//variavel cpf
	char conteudo[200];//o conteudo da variavel
	
	printf("Digite o CPF a ser consultado: ");//coleta a inform��o a ser consultada
	scanf ("%s", cpf);//procura a variavel cpf
	
	FILE *file;//indica onde procurar a informa��o
	file = fopen(cpf, "r");//procura a inform��o no arquivo e l�
	
	if(file == NULL)//se o arquivo no existir
	{
		printf("CPF n�o cadastrado.\n\n");//mensagem que indica que o usu�rio nao est� cadastrado
	}
	
	while(fgets(conteudo, 200,file)!= NULL)//caso encontre a variavel
	{
		printf("\nInforma��es do usu�rio: ");//mensagem que aparece ao usu�rio
		printf("%s", conteudo);//dados consultados
		printf("\n\n");//espa�amentos
	}
	
	system("pause");//pausa a tela
}

int deletar()//fun��o respons�vel por deletar registros
{   
    char cpf[40];//vari�vel CPF
    char confirmacao[3];//vari�vel para armazenar a confirma��o

    printf("Digite o CPF do usu�rio que deseja deletar: \n");//coletando informa��es a serem deletadas
    scanf("%s", cpf);//procura a vari�vel CPF

    FILE *file;//indica onde procurar a informa��o
    file = fopen(cpf, "r");//abre o arquivo e l� a informa��o

    if(file == NULL)//se o arquivo n�o existir
    {
        printf("O usu�rio n�o se encontra no sistema! \n");//mensagem que aparece ao usu�rio
        system("pause");//pausa o sistema
    }
    else//caso exista o arquivo
    {
        fclose(file);//fecha o arquivo (que estava aberto para leitura)
        
        printf("Tem certeza que deseja deletar o usu�rio com CPF %s? (sim/n�o): ", cpf);//solicita confirma��o do usu�rio
        scanf("%s", confirmacao);//l� a resposta do usu�rio

        if(strcmp(confirmacao, "sim") == 0)//verifica se a resposta � "sim"
        {
            if (remove(cpf) == 0)//se remover o CPF do usu�rio registrado
            {
                printf("Usu�rio removido com sucesso! \n");//mensagem de confirma��o
            }
            else
            {
                printf("Erro ao tentar remover o usu�rio. \n");//mensagem de erro
            }
        }
        else
        {
            printf("Opera��o de deletar cancelada. \n");//mensagem de cancelamento
        }
        system("pause");//pausa o sistema
    }
}


int main()//meun inicial
{
	int opcao=0;//Definindo a variavel
	int x=1;
	
	for(x=1;x=1;)//la�o
	{
		
		system("cls");// responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a liguagem
	
		printf("\t***Cart�rio da EBAC***\n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");//coleta a informa�ao da a��o que o usu�rio deseja fazer
		
		printf("\t1 - Registrar nomes\n");// registrar nomes
		printf("\t2 - Consultar nomes\n");// consultar nomes
		printf("\t3 - Deletar nomes\n");// deletar nomes
		printf("\t4 - Sair do sistema\n\n");// sair do sistema
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");//limpa a tela
		
		switch(opcao)// inicio da sele��o
		{
			case 1:// op��o para a fun��o (1)
			registro();//chamada de fun��es (registro)
			break;//sair do bloco ap�s a execu��o da chamada
			
			case 2://op��o para a fun��o (2)
			consulta();//chamada de fun��es (onsulta)
			break;//sair do bloco ap�s a execu��o da chamada
				
			case 3://op��o para a fun��o (3)
			deletar();//chamada de fun��es (deletar)
			break;//sair do bloco ap�s a execu��o da chamada
			
			case 4://sair do sistema (4)
			printf("Obrigado por utilizar o sistema");//mensagem de saida do sistema
			return 0;//retornar ao valor 0
			break;//sair do bloco de execu��o da chamada
			
			
			default://qualquer outra op��o que nao seja as previamentes programadas	
			printf("### Op��o invalida ###\n\n");//mensagem para o usu�rio
			system("pause");//pausa o sistema
			break;//sair do bloco ap�s a execu��o da chamada
		}
		
	}
}
