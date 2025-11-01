#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "db.h"
#include "address_t.h"

MYSQL *conn;
void my_connect(){
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0))){
		fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
	}
	puts("successful connection");
//	return conn;
}

void my_db_insert(struct address_t *item){
	char buffer[100];
	snprintf(buffer, sizeof(buffer), "INSERT INTO hostnames (alias, ip) VALUES('%s', '%d.%d.%d.%d')",item->alias, item->octet[0], item->octet[1], item->octet[2], item->octet[3]);
	printf("%s\n", buffer);


	if(mysql_query(conn, buffer)){
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
}

void save_db(){
	struct address_t *current;
	current = head;

	if(head == NULL){
		puts("List is empty nothing saved");
		return;
	}else{
		while(current != NULL){
			my_db_insert(current);
			current = current->next;
		}
	}
}

