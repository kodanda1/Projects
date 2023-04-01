
project= decoder

objs = main.o $(project).o
testobjs = tests.o $(project).o
testdir = $(COA_ARM64)/lib/coa/tests/$(project)
	
CC=gcc
CFLAGS := $(CFLAGS) -Wall
			
CLEANEXTS = o
outputfile  = $(project)

decoder: main.o decoder.o
		gcc -o decoder main.o decoder.o

main.o: main.c
			gcc -c -Wall main.c

decoder.o: decoder.c decoder.h
				gcc -c -Wall decoder.c
