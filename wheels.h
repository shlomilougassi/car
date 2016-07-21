#ifndef _WHEELS_
#define _WHEELS_
#include <iostream>
using namespace std;

class wheels
{
	int psi;
	float radius;
	bool flat;
	bool readytouse;
public:
	wheels();
	wheels(const int psi, const float radius, const bool flat);
	~wheels();
	void setpsi(int psi);
	inline int getpsi()const{ return this->psi; }
	void setradius(float radius);
	inline float getradius()const{return this->radius;}
	inline bool getflat()const{ return this->flat; }
	void setflat(bool flat);
	void setreadytouse(bool readytouse);
	inline bool getreadytouse()const{ return readytouse; }
};
#endif
