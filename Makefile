all: lab03
CPP=g++
CFLAGS=-std=c++11

lab03: dynamicarray.o lab03a.o linkedlist.o
	$(CPP) -o lab03 dynamicarray.o lab03a.o linkedlist.o

lab03a.o: lab03a.cpp stack.h linkedlist.h dynamicarray.h
	$(CPP) -c lab03a.cpp $(CFLAGS)

dynamicarray.o: dynamicarray.cpp dynamicarray.h stack.h
	$(CPP) -c dynamicarray.cpp $(CFLAGS)

linkedlist.o: linkedlist.cpp linkedlist.h stack.h
	$(CPP) -c linkedlist.cpp $(CFLAGS)

clean:
	rm -f *.o *~ lab03
