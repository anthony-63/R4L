#include <stdio.h>

#include "rvm.h"


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

int
main ()
{
  rvm *vm = rvm_init ();
}
