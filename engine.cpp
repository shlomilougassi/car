#include <iostream>
#include "engine.h"
using namespace std;

engine::engine()
{
	engine::setvolume(1350);
	engine::setfuel(100);
	engine::setmaxfuel(1000);
	engine::setmalfunction(false);
	engine::activate(false);
	if ((getmaxfuel() > 20) && (getmalfunction() == false) && (getfuel() > 0) && (getvolume() > 1300)){
		//cout << "The engine has been created successfully with values of: " << endl << "volume  - " << volume << ", fuel level  - " << currentfuel << ", maxfuel  - " << maxfuel << endl;
	}
	//else cout << "the engine could not be created due to wrong values entered" << endl;
}
engine::engine(float volume, float currentfuel, float maxfuel, bool malfunction)
{
	engine::setvolume(volume);
	engine::setfuel(currentfuel);
	engine::setmaxfuel(maxfuel);
	engine::activate(false);
	engine::setmalfunction(malfunction);
	if ((getmaxfuel() > 20) && (getmalfunction() == false) && (getfuel() > 0) && (getvolume() > 1300)){
		//cout << "The engine has been created successfully with values of: " << endl << "volume  - " << volume << ", fuel level - " << currentfuel << ", maxfuel- " << maxfuel << endl;
	}
	//else cout << "the engine could not be created due to wrong values entered" << endl;
}

engine::~engine()
{
	//cout << "The engine was deleted" << endl;
}

void engine::setfuel(float currentfuel)
{
	if (currentfuel > 0) this->currentfuel = currentfuel;
}


void engine::setmaxfuel(float maxfuel)
{
	if (maxfuel > 20) this->maxfuel = maxfuel;
}

void engine::setvolume(float volume)
{
	if (volume > 1300) this->volume = volume;
}

void engine::setactivated(bool activated)
{
	this->activated = activated;
}

void engine::activate(bool activated)
{
	if (getactivated() == false) setactivated(true);
	else setactivated(false);
}

void engine::setmalfunction(bool malfunction)
{
	this->malfunction = malfunction;
}

