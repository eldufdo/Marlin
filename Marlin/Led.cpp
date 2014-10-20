#include "Led.h"
#include <Configuration.h>
#include "cardreader.h"

Led::Led() 
{
	this->pixels = new Adafruit_NeoPixel(WS2812_NUM_LEDS, WS2812_PIN, NEO_GRB + NEO_KHZ800);
	this->pixels->begin();
}

Led::~Led() 
{
	delete(this->pixels);
}

void Led::bootAnimation() 
{
	for(int i=0;i<WS2812_NUM_LEDS;i++)
	{
		pixels->setPixelColor(i, pixels->Color(0,150,0)); // Moderately bright green color.
		pixels->show(); // This sends the updated pixel color to the hardware.
		delay(50); // Delay for a period of time (in milliseconds).
	}
	for(int i=0;i<WS2812_NUM_LEDS;i++)
	{
		pixels->setPixelColor(i, pixels->Color(150,0,0)); // Moderately bright green color.
		pixels->show(); // This sends the updated pixel color to the hardware.
		delay(50); // Delay for a period of time (in milliseconds).
	}
	for(int i=0;i<WS2812_NUM_LEDS;i++)
	{
		pixels->setPixelColor(i, pixels->Color(0,0,150)); // Moderately bright green color.
		pixels->show(); // This sends the updated pixel color to the hardware.
		delay(50); // Delay for a period of time (in milliseconds).
	}
}

void Led::showProgress() {
	if (IS_SD_PRINTING) {
		uint8_t progress = card.percentDone();
		uint8_t led_step = 100/WS2812_NUM_LEDS;
		uint8_t i;
		uint8_t s = 0;
		this->clear();
		for (i = 0; i < progress;i+=led_step) {
			this->setPixel(s,0,0,180);
			s++;
		}
		this->show();
	}
}

void Led::setPixel(uint16_t index,uint8_t r, uint8_t g, uint8_t b) 
{
	pixels->setPixelColor(index,pixels->Color(r,g,b));
}

void Led::show() 
{
	pixels->show();
}

void Led::clear() 
{
	pixels->clear();
}
