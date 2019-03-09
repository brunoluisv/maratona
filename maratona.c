#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int cod;
	char *nome;
	char *t_corrida;
	char *dt_corrida;
} Registro;

int insere_reg(){
	FILE *arquivo_maratona;
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;

	if(arquivo_maratona == NULL){
		printf("Erro ao Abrir");
		return 1;
	}

	system("clear || cls");
	printf("|	INSERIR REGISTRO	|");
	printf("1 - Código Corredor: ");
	scanf("%d", &maratona_reg.id);
	fprintf(arquivo_maratona, "%d  ", maratona_reg.id);
	printf("2 - Nome Corredor: ");
	scanf("%[^\n]s", maratona_reg.nome);
	fprintf(arquivo_maratona, "%s ", maratona_reg.nome);
	printf("3 - Tempo de Corrida: ");
	scanf("%[^\n]s", maratona_reg.t_corrida);
	fprintf(arquivo_maratona, "%s ", maratona_reg.t_corrida);
	printf("4 - Data da Corrida: ");
	scanf("%[^\n]s", maratona_reg.dt_corrida);
	fprintf(arquivo_maratona, "%s ", maratona_reg.dt_corrida);

	fclose(arquivo_maratona);
	printf("<== VOLTAR - PRESSIONE 0");
	scanf("%d", &op2);
}

int mostra_reg(){
	FILE *arquivo_maratona;
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;

	system("clear || cls");
	printf("> 1 - ID Corredor\n");
	printf("> 2 - Nome Corredor\n");
	printf("> 3 - Tempo de Corrida\n");
	printf("> 4 - Data de Corrida\n");
	printf("> Pressione 1 para listar\n");
	scanf("%d", op1);

	switch(op1){
		case 1:
			while(fscanf(arquivo_maratona, "%c", &c) != EOF){
				printf("%c", c);
			}
			fclose(arquivo_maratona);
		break;
	}
	printf("\n\n<== VOLTAR - PRESSIONE 0");
	scanf("%d", &op2);
}



int main(){
	setlocale(LC_ALL, "Portuguese");
  	int op, registros, tam;
  	
  	printf("Defina a quantidade de registros\n");
  	printf("1 - POR QUANTIDADE\n");
  	printf("2 - POR TAMANHO DO ARQUIVO\n");
  	printf("0 - SAIR\n\n");
  	printf("Opção: ");
  	scanf("%d", &op);
  	if(op == 1){
  		printf("Digite a quantidade de registros = ");
  		scanf("%d", &registros);
  		printf("Quantidade Registros = %d\n", registros);
  	}else if(op == 2){
  		printf("Defina o tamanho do arquivo = ");
  		scanf("%d", &tam);
  		printf("Tamanho = %d\n", tam);
  	}else{
  		return 0;
  	}
  	return 0;
}
