#include <stdio.h>
#include <string.h>
#include "address_book.h"

void _initialize(CLIENT *clnt){
	//char * filename;
	FILE * file;
	int * result;
	entry  data;
	data.name.name_val = malloc(100 * sizeof(char));
	data.addr.addr_val = malloc(100 * sizeof(char));
	data.phone.phone_val = malloc(100 * sizeof(char));
	//printf("Digite o nome do arquivo:\n");
	//scanf("%s",filename);
	file = fopen("entrada.txt", "r");
	
	if (file != NULL) {
		result = drop_110(NULL, clnt);
		while(!feof(file)){
			fscanf(file,"%[^\n]%*c\n\n%[^\n]%*c\n\n%[^\n]%*c\n\n",data.name.name_val,data.addr.addr_val,data.phone.phone_val);
			data.name.name_len = (unsigned) strlen(data.name.name_val);
			data.addr.addr_len = (unsigned) strlen(data.addr.addr_val);
			data.phone.phone_len = (unsigned) strlen(data.phone.phone_val);
			result = insert_110(&data, clnt);
		}
	} else {
		fprintf(stderr, "Erro!!");
	}
}
void _insert(CLIENT *clnt){
	int * result = NULL;
	entry  data;
	data.name.name_val = malloc(100 * sizeof(char));
	data.addr.addr_val = malloc(100 * sizeof(char));
	data.phone.phone_val = malloc(100 * sizeof(char));

	fflush(stdin);
	printf("\nDigite o nome: ");
	//fscanf(stdin, "%s",data.name.name_val);
	getchar();
	scanf("%[^\n]%*c", data.name.name_val);
	data.name.name_len = (unsigned) strlen(data.name.name_val);
	printf("\nDigite o endereço: ");
	scanf("%[^\n]%*c", data.addr.addr_val);
	data.addr.addr_len = (unsigned) strlen(data.addr.addr_val);
	printf("\nDigite o telefone: ");
	scanf("%[^\n]%*c", data.phone.phone_val);
	data.phone.phone_len = (unsigned) strlen(data.phone.phone_val);
	
	result = insert_110(&data, clnt);
	//printf("%d\n",*result);
}

void _alter(CLIENT *clnt){
	int * result;
	entries  data;
	entry old,new;
	old.name.name_val = malloc(100 * sizeof(char));
	old.addr.addr_val = malloc(100 * sizeof(char));
	old.phone.phone_val = malloc(100 * sizeof(char));
	new.name.name_val = malloc(100 * sizeof(char));
	new.addr.addr_val = malloc(100 * sizeof(char));
	new.phone.phone_val = malloc(100 * sizeof(char));
	
	data.old = &old;
	data.new = &new;
	
	printf("\nDigite o nome atual: ");
	scanf("%s",data.old->name.name_val);
	data.old->name.name_len = (unsigned) strlen(data.old->name.name_val);
//	printf("\nDigite o endereço atual: ");
//	scanf("%s",data.old->addr.addr_val);
	data.old->addr.addr_len = (unsigned) strlen(data.old->addr.addr_val);
//	printf("\nDigite o telefone atual: ");
//	scanf("%s",data.old->phone.phone_val);
	data.old->phone.phone_len = (unsigned) strlen(data.old->phone.phone_val);
	printf("\nDigite o novo nome: ");
	scanf("%[^\n]%*c", data.new->name.name_val);
	data.new->name.name_len = (unsigned) strlen(data.new->name.name_val);
	printf("\nDigite o novo endereço: ");
	scanf("%[^\n]%*c", data.new->addr.addr_val);
	data.new->addr.addr_len = (unsigned) strlen(data.new->addr.addr_val);
	printf("\nDigite o novo telefone: ");
	scanf("%[^\n]%*c", data.new->phone.phone_val);
	data.new->phone.phone_len = (unsigned) strlen(data.new->phone.phone_val);

	result = alter_110(&data,clnt);
	//printf("%d\n",*result);	
}

void _delete(CLIENT *clnt){
	int * result;
	entry  data;
	data.name.name_val = malloc(100 * sizeof(char));
	data.addr.addr_val = malloc(100 * sizeof(char));
	data.phone.phone_val = malloc(100 * sizeof(char));

	printf("\nDigite o nome: ");
	scanf("%[^\n]%*c", data.name.name_val);
	data.name.name_len = (unsigned) strlen(data.name.name_val);
	data.addr.addr_len = (unsigned) strlen(data.addr.addr_val);
	data.phone.phone_len = (unsigned) strlen(data.phone.phone_val);
		

	result = delete_110(&data,clnt);
	//printf("%d\n",*result);	
}

void _consult(CLIENT *clnt){
	entry data;
	entry * result = malloc(sizeof(entry));
	data.name.name_val = malloc(100 * sizeof(char));
	data.addr.addr_val = malloc(100 * sizeof(char));
	data.phone.phone_val = malloc(100 * sizeof(char));

	printf("\nDigite o nome: ");
	scanf("%[^\n]%*c", data.name.name_val);
	data.name.name_len = (unsigned) strlen(data.name.name_val);
	data.addr.addr_len = (unsigned) strlen(data.addr.addr_val);
	data.phone.phone_len = (unsigned) strlen(data.phone.phone_val);
		
	
	result = consult_110(&data,clnt);

	if(result)
		printf("Endereço: %s\ntelefone: %s\n",result->addr.addr_val,result->phone.phone_val);	
	//printf("DEPOIS\n");
}
void
prog_110(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	char *drop_110_arg;
	int  *result_2;
	entry  insert_110_arg;
	int  *result_3;
	entries  alter_110_arg;
	int  *result_4;
	entry  delete_110_arg;
	entry  *result_5;
	entry  consult_110_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PROG, VERSAO, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = drop_110((void*)&drop_110_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = insert_110(&insert_110_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = alter_110(&alter_110_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = delete_110(&delete_110_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = consult_110(&consult_110_arg, clnt);
	if (result_5 == (entry *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	int choice=1;
	CLIENT *clnt;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	//prog_110 (host);

	clnt = clnt_create(argv[1], PROG, VERSAO, "udp");
  	if (clnt == (CLIENT *) NULL) {
    	clnt_pcreateerror(argv[1]);
    	exit(1);
  	}
 
  	while(choice !=0 ){
      printf("Escolha uma das opcoes abaixo:\n\n");
      printf("1 - Inicializar\n");
      printf("2 - Inserir uma entrada\n");
      printf("3 - Remover uma entrada\n");
      printf("4 - Consultar uma entrada\n");
      printf("5 - Alterar uma entrada\n");
      printf("0 - Sair do programa\n");
      
      scanf("%d",&choice);
      printf("choice: %d\n",choice);
      switch(choice){
        case 1:
          _initialize(clnt);
          break;
        case 2:
          _insert(clnt);
          break;
        case 3: 
          _delete(clnt);
          break;
        case 4:
          _consult(clnt);
          break;
        case 5:
          _alter(clnt);
          break;
      }
  }
exit (0);
}
