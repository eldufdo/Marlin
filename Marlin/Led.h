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
	void setPixel(uint16_t i,uint8_t r, uint8_t g,uint8_t b);
	void clear();
	void show();
	void showProgress();
private:
};

#endif
