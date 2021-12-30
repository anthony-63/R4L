#include "rvm.h"
#include "callbacks.h"

#include <stdlib.h>
#include <stdio.h>

#define ERR(msg) \
  printf("Error: %s\n", msg); \
  exit(-1);

rvm *
rvm_init ()
{
  rvm *vm = malloc (sizeof (rvm));
  vm->ip = 0;
  return vm;
}

void
getCallback (IData * idata)
{
  switch (idata->i)
    {
    case MOV:
      idata->cb = cb_mov;
      break;
    case ADD:
    case SUB:
    case MUL:
      idata->cb = cb_arithemetic;
      break;
    case SHR:
    case SHL:
    case AND:
    case OR:
    case XOR:
    case NOT:
      idata->cb = cb_logical;
      break;
    case JMP:
    case JNE:
    case JEQ:
    case JLE:
    case JGE:
    case JLT:
    case JGT:
      idata->cb = cb_branching;
      break;
    case VIEW:
    case CALL:
    case RET:
      idata->cb = cb_others;
    }
}

// instruction format
// 0xPPSSDDDDDDDDTTII
// P = primary/dst reg
// S = secondary/src reg
// D = data
// T = instruction type
// I = instruction

// NOTE: Anything that takes more than 2 registers will
// have a memory address stored in the primary register to point to all 
// the data needed for the instruction.

void
exec_idata (IData idata)
{
  int cbcode = idata.cb ();
  switch (cbcode)
    {
    case 0x00:
      return;
    default:
      ERR ("Unexpected error occured!");
    };
}

IData
rbc2idata (uint64_t rbc)
{
  int p_reg = (rbc & 0xFF00000000000000) >> 56;
  int s_reg = (rbc & 0x00FF000000000000) >> 48;
  long data = (rbc & 0x0000FFFFFFFF0000) >> 16;
  int itype = (rbc & 0x000000000000FF00) >> 8;
  int instr = (rbc & 0x00000000000000FF) >> 0;
  IData inst = {
    .i = instr,
    .itype = itype,
    .p_reg = p_reg,
    .s_reg = s_reg,
    .data = data,
  };
  getCallback (&inst);
  return inst;
}

int
rvm_getSize (uint64_t * pd)
{
  int t = 0;
  while (*pd != 0xF0F0F0F0F0F0F0F)
    {
      pd++;
      t++;
    }
  return t;
}

void
rvm_run (rvm * vm, int start)
{
  int ps = rvm_getSize (vm->pd);
  for (int i = start; i < ps - 1; i++)
    {
      exec_idata (rbc2idata (vm->pd[i]));
    }
}
