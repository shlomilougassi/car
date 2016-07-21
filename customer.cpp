#include <iostream>
#include "customer.h"
#include "car.h"
#include "fileparser.h"
#pragma warning(disable:4996)

using namespace std;

customer::customer()
{
	customer::setfullname("Defult_first_name");
	customer::setfunds(123456.9);
	customer::setcurrentcar(NULL);
}

customer::customer(char* fullname, int id, float funds, car* currentcar)
{
	customer::setfullname(fullname);
	customer::setfunds(funds);
	customer::setid(id);
	customer::setcurrentcar(NULL);
}
customer::~customer()
{
	cout << "The customer was deleted" << endl;
}

void customer::setfullname(char* full_name)
{
	this->fullname = full_name;
}

void customer::setfunds(float funds)
{
	this->funds = funds;
}
void customer::setcurrentcar(car* currentcar)
{
	this->currentcar = currentcar;
}
void customer::setid(int id)
{
	this->id = id;
}

bool customer::assigncar(car* new_car)
{
	if (new_car == NULL) return false;
	else
	{
		customer::setcurrentcar(new_car);
		return true;
	}
}


customer & customer::operator=(const customer & cst)
{
	if (this == &cst) return (*this);
	delete this->currentcar;
	this->setid(cst.getid());
	this->setfunds(cst.getfunds());
	this->setfullname(cst.getfullname());
	this->setcurrentcar(cst.getcar());
	return (*this);
}

customer::customer(const customer & cst)
{
	this->setid(cst.getid());
	this->setfunds(cst.getfunds());
	this->setfullname(cst.getfullname());
	this->setcurrentcar(cst.getcar());
}
