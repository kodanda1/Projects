project = blocky

objs = $(project).o main.o image.o readimage.o writeimage.o
filesdir = /user/cse320/files

CC=gcc
CFLAGS := $(CFLAGS) -I$(COA_ARM64)/include -Wall
LDLIBS := $(LDLIBS) -L$(COA_ARM64)/lib -lgrlcoa -lpng

outputfile  = $(project)

.PHONY: all
all: $(project)

$(outputfile): $(objs)
	gcc -o $(outputfile) $(objs) $(LDLIBS)

.PHONY: clean
clean:
	rm -f $(project)
	rm -f *.o

main.o:	image.h

leakcheck:	$(outputfile)
	valgrind --leak-check=yes ./blocky
	
