#include <iostream>
#include <string>
#include "car.h"
#include "lights.h"
#include "engine.h"
#include "wheels.h"
using namespace std;

car::car() : light(false), motor()
{
	car::setbrand("Tal");
	car::setmodel("Kot");
	wheel1 = new wheels();
	if (wheel1 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel2 = new wheels();
	if (wheel2 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel3 = new wheels();
	if (wheel3 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel4 = new wheels();
	if (wheel4 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	car::setowner_full_name("TAL KOT");
	car::setinshop(false);
	car::setcarid(1234567);
}

car::car(char* brand, char* model, bool lights_sending, int volume, float maxfuel, float currentfuel, bool malfunction, int psi1, int radius1, bool flat1, int psi2, int radius2, bool flat2, int psi3, int radius3, bool flat3, int psi4, int radius4, bool flat4, int carid) : light(lights_sending), motor(volume, maxfuel, currentfuel, malfunction)
{
	car::setbrand(model);
	car::setmodel(brand);
	wheel1 = new wheels(psi1, radius1, flat1);
	if (wheel1 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel2 = new wheels(psi2, radius2, flat2);
	if (wheel2 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel3 = new wheels(psi3, radius3, flat3);
	if (wheel3 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}
	wheel4 = new wheels(psi4, radius4, flat4);
	if (wheel4 == NULL)
	{
		cout << "ERROR, the computer is out of memory! the pointer counld not be created." << endl;
	}

	car::setcarid(carid);
}

car::~car()
{
	if (wheel1 != NULL)delete wheel1;
	if (wheel2 != NULL)delete wheel2;
	if (wheel3 != NULL)delete wheel3;
	if (wheel4 != NULL)delete wheel4;
	cout << "The car has been deleted" << endl;
}

void car::switchon()
{
	cout << "Turing the car on..." << endl;
	if (light.getactive() == false) light.togglelights();
	motor.activate(true);
	cout << "the engine turned on" << endl;
}
void car::switchoff()
{
	cout << "Turing the car off..." << endl;
	if (motor.getactivated() == true)motor.setactivated(false);
	light.togglelights();
	cout << "the engine turned off" << endl;
}

void car::drive()
{
	if (wheel1->getreadytouse() == false) wheel1->setreadytouse(true);
	if (wheel2->getreadytouse() == false) wheel2->setreadytouse(true);
	if (wheel3->getreadytouse() == false) wheel3->setreadytouse(true);
	if (wheel4->getreadytouse() == false) wheel4->setreadytouse(true);
	if (light.getactive() == false)light.togglelights();
	if (motor.getactivated() == false) motor.setactivated(true);
	cout << "the car is drivingggg...WOW!" << endl;
}
void car::setbrand(char* brand)
{
	this->brand =strdup(brand);
}
void car::setmodel(char* model)
{
	this->model =strdup(model);
}

void car::setowner_full_name(char* owner_full_name)
{
	this->owner_full_name = owner_full_name;
}

void car::setinshop(bool inshop)
{
	this->inshop = inshop;

}
void car::setcarid(int carid)
{
	this->carid = carid;
}

car & car::operator=(const car & o)
{
	if (this == &o) return (*this);
	lights(o.light.getmalfunction());
	engine(o.motor.getvolume(), o.motor.getmaxfuel(), o.motor.getfuel(), o.motor.getmalfunction());
	delete this->wheel1;
	delete this->wheel2;
	delete this->wheel3;
	delete this->wheel4;
	wheels* wheel1 = new wheels(o.wheel1->getpsi(), o.wheel1->getradius(), o.wheel1->getflat());
	wheels* wheel2 = new wheels(o.wheel2->getpsi(), o.wheel2->getradius(), o.wheel2->getflat());
	wheels* wheel3 = new wheels(o.wheel3->getpsi(), o.wheel3->getradius(), o.wheel3->getflat());
	wheels* wheel4 = new wheels(o.wheel4->getpsi(), o.wheel4->getradius(), o.wheel4->getflat());
	setbrand(o.getbrand());
	setmodel(o.getmodel());
	setowner_full_name(o.getowner_full_name());
	return (*this);

}

car::car(const car& secCar)
:light(secCar.light.getmalfunction()), motor(secCar.motor.getvolume(), secCar.motor.getfuel(), secCar.motor.getmaxfuel(), secCar.motor.getmalfunction())
{
	delete wheel1;
	delete wheel2;
	delete wheel3;
	delete wheel4;
	setbrand(secCar.getbrand());
	setmodel(secCar.getmodel());
	setowner_full_name(secCar.getowner_full_name());
	wheel1 = new wheels(secCar.wheel1->getpsi(), secCar.wheel1->getradius(), secCar.wheel1->getflat());
	wheel2 = new wheels(secCar.wheel2->getpsi(), secCar.wheel2->getradius(), secCar.wheel2->getflat());
	wheel3 = new wheels(secCar.wheel3->getpsi(), secCar.wheel3->getradius(), secCar.wheel3->getflat());
	wheel4 = new wheels(secCar.wheel4->getpsi(), secCar.wheel4->getradius(), secCar.wheel4->getflat());
}