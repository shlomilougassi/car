#ifndef _LIGHTS_
#define _LIGHTS_
#include <iostream>
using namespace std;

class lights
{
	bool active;
	bool malfunction;
	bool lights_sending;
public:
	lights(bool lights_sending);
	~lights();
	void setactive(bool active);
	inline bool getactive()const { return active; }
	void setmalfunction(bool malfunction);
	inline bool getmalfunction()const { return malfunction; }
	inline bool getlights_sending()const { return lights_sending; }
	void togglelights();
	void setlights_sending(bool lights_sending);
};
#endif
