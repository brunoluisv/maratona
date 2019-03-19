#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int cod;
	char nome[30];
	int horas;
	int minutos;
	int segundos;
	int milisegundos;
	int dia;
	int mes;
	int ano;
} Registro;

int op;
int op1;
int op2;
char c;

int insere_reg(){
	FILE *arquivo_maratona;
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;

	if(arquivo_maratona == NULL){
		printf("Erro ao Abrir");
		return 1;
	}

	system("clear || cls");
	printf("\n|	INSERIR REGISTRO	|\n");
	printf("1 - Código Corredor: ");
	scanf("%d", &maratona_reg.cod);
	fprintf(arquivo_maratona, "%d  ", maratona_reg.cod);
	printf("2 - Nome Corredor: ");
	scanf(" %[^\n]s", maratona_reg.nome);
	fprintf(arquivo_maratona, "%s  ", maratona_reg.nome);
	printf("3 - Tempo de Corrida\n");
	printf("\tHoras: ");
	scanf("%d", &maratona_reg.horas);
	printf("\tMinutos: ");
	scanf("%d", &maratona_reg.minutos);
	printf("\tSegundos: ");
	scanf("%d", &maratona_reg.segundos);
	printf("\tMilisegundos: ");
	scanf("%d", &maratona_reg.milisegundos);
	fprintf(arquivo_maratona, "%d:%d:%d:%d", maratona_reg.horas, maratona_reg.minutos, maratona_reg.segundos,maratona_reg.milisegundos);
	printf("4 - Data da Corrida\n");
	printf("\tDia: ");
	scanf("%d", &maratona_reg.dia);
	printf("\tMês: ");
	scanf("%d", &maratona_reg.mes);
	printf("\tAno: ");
	scanf("%d", &maratona_reg.ano);
	fprintf(arquivo_maratona, "  %d/%d/%d\n", maratona_reg.dia, maratona_reg.mes, maratona_reg.ano);
	fprintf(arquivo_maratona, "\n \n");

	fclose(arquivo_maratona);
	printf("<== VOLTAR - PRESSIONE 0\n");
	scanf("%d", &op2);
}

int mostra_reg(){
	FILE *arquivo_maratona;
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;

	system("clear || cls");
	printf("> FORMATO\n");
	printf("> Código > Nome > Tempo (hh:mm:ss:ms) > Data (dd/mm/aaaa)\n");
	printf("> Pressione 1 para listar\n");
	scanf("%d", &op1);

	switch(op1){
		case 1:
			while(fscanf(arquivo_maratona, "%c", &c) != EOF){
				printf("%c", c);
			}
			fclose(arquivo_maratona);
		break;
	}
	printf("\n\n<== VOLTAR - PRESSIONE 0 ==> ");
	scanf("%d", &op2);
}

int del_reg(){
	FILE *arquivo_maratona;
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;
	system("clear || cls");

	if(fscanf(arquivo_maratona, "%c", &c) == EOF){
		printf("Nenhum Maratonista cadastrado!\n");
		insere_reg();
	}else{
		printf(" _________________________________\n");
		printf("| Apagar dados de um maratonista? |");
		printf("\n\nDigite 1 para continuar: ");
		scanf("%d", &op1);

		switch(op1){
			case 1:
				system("clear || cls");
				while(remove("maratona.txt") == 0){
					printf("Todos Maratonistas excluidos!!");
				}
				break;
		}
		printf("\n\n<== VOLTAR - PRESSIONE 0");
		scanf("%d", &op2);
	}
}

int menu(){
	for(;;){
		system("clear || cls");
		int opcao, tam, registros, i;

		printf(" ____________________________\n");
		printf("|			 MENU  			 |\n");
		printf("| 1 - Cadastrar Maratonista  |\n");
		printf("| 2 - Excluir Maratonistas   |\n");
		printf("| 3 - Listar Maratonistas    |\n");
		printf("| 0 - SAIR                   |\n");
		printf("| __________________________ |\n");
		printf("OPÇÃO: ");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("Defina a quantidade de registros\n");
  				printf("1 - POR QUANTIDADE\n");
  				printf("2 - POR TAMANHO DO ARQUIVO\n");
  				printf("0 - SAIR\n\n");
  				printf("Opção: ");
  				scanf("%d", &opcao);
  				if(opcao == 1){
  					printf("Digite a quantidade de registros = ");
  					scanf("%d", &registros);
  					printf("Quantidade Registros = %d\n", registros);
  					for(i=0; i<registros; i++){
  						insere_reg();
  					}
  				}else if(opcao == 2){
  					printf("Defina o tamanho do arquivo = ");
  					scanf("%d", &tam);
  					printf("Tamanho = %d\n", tam);
  				}else{
  					printf("Opção invalida - Encerrando programa");
  					return 0;
  				}
			break;

			case 2:
				del_reg();
			break;

			case 3:
				mostra_reg();
			break;

			case 0:
				exit(0);

		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
  	for(;;){
  		menu();
  	}
  	
  	return 0;
}
