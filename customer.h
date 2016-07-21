#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <iostream>
#include "car.h"
#include "customer.h"


using namespace std;

class customer
{
	char* fullname;
	int id;
	float funds;
	car* currentcar;

public:

	customer();
	~customer();
	customer(const customer& cst);
	customer& operator=(const customer & cst);
	customer(char* fullname, int id, float funds, car* currentcar);
	void setfullname(char* fullname);
	void setid(int id);
	void setfunds(float funds);
	void setcurrentcar(car* currentcar);
	inline char* getfullname() const {return fullname;}
	inline float getfunds() const {return this->funds;}
	inline car* getcar() const {return currentcar;}
	inline int getid() const {return this->id;}
	bool assigncar(car* new_car);
};
#endif

