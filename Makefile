CC = gcc
CFLAGS =

DBIN=bin
DSRC=src

EXE=r4l

all: $(DBIN)/$(EXE)

SRC=$(DSRC)/*.c
OUT=$(DBIN)/$(EXE)

$(OUT): $(SRC)
	gcc $(SRC) $(CFLAGS) -o $(OUT)

run: all
	bin/r4l

