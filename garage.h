#ifndef _GARAGE_
#define _GARAGE_
#include <iostream>
#include "customer.h"
#include "car.h"
#define amount_of_clients_from_file 4
using namespace std;

class garage
{
	car* cars_in_garage[amount_of_clients_from_file];
	customer* full_customers_list[amount_of_clients_from_file];
	customer* customers_in_garage[amount_of_clients_from_file];
	double funds;
	int how_many_in_garage;

public:
	garage();
	~garage();
	void setcars_in_garage();
	void setfull_customers_list();
	void setcustomers_in_garage();
	void setfunds_start(double funds);
	void setfunds(double funds);
	void sethow_many_in_garage_start(int to_change);
	void sethow_many_in_garage(int how_many_in_garage);
	inline int gethow_many_in_garage(){ return how_many_in_garage; }
	void set_create_full_customers_list(customer* to_add);
	bool addcustomer(customer& cr);
	bool checkincar(car* cr);
	bool checkout(customer& cst);
	bool checkoutcar(car& cr);
	double calculateprice(car* cr);
	bool print_customers_in_garage();
	bool print_cars_in_garage();
	int which_car_is_mine(customer& cst);
	inline double getfunds_garage()const{ return funds; }
	car* getcars_in_garage(int which_one);
	customer* getcustomers_in_garage(int which_one);
	
};
#endif
