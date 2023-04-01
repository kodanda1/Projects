project = perfect

objs = main.o $(project).o perfect.o
testobjs = tests.o $(project).o perfect.o
testdir = $(COA_ARM64)/lib/coa/tests/$(project)

CC=gcc
FLAGS := $(CFLAGS) -I$(COA_ARM64)/include -Wall
LDLIBS := $(LDLIBS) -L$(COA_ARM64)/lib -lgrlcoa
CLEANEXTS   = o

outputfile  = $(project)

# Default target
.PHONY: all
all: $(outputfile)

$(outputfile): $(objs)
								 	gcc -o $(outputfile) $(objs) $(LDLIBS)
