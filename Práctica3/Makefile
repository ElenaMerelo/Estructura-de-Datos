INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
BIN=./bin
CXX = g++
CPPFLAGS = -Wall -g -c

all : $(BIN)/uso_pila_max

$(BIN)/uso_pila_max : $(SRC)/uso_pila_max.cpp
	g++ -L$(LIB) -o $(BIN)/uso_pila_max -I$(INCLUDE) $(SRC)/uso_pila_max.cpp

#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
