#include "I2C.hpp"
#include <Arduino.h>

bool stateSCL;
bool stateSDA;
bool stateSTART;
bool stateSTOP;

char* dataBuff;

void i2cInit()
{
    stateSCL = false;
    stateSDA = false;
    stateSTART = false;
    stateSTOP = false;

    pinMode(SCLpin, OUTPUT);
	pinMode(SDApin, INPUT);
    digitalWrite(SCLpin, stateSCL);
    digitalWrite(SDApin, stateSDA);
    attachInterrupt(digitalPinToInterrupt(SDApin), i2cInterruptSDA, CHANGE);
}

void i2cInterruptSDA()
{
    if(stateSCL && stateSDA){
        stateSTART = true;
    }
    else if(stateSCL && !stateSDA){
        stateSTOP = true;
    }
}

void i2cPulseSCL()
{
    stateSCL = !stateSCL;
    digitalWrite(SCLpin, stateSCL);
    delayMicroseconds(durationSCL);
    stateSCL = !stateSCL;
    digitalWrite(SCLpin, stateSCL);
}

void i2cWriteSDA(char data)
{
    int8_t durSCL = (durationSCL - durationSDA)/2;
    
    //8bit (1Byte) Data write
    for (size_t b = 0; b < 7; b++)
    {
        stateSCL = !stateSCL;
        digitalWrite(SCLpin, stateSCL);
        delayMicroseconds(durSCL);
        
        //write SDA
        digitalWrite(SDApin, (data >> b) & 1 ? 1 : 0);
        delayMicroseconds(durationSDA);
        digitalWrite(SDApin, stateSDA);

        delayMicroseconds(durationSCL);
        stateSCL = !stateSCL;
        digitalWrite(SCLpin, stateSCL);
    }
}

void i2cReadSlave(char address)
{   
    pinMode(SDApin, INPUT);
    while(!stateSTOP)
    {
        i2cPulseSCL();
        if(digitalRead(SDApin) && digitalRead(SCLpin)){

        }
        else{

        }
    }

    //Reset STOP flag
    stateSTOP = false;

}

void i2cWriteSlave(char address, char reg, char* data)
{
    //START condition
    i2cWriteSTART();

    //Address + R/W data write
    char addrw = (address << 1);
    i2cWriteSDA(addrw);

    //SDA to mode:Input & wait for ACK
    bool ack = i2cWriteWAIT();
    if(ack)
        i2cWriteSDA(reg);
    

    //SDA to mode:Output
    ack = i2cWriteWAIT();
    if(ack)
    {   
        bool fin = false;
        int8_t ic = 0;
        while(!fin)
        {
            i2cWriteSDA(data[ic]);           
        }
    }    

    //STOP condition
    i2cWriteSTOP();
}

bool i2cWriteWAIT()
{
    bool ack = false;
    int8_t timeout = 0;
    pinMode(SDApin, INPUT);
    while(!ack && timeout < 8)
    {
        i2cPulseSCL();
        if(!digitalRead(SDApin)){
            ack = true;
        }
        timeout++;
    }
    pinMode(SDApin, OUTPUT);   
    return ack;
}

void i2cWriteSTART()
{
    digitalWrite(SCLpin, stateSCL);
    delayMicroseconds(durationSCL/2);
    digitalWrite(SDApin, !stateSDA);
    delayMicroseconds(durationSCL/2);
}

void i2cWriteSTOP()
{
    digitalWrite(SCLpin, stateSCL);
    delayMicroseconds(durationSCL/2);
    digitalWrite(SDApin, stateSDA);
    delayMicroseconds(durationSCL/2);
}