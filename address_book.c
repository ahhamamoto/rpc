#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int initialize(MYSQL *conn, FILE *file);
void insert(MYSQL *conn, char *name, char *phone, char *addr);
int alter(MYSQL *conn, char *name);
int remove(MYSQL *conn, char *name);
void list(MYSQL *conn);

void initialize(MYSQL *conn) {}

void insert(MYSQL *conn, char *name, char *phone, char *addr) {}

int alter(MYSQL *conn, char *name) {}

void remove(MYSQL *conn, char *name) {}

void list(MYSQL *conn) {}