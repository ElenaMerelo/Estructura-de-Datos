INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
BIN=./bin
CXX = g++
CPPFLAGS = -Wall -g -c 

all : $(BIN)/uso_pila_max

# uso_pila_max : $(SRC)/uso_pila_max.cpp $(INCLUDE)/cola.h
# 	g++ -I$(INCLUDE) -o uso_pila_max $(SRC)/uso_pila_max.cpp 

$(BIN)/uso_pila_max : $(SRC)/uso_pila_max.cpp $(LIB)/libvd.a
	g++ -L$(LIB) -o $(BIN)/uso_pila_max -I$(INCLUDE) $(SRC)/uso_pila_max.cpp -lvd

$(LIB)/libvd.a : $(OBJ)/pila_max_cola.o 
	ar rvs $(LIB)/libvd.a $(OBJ)/pila_max_cola.o 

$(OBJ)/pila_max_cola.o : $(SRC)/pila_max_cola.cpp
	g++ -c -o $(OBJ)/pila_max_cola.o -I$(INCLUDE) $(SRC)/pila_max_cola.cpp

#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
