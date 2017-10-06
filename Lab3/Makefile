cc=g++
cFlags=-std=c++11 -pthread
cFiles = Semaphore.cpp mutexExclusion.cpp
hFiles = Semaphore.h

%.o: %.cpp
	$(cc) -c -o $@ $(cFlags) $(DEBUGFLAGS)
	
ALL: $(cFiles) $(hFiles)
	$(cc) $(cFlags) *.cpp -o run $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL


CLEAN:
	rm *.o 
