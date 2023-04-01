project = first

objs = main.o $(project).o

CC=gcc
CFLAGS := $(CFLAGS) -Wall

outputfile  = $(project)

.PHONY: all
all: first first.prn



$(outputfile): $(objs)
	gcc -o $(outputfile) $(objs) $(LDLIBS)


first.prn: first.S
	rm -f first.prn
	gcc -c -g -Wa,-a,-ad first.S >first.prn


.PHONY: clean
clean:
	rm -f first
	rm -f *.o
	rm -f first.prn
	
	
