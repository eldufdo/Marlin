#ifndef Led_h
#define Led_h

#include <inttypes.h>
#include "Adafruit_NeoPixel.h"

class Led
{
public:
	Led();
	~Led(); 
	void bootAnimation();
	Adafruit_NeoPixel *pixels;
private:
};

#endif
