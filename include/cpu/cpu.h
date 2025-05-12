
#ifndef CPU_H
#define CPU_H


#include <cstdint>

class CPU
{

    private:
union {
    struct { uint8_t F ; uint8_t A; };
    uint16_t AF;
};




union {
    struct { uint8_t C ; uint8_t B; };
    uint16_t BC;
};



union {
    struct { uint8_t E ; uint8_t D; };
    uint16_t DE;
};


union {
    struct { uint8_t L ; uint8_t H; };
    uint16_t HL;
};


uint16_t SP , PC;

static const uint8_t FLAG_Z = 7;
static const uint8_t FLAG_N = 6;
static const uint8_t FLAG_H = 5;
static const uint8_t FLAG_C = 4;



public:

CPU() : AF(0X01B0), BC(0X0013), DE(0X00D8), HL(0X014D), SP(0XFFFE), PC(0X0100) {}

void reset();


bool getFlag(uint8_t flag);

void setFlag(uint8_t flag, bool value);

uint8_t readByte(uint16_t address);

uint16_t readWord(uint16_t address);

void writeByte(uint16_t address, uint8_t value);

void step();

void handleInterrupts();

void pushStack(uint16_t value);

uint16_t popStack();


uint8_t fetchByte();

uint16_t fetchWord();


};



#endif // CPU_H








