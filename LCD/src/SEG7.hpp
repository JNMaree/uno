#include "stdint.h"

/* 7 segment LED display constants
    A
F       B
    G
E       C
    D
*/
//Ports/Pins
#define seg7PA 9
#define seg7PB 8
#define seg7PC 7
#define seg7PD 6
#define seg7PE 5
#define seg7PF 4
#define seg7PG 3
#define seg7PDP 2

//Default On state
#define s7ON 0      //1 for Common cathode, 0 for Common anode

//Bitfield for display segments
typedef struct segment7
{
    int A : 1;
    int B : 1;
    int C : 1;
    int D : 1;
    int E : 1;
    int F : 1;
    int G : 1;
    int PD : 1;
} seg7;

#define seg7_4DMode 1    //4 Digit mode
#if seg7_4DMode

    #define seg7D1 10
    #define seg7D2 11
    #define seg7D3 12
    #define seg7D4 13

    const uint8_t seg7digitPosition[] = {seg7D1, seg7D2, seg7D3, seg7D4};

    typedef struct segment7_4d
    {
        seg7 digit[4];
    } seg74D;

    void seg7Set4Digits(seg74D characters);
    void seg7Set4Dint(uint16_t display);
    void seg7delay(uint16_t time);
	void seg7Set(seg7 character, uint8_t digit);

#else

    void seg7Set(seg7 character);

#endif

const seg7 seg7digitArray[] = 
{
    //Hexadecimal Characters
    {s7ON, s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON, !s7ON},     //0
    {!s7ON, s7ON, s7ON, !s7ON, !s7ON, !s7ON, !s7ON, !s7ON}, //1
    {s7ON, s7ON, !s7ON, s7ON, s7ON, !s7ON, s7ON, !s7ON},    //2
    {s7ON, s7ON, s7ON, s7ON, !s7ON, !s7ON, s7ON, !s7ON},    //3
    {!s7ON, s7ON, s7ON, !s7ON, !s7ON, s7ON, s7ON, !s7ON},   //4
    {s7ON, !s7ON, s7ON, s7ON, !s7ON, s7ON, s7ON, !s7ON},    //5
    {s7ON, !s7ON, s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON},     //6
    {s7ON, s7ON, s7ON, !s7ON, !s7ON, !s7ON, !s7ON, !s7ON},  //7
    {s7ON, s7ON, s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON},      //8
    {s7ON, s7ON, s7ON, s7ON, !s7ON, s7ON, s7ON, !s7ON},     //9
    {s7ON, s7ON, s7ON, !s7ON, s7ON, s7ON, s7ON, !s7ON},     //A
    {!s7ON, !s7ON, s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON},    //b
    {s7ON, !s7ON, !s7ON, s7ON, s7ON, s7ON, !s7ON, !s7ON},   //C
    {!s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON, s7ON, !s7ON},    //d
    {s7ON, !s7ON, !s7ON, s7ON, s7ON, s7ON, s7ON, !s7ON},    //E
    {s7ON, !s7ON, !s7ON, !s7ON, s7ON, s7ON, s7ON, !s7ON},   //F

    //Punctuation Characters
    {!s7ON, !s7ON, !s7ON, !s7ON, !s7ON, !s7ON, !s7ON, s7ON},//.
    {!s7ON, !s7ON, !s7ON, s7ON, !s7ON, !s7ON, !s7ON, !s7ON},//_
};

void seg7Init();
void seg7Cycle(uint16_t duration);

