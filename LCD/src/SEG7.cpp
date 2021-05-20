#include "SEG7.hpp"
#include "Arduino.h"
#include "math.h"


void seg7Init()
{
    pinMode(seg7PA, OUTPUT);
    pinMode(seg7PB, OUTPUT);
    pinMode(seg7PC, OUTPUT);
    pinMode(seg7PD, OUTPUT);
    pinMode(seg7PE, OUTPUT);
    pinMode(seg7PF, OUTPUT);
    pinMode(seg7PG, OUTPUT);
    pinMode(seg7PDP, OUTPUT);

    #if seg7_4DMode
        pinMode(seg7D1, OUTPUT);
        pinMode(seg7D2, OUTPUT);
        pinMode(seg7D3, OUTPUT);
        pinMode(seg7D4, OUTPUT);
		Serial.begin(9600);
    #endif
}

void seg7Cycle(uint16_t duration)
{
    for (size_t i = 0; i < 16; i++)
    {
        #if seg7_4DMode
            seg74D s7 = {seg7digitArray[i], seg7digitArray[i], seg7digitArray[i], seg7digitArray[i]};
            seg7Set4Digits(s7);
        #else
            seg7Set(seg7DisplayArray[i]);
        #endif
        delay(duration);
    }
}


//4 Digit mode functions
#if seg7_4DMode

	static seg74D currentDisplay;

	void seg7Set(seg7 character, uint8_t digi)
	{
		digitalWrite(seg7PA, character.A);
		digitalWrite(seg7PB, character.B);
		digitalWrite(seg7PC, character.C);
		digitalWrite(seg7PD, character.D);
		digitalWrite(seg7PE, character.E);
		digitalWrite(seg7PF, character.F);
		digitalWrite(seg7PG, character.G);
		digitalWrite(seg7PDP, character.PD);

		currentDisplay.digit[digi] = character;
	}

	void seg7Set4Digits(seg74D characters)
	{
		for (size_t d = 0; d < 4; d++)
		{
			seg7Set(characters.digit[d], d);
			digitalWrite(seg7digitPosition[d], !s7ON);
			delay(2);
			digitalWrite(seg7digitPosition[d], s7ON);
		}
	}

	void seg7Set4Dint(uint16_t display)
	{
		//uint8_t digi1 = display / 1000;
		seg74D s7disp;
		//uint8_t digi2 = (display-digi1*1000) / 100;
		//uint8_t digi3 = (display-digi1*1000-digi2*100) / 10;
		//uint8_t digi4 = display-digi1*1000-digi2*100-digi3*10;
		uint8_t di = 4; //number of digits in int
		uint16_t dg[di]; //digit array of int

		//Set first digit
		dg[0] = display / pow(10, di -1);
		s7disp.digit[0] = seg7digitArray[dg[0]];

		//Calculate the remaining digits in their respective decimal positions
		for (size_t i = 1; i < di; i++)
		{
			dg[i] = display;
			for (size_t j = 0; j < i; j++)
			{
				dg[i] -= dg[j]*pow(10, di -j -1);
			}
			uint8_t exp10 = di -i -1;
			dg[i] /= pow(10, exp10);

			//Set digits to corresponding displayArray entry
			s7disp.digit[i] = seg7digitArray[dg[i]];
		}
		Serial.println(display);
		
		//Write display
		seg7Set4Digits(s7disp);
	}

	void seg7delay(uint16_t time)
	{
		uint16_t counter = time; 
		while(counter > 0)
		{
			seg7Set4Digits(currentDisplay);
			counter -= 8;
		}
	}

#else

	void seg7Set(seg7 character)
	{
		digitalWrite(seg7PA, character.A);
		digitalWrite(seg7PB, character.B);
		digitalWrite(seg7PC, character.C);
		digitalWrite(seg7PD, character.D);
		digitalWrite(seg7PE, character.E);
		digitalWrite(seg7PF, character.F);
		digitalWrite(seg7PG, character.G);
		digitalWrite(seg7PDP, character.PD);
	}

#endif