#ifndef _ENGINE_
#define _ENGINE_
#include <iostream>
using namespace std;

class engine
{
	float volume, currentfuel, maxfuel;
	bool activated;
	bool malfunction;
public:

	engine();
	engine(float volume, float currentfuel, float maxfuel, bool malfunction);
	~engine();
	void setfuel(float currentfuel);
	inline float getfuel() const { return this->currentfuel; }
	inline float getmaxfuel() const { return this->maxfuel; }
	void setmaxfuel(float maxfuel);
	inline float getvolume() const { return this->volume; }
	void setvolume(float volume);
	void setactivated(bool activated);
	inline bool getactivated() const { return activated; }
	void activate(bool activated);
	inline bool getmalfunction() const { return malfunction; }
	void setmalfunction(bool malfunction);
};
#endif
