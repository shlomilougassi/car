//shlomi lougassi 300620077
//tal kot 305468050
#include <iostream>
#include "car.h"
#include "customer.h"
#include "fileparser.h"
#include "garage.h"
#define amount_of_clients_from_file 4
using namespace std;

void matching_cars_to_customers(customer* ptr_customer[], car* ptr_car[], int which_car)
{
	for (int i = 0; i < amount_of_clients_from_file; i++)
	{
		if (ptr_customer[i]->getid() == ptr_car[which_car]->getcarid())
		{
			ptr_customer[i]->assigncar(ptr_car[which_car]);
			ptr_car[which_car]->setowner_full_name(ptr_customer[i]->getfullname());
		}
	}
}

void main(int argc, char* argv[])
{
	int whichaction = 0, choose_customer = 0, do_you_want_to_fix = 0, which_car_is_mine = 0, which_car_to_fix = 0, i = 0;
	fileParser* filep = new fileParser();
	customer* ptr_customer[amount_of_clients_from_file] = { NULL };
	car* ptr_car[amount_of_clients_from_file] = { NULL };

	for ( i = 0; i < amount_of_clients_from_file; i++)
	{
		ptr_customer[i] = filep->parsecustomerfile(argv[1]);
		ptr_car[i] = filep->parsecarfile(argv[2]);

	}

	for (i = 0; i < amount_of_clients_from_file; i++) matching_cars_to_customers(ptr_customer, ptr_car, i);
	garage* ptr_garage = new garage();
	for (i = 0; i < amount_of_clients_from_file; i++)ptr_garage->set_create_full_customers_list(ptr_customer[i]);

	cout << "Hello user,";
	do
	{
		cout  <<endl<< "Please choose your wanted action from the list below - " << endl << "(1)\t To print full customers list" << endl << "(2)\t To print all registered cars in the garage" << endl << "(3)\t To print all the registered customers in the garage" << endl << "(4)\t To exit the program" << endl;
		cout << "Please choose your action - ";
		cin >> whichaction;
		while ((whichaction != 1) && (whichaction != 2) && (whichaction != 3) && (whichaction != 4))
		{
			cout << "Please use valid input" << endl;
			cin >> whichaction;
		}

		if (whichaction == 1)
		{
			cout << "Please choose customer from the list:" << endl;
			for (int temp = 0; temp < amount_of_clients_from_file; temp++) cout <<"(" << temp + 1 <<")\t" << ptr_customer[temp]->getfullname() << endl ;
			cout << "The customer you want to check his car is - ";
			cin >> choose_customer;
			--choose_customer;
			while (choose_customer>amount_of_clients_from_file-1 || choose_customer < 0)
			{
				cout << "Please use valid input" << endl;
				cin >> choose_customer;
				--choose_customer;
			}


			if (!ptr_customer[choose_customer]->getcar())
			{
				cout << "ERROR - The car is already in the garage - you can't sent it twice" << endl;
			}
			else
			{
				if (ptr_garage->calculateprice(ptr_customer[choose_customer]->getcar()) == 0)
				{
					cout << "There are no malfuncations in this client's car" << endl;
				}
				else
				{
					if (ptr_garage->calculateprice(ptr_customer[choose_customer]->getcar()) > 0)
					{
						cout << endl << "this client's car needs to be fix." << endl << "in order for us to fix all the malfuncations, it will cost the client - " << ptr_garage->calculateprice(ptr_customer[choose_customer]->getcar()) << "$" << endl;
						if (ptr_customer[choose_customer]->getfunds() < ptr_garage->calculateprice(ptr_customer[choose_customer]->getcar()))
						{
							cout << "you don't have enough money to fix your car - try to get a better job :)" << endl;
						}
						else
						{
							cout << "do you want to check your car in to the garage?" << endl;
							cout << "1.  Yes " << endl << "2.  No " << endl << "Please choose your action - ";
							cin >> do_you_want_to_fix;
							while ((do_you_want_to_fix != 1) && (do_you_want_to_fix != 2))
							{
								cout << "plaese use valid input" << endl;
								cin >> do_you_want_to_fix;
							}
							if (do_you_want_to_fix == 2)
							{
								cout << "You chose not to fix the client's car" << endl;
							}
							else
							{
								ptr_garage->addcustomer(*ptr_customer[choose_customer]);
								cout << "The client's car sent to the garage" << endl;
							}
						}
					}
				}
			}
		}

		else if (whichaction == 2)
		{
			cout << "You choose to print the cars that are currnet location is the garage:" << endl;
			if (ptr_garage->print_cars_in_garage())
			{
				cout << endl << "choose the car that you want to fix: " << endl;
				cin >> which_car_to_fix;
				--which_car_to_fix;
				while ((which_car_to_fix>=ptr_garage->gethow_many_in_garage()) || (which_car_to_fix<0))
				{
					cout << "plaese use valid input" << endl;
					cin >> which_car_to_fix;
					--which_car_to_fix;
				}
				ptr_garage->checkoutcar(*ptr_garage->getcars_in_garage(which_car_to_fix));
			}
		}
		
		else if (whichaction == 3)
		{
			cout<< "You choose to print the customers that are currnet location is the garage:" << endl;
			if (ptr_garage->print_customers_in_garage())
			{
				cout << endl << "choose the customer that you want to fix: " << endl;
				int which_customer_to_fix = 0;
				cin >> which_customer_to_fix;
				--which_customer_to_fix;
				while ((which_customer_to_fix>=ptr_garage->gethow_many_in_garage()) || (which_customer_to_fix<0))
				{
					cout << "plaese use valid input" << endl;
					cin >> which_customer_to_fix;
					--which_customer_to_fix;
				}
				which_car_is_mine = ptr_garage->which_car_is_mine(*ptr_garage->getcustomers_in_garage(which_customer_to_fix));
				if (which_car_is_mine == -1)
				{
					cout << "The client doesn't have a car in the garage" << endl;
				}
				else ptr_garage->checkoutcar(*ptr_garage->getcars_in_garage(which_car_is_mine));
			}
		}
		else if (whichaction == 4)
		{
			cout << "You choose to exit the program, thank you for using.." << endl;
			break;
		}
	} while ((whichaction == 1) || (whichaction == 2) || (whichaction == 3));

	

	
	if (ptr_garage != NULL)delete ptr_garage;
	if (filep != NULL)delete filep;
	for (int i = 0; i < amount_of_clients_from_file; i++)
	{
		if (ptr_customer[i] != NULL) delete ptr_customer[i];
		if (ptr_car[i] != NULL)delete ptr_car[i];
	}
	
	system("PAUSE");
}
