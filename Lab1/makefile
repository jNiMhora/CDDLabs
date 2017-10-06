cc = g++
cFlags = -std=c++11 -pthread
cFiles = signal.cpp Semaphore.cpp
hFiles = Semaphore.h

all: $(cFiles) $(hFiles) 
	$(cc) $(cFlags) *.cpp -o sigexe
