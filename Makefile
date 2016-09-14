SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic
LIBS   =

# pour compiler avec bor-util.c
EXECSUTIL = triosig

.c.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean distclean"

all :: $(EXECS) $(EXECSUTIL) $(EXECSTIMER)

$(EXECS) : %: %.o
	$(CC) -o $@ $@.o $(LIBS)

$(EXECSUTIL) : %: %.o bor-util.o
	$(CC) -o $@ $@.o bor-util.o $(LIBS)

clean ::
	\rm -f *.o core

distclean :: clean
	\rm -f *% $(EXECS) $(EXECSUTIL) $(EXECSTIMER)

