#ifndef R4L_VM
#define R4L_VM

#include <stdint.h>

#define REG_MAX 0xFF
#define MEM_MAX 0xFFFFFFFF
#define PROGRAM_DATA_MAX UINT32_MAX

typedef int (*callback) ();

typedef enum
{
  MOV,
  ADD,
  SUB,
  MUL,
  SHR,
  SHL,
  AND,
  OR,
  XOR,
  NOT,
  JMP,
  JNE,
  JEQ,
  JLE,
  JGE,
  JLT,
  JGT,
  VIEW,
  RET,
  CALL,
} instruction;

typedef enum
{
  REG_REG,
  REG_MEM,
  MEM_REG,
  IMM_REG,
  REG_IMM,
  ADDR_REG,
  REG_ADDR,
  ADDR,
  REG,
  IMM
} instruction_type;

typedef struct
{
  instruction i;
  instruction_type itype;
  int p_reg;
  int s_reg;
  long data;
  callback cb;
} IData;

typedef struct
{
  int regs[REG_MAX];
  int ip;
  int mem[MEM_MAX];
  uint64_t *pd;
} rvm;

rvm *rvm_init ();
void rvm_run (rvm * vm, int start);

#endif
