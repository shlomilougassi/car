#include <iostream>
#include "wheels.h"
using namespace std;

wheels::wheels()
{
	wheels::setradius(16);
	wheels::setpsi(32);
	wheels::setflat(false);
	if ((getpsi() > 30) && (getradius() > 5) && (getflat() == false))
	{
		//cout << "wheel has been created successfully" << endl << "Wheel's Radius - " << getradius() << " PSI  - " << getpsi() << endl;
		wheels::setreadytouse(true);
	}
	else
	{
		//cout << "The weel couldn't creat due to bad valuse entered" << endl;
		wheels::setreadytouse(false);
	}
}
wheels::wheels(const int psi, const float radius, const bool flat)
{
	wheels::setradius(radius);
	wheels::setpsi(psi);
	wheels::setflat(flat);
	if ((getpsi() > 30) && (getradius() > 5) && (getflat() == false))
	{
		//cout << "wheel has been created successfully" << endl << "Wheel's Radius - " << getradius() << " PSI  - " << getpsi() << endl;
		wheels::setreadytouse(true);
	}
	else
	{
		//cout << "The weel couldn't create due to bad valuse entered" << endl;
		wheels::setreadytouse(false);
	}
}

wheels::~wheels()
{
	//cout << "wheels has been deleted" << endl;
}

void wheels::setpsi(int psi)
{
	if (psi > 30) this->psi = psi;
}


void wheels::setradius(float radius)
{
	if (radius > 5) this->radius = radius;
}


void wheels::setflat(bool flat)
{
	this->flat = flat;
}

void wheels::setreadytouse(bool readytouse)
{
	this->readytouse = readytouse;
}

