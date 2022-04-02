CXX = g++
CXXFLAGS = -c -g -Wall -Wextra -msse4.2 -mavx2 -O2

all: imageMerge

imageMerge: main.o imageMerge.o
	$(CXX) main.o imageMerge.o -lSDL2main -lSDL2 -o imageMerge.out

main.o: main.cpp imageMerge.h
	$(CXX) $(CXXFLAGS) main.cpp

imageMerge.o: imageMerge.cpp imageMerge.h
	$(CXX) $(CXXFLAGS) imageMerge.cpp

.PHONY: clean
clean:
	rm -rf *.o imageMerge
