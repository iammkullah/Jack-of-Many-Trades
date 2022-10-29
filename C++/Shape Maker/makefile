# The following just specifies some variables for "flexibility".

# Specify the C++ compiler
CXX     = g++

# Specify options to pass to the compiler. Here it sets the optimisation
# level, outputs debugging info for gdb, and C++ version to use.
CXXFLAGS = -O0 -g3 -std=c++14

All: all
all: main GeometryTesterMain

main: main.cpp Geometry.o
	$(CXX) $(CXXFLAGS) main.cpp Geometry.o -o main

GeometryTesterMain: GeometryTesterMain.cpp GeometryTester.o Geometry.o
	$(CXX) $(CXXFLAGS) GeometryTesterMain.cpp GeometryTester.o Geometry.o -o GeometryTesterMain

# The -c command produces the object file
Geometry.o: Geometry.cpp Geometry.h
	$(CXX) $(CXXFLAGS) -c Geometry.cpp -o Geometry.o

GeometryTester.o: GeometryTester.cpp GeometryTester.h
	$(CXX) $(CXXFLAGS) -c GeometryTester.cpp -o GeometryTester.o

# Some cleanup functions, invoked by typing "make clean" or "make deepclean"
deepclean:
	rm -f *~ *.o GeometryTesterMain main main.exe *.stackdump

clean:
	rm -f *~ *.o *.stackdump

