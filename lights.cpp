#include <iostream>
#include "lights.h"
using namespace std;

lights::lights(bool lights_sending)
{
	if (lights_sending == false)
	{
		lights::setactive(false);
		lights::setmalfunction(true);
	}
	else
	{
		lights::setactive(false);
		lights::setmalfunction(false);
	}
	//cout << "Lights constructor created light for your car"  << endl;
}
lights::~lights()
{
	//cout << "Lights distructor destroyed car's light" << endl;
}


void lights::setactive(bool active)
{
	if ((active == true) || (active == false))
	{
		this->active = active;
		//cout << "New lights mode was updated" << endl;
	}
	else
	{
		cout << "lights could not be configurated - due wrong input" << endl;
	}
}
void lights::setmalfunction(bool malfunction)
{

		this->malfunction = malfunction;
		//cout << "New malfunction for lights mode was updated" << endl;
}
void lights::setlights_sending(bool lights_sending)
{

	this->lights_sending = lights_sending;
	//cout << "New malfunction for lights mode was updated" << endl;
}

void lights::togglelights()
{
	if (getactive() == true)
	{
		setactive(false);
		cout << "Lights turned off" << endl << endl;
	}
	else
	{
		setactive(true);
		cout << "Lights turned on" << endl << endl;
	}
}
