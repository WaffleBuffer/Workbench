SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99 -pedantic -I.

LINKER   = gcc -o
# linking flags here
LFLAGS   = -Wall -I. -lm

#INCDIR   = src/Sorts
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
LIBS     := $(wildcard $(LIBSDIR)/*.c)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
#LIBSOBJ  := $(LIBS:$(LIBSDIR)/%.c=$(OBJDIR):%.o)
rm       = rm -f

# project name (generate executable with this name)
TARGET   = Workbench

$(OBJDIR)/$(TARGET).o: $(LIBS)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

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

