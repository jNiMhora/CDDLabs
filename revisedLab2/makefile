cc=g++
cFlags=-std=c++11 -pthread
cFiles= Semaphore.cpp rendezvous.cpp
hFiles=Semaphore.h

all:$(cFiles) $(hFiles)
	$(cc) $(cFlags) *.cpp -o rendezvous
CLEAN:
	rm *.o
