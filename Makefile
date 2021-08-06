CFLAGS= -O3 -Wall
#-Wall -pedantic -ansi
#CFLAGS=-O4
MAIN=src/main.cpp
MAIN_TESTS=tests/mainTests.cpp
VISITOR_DIR=Visitor
PSR_DIR=Paper-Scissors-Rock

all: psr psrTests visitorMain visitorTests

psr:
	cd $(PSR_DIR) && make psr

psrTests:
	cd $(PSR_DIR) && make psrTests

visitorTests:
	cd $(VISITOR_DIR) && make visitorTests

visitorMain:
	cd $(VISITOR_DIR) && make visitor

clean:
	rm -f $(VISITOR_DIR)/visitor $(VISITOR_DIR)/visitorTests $(PSR_DIR)/psr $(PSR_DIR)/psrTests
