#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <mysqld_error.h>
#include "db.h"
#include "address_t.h"
void create_table();
MYSQL *conn;

/* my_connect initializes a MySQL connection using the provided database credentials from db.h.
 * first mysql_init is called to prepare the MYSQL object.
 * mysql_real_connect is used to attempt the connection. If connection succeeds a message is printed
 * stating the success. otherwise the error is printed and the program shuts down
*/
void my_connect(){
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0))){
		fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
	}
	puts("successful connection");
}

/* my_db_insert accepts a pointer to a struct address_t item(node in the linked list). It uses the alias
 * and octet values in the struct object to construct a mysql_query. If the query fails, an error is 
 * printed and the program shuts down. otherwise it adds the node to the linked list.
 */
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

/* save_db loops through the linked list of address_t nodes and saves each node to the MySQL database.
 * if the list is empty, the program states that that there is nothing to save and returns to the 
 * calling function. If there are items to save then save_db drops the existing hostname table, 
 * recreates it, and then inserts each item from the list into the table.
 */
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

/* create_table creates the hostname table in the MySQL database. The table hast three fields an
 * auto-incrementing ID, and alias up to 10 characters, and an address stored as a string with 16
 * characters. This function silently succeeds or fails.
 */
void create_table(){
	if(mysql_query(conn, "CREATE TABLE hostname ("
				"id INT AUTO_INCREMENT PRIMARY KEY,"
				"alias VARCHAR(10) NOT NULL,"
				"ip VARCHAR(16) NOT NULL"
				");"));
}

/* read_db retrieves all records fromt he hostname table in the MySQL database and creates the linked
 * list from the tables records. It performs a SELECT query to get the alias and IP address for each
 * entry, formats the data, prints it to the console, and then passes it to add_to_list. If the query
 * fails, the function prints the error, and closes the connection.
 */
void read_db(){
	if (mysql_query(conn, "SELECT ip,alias FROM hostname")){
		fprintf(stderr, "%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	MYSQL_RES *result = mysql_store_result(conn);
	MYSQL_ROW row;
	while((row = mysql_fetch_row(result))){
		char my_fstring[30];
		snprintf(my_fstring, sizeof(my_fstring), "%s %s",row[0],row[1]);
		add_to_list(my_fstring);
	}
	puts("Successfully loaded db information into the list");
}
