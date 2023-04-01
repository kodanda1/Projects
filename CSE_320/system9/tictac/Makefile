project = tictac

objs = $(project).o
testdir = $(COA_ARM64)/lib/coa/tests/$(project)

CC=gcc
CFLAGS := $(CFLAGS) -I$(COA_ARM64)/include -Wall
LDLIBS := $(LDLIBS) -L$(COA_ARM64)/lib -lgrlcoa

CLEANEXTS   = o

outputfile  = $(project)

# Default target
.PHONY: all
all: $(outputfile)

$(project): main.o $(objs)
tester: tester.o $(objs)

.PHONY: clean 
clean:
	rm -f $(outputfile)
	rm -f tester
	for file in $(CLEANEXTS); do rm -f *.$$file; done

.PHONY: test
test: tester
	@./tester
	@valgrind --leak-check=yes --error-exitcode=1 ./tester

.PHONY: tests
tests: test

tester.o: $(testdir)/tester.c
	gcc -c $(CFLAGS) $(testdir)/tester.c
