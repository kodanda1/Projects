project = bin2dec

objs = main.o bin2dec.o
testobjs = tests.o bin2dec.o
filesdir = /user/cse320/files
testdir = $(ARM64)/lib/coa/tests/$(project)

CC=gcc
CFLAGS := $(CFLAGS) -Wall

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
	rm -f test320
	for file in $(CLEANEXTS); do rm -f *.$$file; done

tester: $(testobjs)
	gcc -o tester $(testobjs) -L$(ARM64)/lib -lgrlcoa

.PHONY: test
test: tester
	./tester

.PHONY: tests
tests: test
 
tests.o: $(testdir)/tests.c bin2dec.h
	gcc -c $(CFLAGS) -I. -I$(ARM64)/include $(testdir)/tests.c

# Indicate dependencies of .ccp files on .hpp files
main.c: bin2dec.h
bin2dec.c: bin2dec.h
