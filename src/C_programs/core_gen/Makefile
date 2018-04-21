#### Makefile should be palced in src directory ####
#/* Shashaankar Komirelly, shashaankar.komirelly@gmail.com */ 

### Constants
CC=gcc
IDIR =.
CFLAGS=-I.
CFLAGS=-I$(IDIR) -g
#DEPS =

### object code directories
ODIR=obj
#LDIR =../lib

# TODO: Include math libraries or others as needed
#LIBS=-lm

## Specifying dependencies, header files
_DEPS = core_gen_util.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


_OBJ = core_gen_util.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
#OBJ = core_gen_util.o


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#%.o: %.c $(DEPS)
#		$(CC) -c -o $@ $< $(CFLAGS)


### Final executable rule
# TODO: include $(LIBS) if any libraries included
core_gen_util: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
