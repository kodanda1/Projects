project = perfect

objs = main.o $(project).o
testobjs = tests.o $(project).o

CC=gcc
CFLAGS := $(CFLAGS) -Wall -I$(COA_ARM64)/include
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
	rm -f tests
	for file in $(CLEANEXTS); do rm -f *.$$file; done

tests: $(testobjs)
	gcc -o tests $(testobjs) $(LDLIBS)

.PHONY: test
test: tests
	./tests
	@# valgrind --leak-check=yes --error-exitcode=1 ./tests

# Indicate dependencies of .ccp files on .h files

