//textbook.h
#include <string>
using namespace std;

#ifndef TEXTBOOK_H
#define TEXTBOOK_H

class textbook {
	public:
		string textbook_id, textbook_name, date, publisher, yearform, spbt_id;
		int stock;
		double price, amountlost;
		
};

#endif