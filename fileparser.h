#ifndef _FILEPARSER_
#define _FILEPARSER_
#include <iostream>
#include "car.h"
#include "customer.h"

using namespace std;

class fileParser
{
public:
	fileParser();
	~fileParser();
	customer* parsecustomerfile(char* file_name);
	car* parsecarfile(char* file_name);
};
#endif