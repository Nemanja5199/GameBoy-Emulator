
#include "memory.h"

#include <iostream>



Memory::Memory() {
    // Initialize memory with zeros
    memory.fill(0);
}


void Memory::writeByte(uint16_t address, uint8_t value){

    if(address < 0x10000) {

        memory[address] = value;
    } else {

        std::cerr << "Error: Attempt to write to invalid memory address: " << std::hex << address << std::endl;

    }

}




uint8_t Memory::readByte(uint16_t address) const {

    if(address < 0x10000) {

        return memory[address];
    } else{

        std::cerr << "Error: Attempt to read from invalid memory address: " << std::hex << address << std::endl;
        return 0xFF; // Return a default value in case of error

    }




    }


uint16_t Memory::readWord(uint16_t address) const {


    if(address < 0x10000){

        uint16_t value = (memory[address + 1] << 8) | memory[address];
        return value;
    } else {
        
        std::cerr << "Error: Attempt to read from invalid memory address: " << std::hex << address << std::endl;
        return 0xFFFF; // Return a default value in case of error

    }


}


 void Memory::writeWord(uint16_t address, uint16_t value){
    if(address < 0x10000) {

        memory[address] = value & 0xFF; // Lower byte
        memory[address + 1] = (value >> 8) & 0xFF; // Upper byte

    } else {

        std::cerr << "Error: Attempt to write to invalid memory address: " << std::hex << address << std::endl;
    }


 }

void Memory::reset() {
    // Reset memory to initial state
    memory.fill(0);
}


