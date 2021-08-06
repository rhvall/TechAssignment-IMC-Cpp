CFLAGS= -O3 -Wall
#-Wall -pedantic -ansi
#CFLAGS=-O4
SOURCES=src/Shape.cpp src/Triangle.cpp src/Rectangle.cpp src/Circle.cpp src/AreaVisitor.cpp
MAIN=src/main.cpp
MAIN_TESTS=tests/mainTests.cpp

LDFLAGS = -Iheader

all: visitor visitorTests

visitor:
	g++ -std=c++17 $(CFLAGS) $(LDFLAGS) $(SOURCES) $(MAIN) -o visitor

visitorTests:
	g++ -std=c++17 $(CFLAGS) $(LDFLAGS) $(SOURCES) $(MAIN_TESTS) -o visitorTests

clean:
	rm -f visitor visitorTests
