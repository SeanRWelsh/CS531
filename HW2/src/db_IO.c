#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "db.h"

MYSQL * connect(){
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0))){
		fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
		exit(1);
	}
	return conn;
}
