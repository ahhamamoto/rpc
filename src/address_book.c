#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

typedef struct entry entry;

struct entry {
  char *name;
  char *addr; 
  char *phone;
};

// abre um arquivos e carrega os seus dados no banco
int initialize(MYSQL *conn, FILE *file);

// insere uma entrada no banco de dados
void insert(MYSQL *conn, entry *data);

// altera uma das entradas no banco de dados
int alter(MYSQL *conn, entry *old, entry *new);

// deleta uma das entradas no banco
int delete(MYSQL *conn, entry *data);

// faz uma listagem das entradas no banco de dados
void list(MYSQL *conn);

// exibe um menu para a escolha da opcao a ser executada
void menu(void);

int main(int argc, char **argv) {
  MYSQL *conn;
  char *server = "localhost";
  char *user = "root";
  char *password = "toor";
  char *database = "aloha";
  conn = mysql_init(NULL);
  mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
		
	int choice;
	do {
		menu();
		scanf("%d", &choice);
	} while (choice != 0);

  mysql_close(conn);
  
  return 0;
}

int initialize(MYSQL *conn, FILE *file) {
  file = fopen("entrada.txt", "r");
  if (file != NULL && conn != NULL) {
    mysql_query(conn, "DELETE * FROM aloha");
  } else {
    fprintf(stderr, "Erro!!");
  }
}

void insert(MYSQL *conn, entry *data) {
  int n;
  char query[100];
  n = sprintf(query, "INSERT INTO teste VALUES('%s', '%s', '%s')", data->name, data->addr, data->phone);
  mysql_query(conn, query);
}

int alter(MYSQL *conn, entry *old, entry *new) {
  int n;
  char query[100];
  n = sprintf(query, "UPDATE teste SET name='%s', address='%s', phone='%s' WHERE name='%s'", new->name, new->addr, new->phone, old->name);
  printf("%s\n", query);
  if (!mysql_query(conn, query)) printf("%s\n", mysql_error(conn));
} 

int delete(MYSQL *conn, entry *data) {
  int n;
  char query[100];
  n = sprintf(query, "DELETE FROM teste WHERE name='%s'", data->name);
  mysql_query(conn, query);
}

void list(MYSQL *conn) {
  MYSQL_RES *res;
  MYSQL_ROW *row;
  mysql_query(conn, "SELECT * FROM teste");
  res = mysql_use_result(conn);
  while ((row = (MYSQL_ROW *) mysql_fetch_row(res)) != NULL) {
    printf("%s %s %s\n", (char *) row[0], (char *) row[1], (char *) row[2]);
  }
  mysql_free_result(res);
}

void menu(void) {
	printf("Escolha uma das opcoes abaixo:\n\n");
	printf("1 - Inicializar\n");
	printf("2 - Inserir uma entrada\n");
	printf("3 - Remover uma entrada\n");
	printf("4 - Consultar uma entrada(nao implementada)\n");
	printf("5 - Listar as entradas\n");
	printf("0 - Sair do programa\n");
}