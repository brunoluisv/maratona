#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista {
	int cod;
	char *nome;
	char *t_corrida;
	char *dt_corrida;
	struct lista *prox;
} Registros;

Registros *inicia_registros(int cod, char *nome, char *t_corrida, char *dt_corrida);
Registros *insere_registros(Registros *registros, int cod, char *nome, char *t_corrida, char *dt_corrida);
void mostra_registros(Registros *registros);

void insere();
void mostra();

Registros *principal = NULL;

Registros *inicia_registros(int cod, char *nome, char *t_corrida, char *dt_corrida){
	Registros *novo;

	novo = (Registros *)malloc(sizeof(Registros));
	novo->cod = cod;
	novo->nome = (char *)malloc(strlen(nome)+1);
	strncpy(novo->nome, nome, strlen(nome)+1);
	novo->t_corrida = (char *)malloc(strlen(t_corrida)+1);
	strncpy(novo->t_corrida, t_corrida, strlen(t_corrida)+1);
	novo->dt_corrida = (char *)malloc(strlen(dt_corrida)+1);
	strncpy(novo->dt_corrida, dt_corrida, strlen(dt_corrida)+1);
	novo->prox = NULL;

	return novo;
}

Registros *insere_registros(Registros *registros, int cod, char *nome, char *t_corrida, char *dt_corrida){
	Registros *novo;

	novo = (Registros *)malloc(sizeof(Registros));
	novo->cod = cod;
	novo->nome = (char *)malloc(strlen(nome)+1);
	strncpy(novo->nome, nome, strlen(nome)+1);
	novo->t_corrida = (char *)malloc(strlen(t_corrida)+1);
	strncpy(novo->t_corrida, t_corrida, strlen(t_corrida)+1);
	novo->dt_corrida = (char *)malloc(strlen(dt_corrida)+1);
	strncpy(novo->dt_corrida, dt_corrida, strlen(dt_corrida)+1);
	novo->prox = NULL;

	return novo;
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
