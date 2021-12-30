#include "callbacks.h"
#include <stdarg.h>

// MOV
int
mov_rr (int r1, int r2)
{

}

int
movir (int imm, int r)
{

}

// MOV END

// ARITHEMETIC
int
addir (int imm, int r)
{

}

int
subir (int imm, int r)
{

}

int
mulir (int imm, int r)
{

}


int
addrr (int r1, int r2)
{

}

int
subrr (int r1, int r2)
{

}

int
mulrr (int r1, int r2)
{

}

// ARITHEMETIC END

// LOGICAL
int
shrr (int r)
{

}

int
shlr (int r)
{

}

int
andir (int imm, int r)
{

}

int
orir (int imm, int r)
{

}

int
xorir (int imm, int r)
{

}

int
andrr (int imm, int r)
{
}

int
orrr (int imm, int r)
{
}

int
xorrr (int imm, int r)
{
}

int
notr (int r)
{

}

// LOGICAL END

//BRANCHING
int
jmpi (int imm)
{

}

int
jnei (int imm)
{

}

int
jeqi (int imm)
{

}

int
jlei (int imm)
{

}

int
jgei (int imm)
{

}

int
jlti (int imm)
{

}

int
jgti (int imm)
{

}

int
jmpr (int r)
{

}

int
jner (int r)
{

}

int
jeqr (int r)
{

}

int
jler (int r)
{

}

int
jger (int r)
{

}

int
jltr (int r)
{

}

int
jgtr (int r)
{

}

// BRANCHING END

// OTHERS
int
viewr (int r)
{

}

int
viewa (int a)
{

}

int
callr (int r)
{

}


int
cb_mov (rvm * vm, IData idata)
{
  switch (idata.i)
    {

    }
}

int
cb_arithemetic (rvm * vm, IData idata)
{
  switch (idata.i)
    {

    }
}

int
cb_branching (rvm * vm, IData idata)
{
  switch (idata.i)
    {

    }
}

int
cb_logical (rvm * vm, IData idata)
{
  switch (idata.i)
    {

    }
}

int
cb_others (rvm * vm, IData idata)
{
  switch (idata.i)
    {

    }
}
