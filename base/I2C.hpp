#include "stdint.h"

#define SCLpin 19
#define SDApin 18

#define durationSCL 20
#define durationSDA 10

extern char* dataBuff;

void i2cInit();
void i2cInterruptSDA();
void i2cPulseSCL();
void i2cWriteSDA(char data);

bool i2cWriteWAIT();
void i2cWriteSTART();
void i2cWriteSTOP();