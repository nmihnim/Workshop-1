//DatabaseConnection.h
#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

class DatabaseConnection
{
private:
	Connection* connection;
	//represent connection from application to mySQL (read up more)

public:

	DatabaseConnection();
	~DatabaseConnection();
	//constructorand destructor

	PreparedStatement* prepareStatement(string query);
	//return prepared statement (use to send mysql statement to database)
};

#endif
