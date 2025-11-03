#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <mysqld_error.h>
#include "db.h"
#include "address_t.h"
void create_table();
MYSQL *conn;
void my_connect(){
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0))){
		fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
	}
	puts("successful connection");
}

void my_db_insert(struct address_t *item){
	char buffer[100];
	snprintf(buffer, sizeof(buffer), "INSERT INTO hostname (alias, ip) VALUES('%s', '%d.%d.%d.%d')",item->alias, item->octet[0], item->octet[1], item->octet[2], item->octet[3]);
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
		mysql_query(conn, "DROP TABLE hostname");
		create_table();
		while(current != NULL){
			my_db_insert(current);
			current = current->next;
		}
	}
}

void create_table(){
	if(mysql_query(conn, "CREATE TABLE hostname ("
				"id INT AUTO_INCREMENT PRIMARY KEY,"
				"alias VARCHAR(10) NOT NULL,"
				"ip VARCHAR(16) NOT NULL"
				");"));
}

void read_db(){
	if (mysql_query(conn, "SELECT ip,alias FROM hostname")){
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	MYSQL_RES *result = mysql_store_result(conn);
//	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	while((row = mysql_fetch_row(result))){
		char my_fstring[30];
		snprintf(my_fstring, sizeof(my_fstring), "%s %s",row[0],row[1]);
		printf("%s", my_fstring);
		add_to_list(my_fstring);
	}
		puts("");
}

