

#ifndef MEMORY_H
#define MEMORY_H


#include <cstdint>
#include <array>
#include <iostream>
#include <string>

class Memory
{
    
    private:
        std::array<uint8_t, 0x10000> memory;



    public:

        Memory(); 

        static const uint16_t ROM_BANK0_START = 0x0000;
        static const uint16_t ROM_BANK0_END = 0x3FFF;
        static const uint16_t ROM_BANKN_N_START = 0x4000;
        static const uint16_t ROM_BANKN_N_END = 0x7FFF;
        static const uint16_t VRAM_START = 0x8000;
        static const uint16_t VRAM_END = 0x9FFF;
        static const uint16_t EXTERNAL_RAM_START = 0xA000;
        static const uint16_t EXTERNAL_RAM_END = 0xBFFF;
        static const uint16_t WRAM_START = 0xC000;
        static const uint16_t WRAM_END = 0xDFFF;
        static const uint16_t ECHO_RAM_START = 0xE000;
        static const uint16_t ECHO_RAM_END = 0xFDFF;
        static const uint16_t OAM_START = 0xFE00;
        static const uint16_t OAM_END = 0xFE9F;
        static const uint16_t IO_REGISTERS_START = 0xFF00;
        static const uint16_t IO_REGISTERS_END = 0xFF7F;
        static const uint16_t HRAM_START = 0xFF80;
        static const uint16_t HRAM_END = 0xFFFE;
        static const uint16_t IE_REGISTER = 0xFFFF;






        void writeByte(uint16_t address, uint8_t value);
        uint8_t readByte(uint16_t address) const;
        uint16_t readWord(uint16_t address) const;
        void writeWord(uint16_t address, uint16_t value);
        void reset();
        void loadROM(const std::string& filename);


};


#endif // MEMORY_H
