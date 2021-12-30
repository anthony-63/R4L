#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "rvm.h"

int cb_mov (rvm * vm, IData idata);
int cb_arithemetic (rvm * vm, IData idata);
int cb_branching (rvm * vm, IData idata);
int cb_logical (rvm * vm, IData idata);
int cb_others (rvm * vm, IData idata);

#endif
