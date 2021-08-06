CFLAGS= -O3 -Wall
#-Wall -pedantic -ansi
#CFLAGS=-O4
SOURCES=src/PSRInterface.cpp src/PSRStateMachine.cpp
MAIN=src/main.cpp
MAIN_TESTS=tests/mainTests.cpp

LDFLAGS = -Iheader

all: psr psrTests

psr:
	g++ -std=c++17 $(CFLAGS) $(LDFLAGS) $(SOURCES) $(MAIN) -o psr

psrTests:
	g++ -std=c++17 $(CFLAGS) $(LDFLAGS) $(SOURCES) $(MAIN_TESTS) -o psrTests

clean:
	rm -f psr psrTests
