#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro()//função responsavel pelo cadastro no sistema
{
	char arquivo[40];//string conjunto de variaveis
	char cpf[40];//variavel cpf
	char nome[40];//variavel nome
	char sobrenome[40];//variavel sobrenome
	char cargo[40];//variavel cargo
	
	printf("Digite o CPF: ");// coleta de informções
	scanf("%s", cpf);//%s referese ao armazanemanto da string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file;//cira o arquivo no banco de dados
	file = fopen(arquivo, "r");//tenta abrir o arquivo para leitura
	
	if(file != NULL)// se o arquivo já existir (ou seja não é NULL)
	{
		printf("CPF já cadastrado no sistema. \n");//mensagem que indica que o cpf ja esta cadastrado
		fclose(file);//fecha o arquivo previamente aberto para leitura
		system("pause");//pausa a tela
		return 0;//sai da função sem registrar novamente
	}
	
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Nome: ");//coleta a informação nome
	scanf("%s",nome);//armazena os dados coletado a string
	
	file = fopen(arquivo,"a");//abre o arquivo e adiciona
	fprintf(file,nome);//acrescenta o nome ao registro
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Sobrenome: ");//coleta a informação sobrenome
	scanf("%s", sobrenome);// armazena os dados coletados a string
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file, sobrenome);//acrescenta o sobrenome ao registro
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file,",");//acrescenta uma virgula para facilitar o entendimento dos registros
	fclose(file);//fecha o arquivo
	
	printf("Digite o Cargo: ");//coleta a informaçao cargo
	scanf("%s", cargo);//armazena os dados coletados a string
	
	printf("Registro feito com sucesso! \n");//mensagem final referente a um registro concluido
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona
	fprintf(file, cargo); //acrescenta o cargo ao registro
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa a tela	
	
}

int consulta()//Função responsavel pela consulta de registros
{
	setlocale(LC_ALL, "Portuguese");//linguagem para o português
	
	char cpf[40];//variavel cpf
	char conteudo[200];//o conteudo da variavel
	
	printf("Digite o CPF a ser consultado: ");//coleta a informção a ser consultada
	scanf ("%s", cpf);//procura a variavel cpf
	
	FILE *file;//indica onde procurar a informação
	file = fopen(cpf, "r");//procura a informção no arquivo e lê
	
	if(file == NULL)//se o arquivo no existir
	{
		printf("CPF não cadastrado.\n\n");//mensagem que indica que o usuário nao está cadastrado
	}
	
	while(fgets(conteudo, 200,file)!= NULL)//caso encontre a variavel
	{
		printf("\nInformações do usuário: ");//mensagem que aparece ao usuário
		printf("%s", conteudo);//dados consultados
		printf("\n\n");//espaçamentos
	}
	
	system("pause");//pausa a tela
}

int deletar()//função responsável por deletar registros
{   
    char cpf[40];//variável CPF
    char confirmacao[3];//variável para armazenar a confirmação

    printf("Digite o CPF do usuário que deseja deletar: \n");//coletando informações a serem deletadas
    scanf("%s", cpf);//procura a variável CPF

    FILE *file;//indica onde procurar a informação
    file = fopen(cpf, "r");//abre o arquivo e lê a informação

    if(file == NULL)//se o arquivo não existir
    {
        printf("O usuário não se encontra no sistema! \n");//mensagem que aparece ao usuário
        system("pause");//pausa o sistema
    }
    else//caso exista o arquivo
    {
        fclose(file);//fecha o arquivo (que estava aberto para leitura)
        
        printf("Tem certeza que deseja deletar o usuário com CPF %s? (sim/não): ", cpf);//solicita confirmação do usuário
        scanf("%s", confirmacao);//lê a resposta do usuário

        if(strcmp(confirmacao, "sim") == 0)//verifica se a resposta é "sim"
        {
            if (remove(cpf) == 0)//se remover o CPF do usuário registrado
            {
                printf("Usuário removido com sucesso! \n");//mensagem de confirmação
            }
            else
            {
                printf("Erro ao tentar remover o usuário. \n");//mensagem de erro
            }
        }
        else
        {
            printf("Operação de deletar cancelada. \n");//mensagem de cancelamento
        }
        system("pause");//pausa o sistema
    }
}


int main()//meun inicial
{
	int opcao=0;//Definindo a variavel
	int x=1;
	
	for(x=1;x=1;)//laço
	{
		
		system("cls");// responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a liguagem
	
		printf("\t***Cartório da EBAC***\n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");//coleta a informaçao da ação que o usuário deseja fazer
		
		printf("\t1 - Registrar nomes\n");// registrar nomes
		printf("\t2 - Consultar nomes\n");// consultar nomes
		printf("\t3 - Deletar nomes\n");// deletar nomes
		printf("\t4 - Sair do sistema\n\n");// sair do sistema
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");//limpa a tela
		
		switch(opcao)// inicio da seleção
		{
			case 1:// opção para a função (1)
			registro();//chamada de funções (registro)
			break;//sair do bloco após a execução da chamada
			
			case 2://opção para a função (2)
			consulta();//chamada de funções (onsulta)
			break;//sair do bloco após a execução da chamada
				
			case 3://opção para a função (3)
			deletar();//chamada de funções (deletar)
			break;//sair do bloco após a execução da chamada
			
			case 4://sair do sistema (4)
			printf("Obrigado por utilizar o sistema");//mensagem de saida do sistema
			return 0;//retornar ao valor 0
			break;//sair do bloco de execução da chamada
			
			
			default://qualquer outra opção que nao seja as previamentes programadas	
			printf("### Opção invalida ###\n\n");//mensagem para o usuário
			system("pause");//pausa o sistema
			break;//sair do bloco após a execução da chamada
		}
		
	}
}
