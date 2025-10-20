NODEBUGFLAGS = -std=c++14 -fopenmp -O2 -Wall -Werror
DEBUGFLAGS = -g -std=c++14 -fopenmp -Wall -Werror
CFLAGS = $(NODEBUGFLAGS)
OBJS = sorter.o Sorts.o ParaSort1.o ParaSort2.o ParaSort3.o SeqSort.o
CC = g++
.C.o: 
	$(CC) -c $(CFLAGS) -o $@ $<

all: 
	make sorter 

sorter: $(OBJS)
	$(CC) $(OBJS) -fopenmp -o sorter

sorter.o: Sorts.h SeqSort.h ParaSort1.h ParaSort2.h ParaSort3.h

Sorts.o: Sorts.h Sorts.C

ParaSort1.o: Sorts.h ParaSort1.h ParaSort1.C helpers.h

ParaSort2.o: Sorts.h ParaSort2.h ParaSort2.C helpers.h

ParaSort3.o: Sorts.h ParaSort3.h ParaSort3.C helpers.h

SeqSort.o: Sorts.h SeqSort.h SeqSort.C helpers.h

clean:
	rm sorter *.o

