project = life

objs = main.o get_bit.o set_bit.o $(project).o
testobjs = tests.o get_bit.o set_bit.o $(project).o

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

tester: $(testobjs)
	gcc -o tester $(testobjs) -L$(COA_ARM64)/lib -lgrlcoa

.PHONY: test
test: tester
	./tester
	valgrind ./tester

.PHONY: tests
tests: test
 
tests.o: tests.c
	gcc -c $(CFLAGS) -I. -I$(COA_ARM64)/include tests.c

# Indicate dependencies of .ccp files on .hpp files

