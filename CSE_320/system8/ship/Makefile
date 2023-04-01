project = ship

objs = $(project).o main.o

CC=gcc
CFLAGS := $(CFLAGS) -Wall
LDLIBS := $(LDLIBS) -L$(COA_ARM64)/lib -lgrlcoa -lpng -lm

CLEANEXTS   = o

outputfile  = $(project)

# Default target
.PHONY: all
all: $(outputfile)

$(outputfile): $(objs)
	gcc -o $(outputfile) $(objs) $(LDLIBS)

.PHONY: clean 
clean:
	rm -f $(outputfile)
	for file in $(CLEANEXTS); do rm -f *.$$file; done


# Indicate dependencies of .ccp files on .hpp files

