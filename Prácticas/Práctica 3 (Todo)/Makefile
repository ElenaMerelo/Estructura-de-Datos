INCLUDE=./include
LIB=./lib
OBJ=./obj
SRC=./src
BIN=./bin
CXX = g++
CPPFLAGS = -Wall -g -c
 
VERSION=$(OBJ)/pila_max_cola.o

$(BIN)/uso_pila_max : $(SRC)/uso_pila_max.cpp $(VERSION)
	g++ -L$(LIB) -o $(BIN)/uso_pila_max $(VERSION) -I$(INCLUDE) $(SRC)/uso_pila_max.cpp

$(OBJ)/pila_max_cola.o : $(SRC)/pila_max_cola.cpp
	g++ -c -o $(OBJ)/pila_max_cola.o -I$(INCLUDE) $(SRC)/pila_max_cola.cpp

$(OBJ)/pila_max_vd.o : $(SRC)/pila_max_vd.cpp
	g++ -c -o $(OBJ)/pila_max_vd.o -I$(INCLUDE) $(SRC)/pila_max_vd.cpp

#************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
