//DatabaseConnection.cpp

//implementation of h file
//better include in cpp instead of h

#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection()
{
	mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://127.0.0.1", "root", "");

	connection->setSchema("e-spbt");
}

DatabaseConnection::~DatabaseConnection()
{
	connection->close();
	delete connection;
}

PreparedStatement* DatabaseConnection::prepareStatement(string query)
{
	return connection->prepareStatement(query);
}
