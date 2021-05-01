CXX = $(shell wx-config --cxx)
WX_CXXFLAGS = $(shell wx-config --cxxflags) 
WX_LIBS = $(shell wx-config --libs)

PROGRAM = app
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.SUFFIXES:	.o .cpp

.cpp.o:
	$(CXX) -g -c $(WX_CXXFLAGS) -o $@ $<

all:	$(PROGRAM)

$(PROGRAM):		$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(WX_LIBS)

run: all
	./$(PROGRAM)

clean:
	rm -f *.o $(PROGRAM)

tags:
	make clean && bear make
