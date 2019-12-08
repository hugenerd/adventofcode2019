CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
LDFLAGS =
SOURCES = main.cpp
HEADERS =
OBJECTS = $(SOURCES:.cpp=.o)

all: intcode

intcode: $(HEADERS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
