#include "include/emulator.h"



void Emulator::init(size_t memorysize, FILE *bin){
  memory.init(memorysize);
  memory.load_binary(bin);
  cpu.init(0, (int)memorysize/4);
}

void Emulator::free(){
  memory.free_memory();
}

void Emulator::exec(uint8_t opcode){
  cpu.execute_opcode(opcode);
}

void Emulator::dump_registers(){

}


uint8_t Emulator::read_uint8(uint32_t addr){
  uint8_t data = memory.read_uint8(addr);
  return data;
}

uint8_t Emulator::read_next_opcode(){
  uint8_t opcode = memory.read_uint8(cpu.eip);
  cpu.eip++;

  return opcode;
}

uint32_t Emulator::get_eip(){
  return cpu.eip;
}
