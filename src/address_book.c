#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

typedef struct entry entry;

struct entry {
  char *name;
  char *addr; 
  char *phone;
};

int initialize(MYSQL *conn, FILE *file);
void insert(MYSQL *conn, entry *data);
int alter(MYSQL *conn, entry *old, entry *new);
int delete(MYSQL *conn, entry *data);
void list(MYSQL *conn);

int main(int argc, char **argv) {
  printf("Hello!\n");
  MYSQL *conn;
  char *server = "localhost";
  char *user = "root";
  char *password = "toor";
  char *database = "aloha";
  conn = mysql_init(NULL);
  mysql_real_connect(conn, server, user, password, database, 0, NULL, 0);
  
  entry *data = malloc(sizeof(entry));
  entry *new = malloc(sizeof(entry));
  new->name = "joelma ";
  new->addr = "é um ";
  new->phone = "baitola";
  data->name = "Joelma ";
  data->addr = "é um ";
  data->phone = "viadão";
  insert(conn, data);
  list(conn);
  alter(conn, data, new);
  list(conn);
  delete(conn, data);

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
  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("%s %s %s\n", row[0], row[1], row[2]);
  }
  mysql_free_result(res);
}
