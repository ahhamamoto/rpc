/*
  Anderson Hiroshi Hamamoto
  - Para compilar o programa:
  "gcc -o test_mysql test_mysql.c $(mysql_config --libs)"
  - Pra fazer o teste, o usuário root do banco de dados deve ter
  a senha "toor" ou colocar a senha do seu root ai
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char *argv[]) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW *row;
  char *server = "localhost";
  char *user = "root";
  char *password = "toor";
  char *database = "mysql";
  conn = mysql_init(NULL);
  /* Conectar ao banco de dados */
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return 1;
  }
  /* Mandar a query */
  if (mysql_query(conn, "show tables")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return 1;
  }
  res = mysql_use_result(conn);
  /* Printar o nome da tabela */
  printf("Tabelas no banco de dados mysql:\n");
  while ((row = mysql_fetch_row(res)) != NULL)
    printf("%s\n", row[0]);
  /* Fechar a conexao */
  mysql_free_result(res);
  mysql_close(conn);
  
  return 0;
}
