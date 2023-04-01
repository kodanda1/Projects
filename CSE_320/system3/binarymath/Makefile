project = binarymath

objs = main.o $(project).o
testobjs = tests.o $(project).o
testdir = $(COA_ARM64)/lib/coa/tests/$(project)

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
	rm -f tester
	for file in $(CLEANEXTS); do rm -f *.$$file; done

tester: $(testobjs)
	gcc -o tester $(testobjs) -L$(COA_ARM64)/lib -lgrlcoa

.PHONY: test
test: tester
	./tester
	valgrind --leak-check=yes --error-exitcode=1 ./tester

.PHONY: tests
tests: test
 
tests.o: $(testdir)/tests.c $(project).h
	gcc -c $(CFLAGS) -I. -I$(COA_ARM64)/include $(testdir)/tests.c

# Indicate dependencies of .ccp files on .hpp files
main.c: $(project).h
$(project).c: $(project).h
