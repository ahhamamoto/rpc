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
int alter(MYSQL *conn, entry *data);
int delete(MYSQL *conn, entry *data);
void list(MYSQL *conn);
