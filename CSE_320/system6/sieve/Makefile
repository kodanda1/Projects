project = sieve

objs = $(project).o

CC=gcc
CFLAGS := $(CFLAGS) -Wall
LDLIBS := $(LDLIBS) -L$(COA_ARM64)/lib -lgrlcoa

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

.PHONY: valgrind
valgrind:
	valgrind --leak-check=yes --error-exitcode=1 ./sieve 100

# Indicate dependencies of .ccp files on .hpp files

