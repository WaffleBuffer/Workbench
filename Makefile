SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic -I.
LIBS   =

LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

# Rajouter le nom des executables apres '=', separes par un espace.
# Si une ligne est pleine, rajouter '\' en fin de ligne et passer a la suivante.

# pour compiler avec bor-util.c
# project name (generate executable with this name)
TARGET   = Workbench


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(EXECSUTIL) : %: %.o bor-util.o
	$(CC) -o $@ $@.o bor-util.o $(LIBS)
	
.c.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean remove"

all :: $(TARGET)

clean ::
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

remove :: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"