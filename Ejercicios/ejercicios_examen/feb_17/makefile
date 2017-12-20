#Definición de macros para definir las carpetas de trabajo
BIN=./bin
SRC=./src
INC=./include

SRCS=main.cpp ejer2.cpp
OBJS=$(SRCS:.cpp=.o)
OPT=-Wall -g


all : $(BIN)/main

$(BIN)/main : $(OBJ)/main.o $(OBJ)/ejer2.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/ejer2.o

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/ejer2.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

$(OBJ)/ejer2.o : $(SRC)/ejer2.cpp $(INC)/ejer2.h
	g++ $(OPT) -c $(SRC)/ejer2.cpp -o $(OBJ)/ejer2.o -I$(INC)
