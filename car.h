#ifndef _CAR_
#define _CAR_
#include <iostream>
#include <string>
#include "car.h"
#include "lights.h"
#include "engine.h"
#include "wheels.h"

using namespace std;

class car
{
	engine motor;
	lights light;
	wheels* wheel1;
	wheels* wheel2;
	wheels* wheel3;
	wheels* wheel4;
	char* model;
	char* brand;
	bool inshop;
	char* owner_full_name;
	int carid;
public:
	car();
	car(char* brand, char* model, bool lights_sending, int volume, float maxfuel, float currentfuel, bool malfunction, int psi1, int radius1, bool flat1, int psi2, int radius2, bool flat2, int psi3, int radius3, bool flat3, int psi4, int radius4, bool flat4, int carid);
	~car();
	car(const car& secCar);
	car& operator=(const car & o);
	void switchon();
	void switchoff();
	void drive();
	void setinshop(bool inshop);
	inline bool getinshop() const { return inshop; }
	inline char* getowner_full_name() const { return owner_full_name; }
	void setowner_full_name(char* owner_full_name);
	void setbrand(char* brand);
	void setcarid(int carid);
	void setmodel(char* model);
	inline engine& getmotor()  {return motor;}
	inline wheels* getwheel1() const { return wheel1; }
	inline wheels* getwheel2() const { return wheel2; }
	inline wheels* getwheel3() const { return wheel3; }
	inline wheels* getwheel4() const { return wheel4; }
	inline lights& getlights() {return light;}
	inline char* getbrand() const { return brand; }
	inline char* getmodel() const { return model; }
	inline int getcarid() const { return carid; }

};
#endif