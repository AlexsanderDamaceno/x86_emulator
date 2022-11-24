

#include <stdio.h>
#include <stdint.h>
#include "cpu.h"
#include "memory.h"

class Emulator
{
public:
  Cpu cpu;
  Memory memory;

  void init(size_t memorysize, FILE *bin);
  void free();
  void exec(uint8_t opcode);
  uint8_t read_uint8(uint32_t addr);
  void dump_registers();
  uint8_t read_next_opcode();
  uint32_t get_eip();

};
