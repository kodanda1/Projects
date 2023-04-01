project = asmadd

objs = main.o $(project).o

CC=gcc
CFLAGS := $(CFLAGS) -Wall

outputfile  = $(project)

.PHONY: all
all: $(project)

$(outputfile): $(objs)
	gcc -o $(outputfile) $(objs) $(LDLIBS)


.PHONY: clean
clean:
	rm -f $(project)
	rm -f *.o
	
	
