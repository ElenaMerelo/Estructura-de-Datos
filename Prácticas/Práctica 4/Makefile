SRC=./src
INC=./include
OBJ=./obj
BIN=./bin
CXX = g++
CPPFLAGS = -Wall -g -c


all: $(BIN)/fecha_historica_test


$(BIN)/fecha_historica_test : $(SRC)/fecha_historica_test.cpp $(OBJ)/fecha_historica.o
	g++ -g -o $(BIN)/fecha_historica_test $(SRC)/fecha_historica_test.cpp -I$(INC) $(OBJ)/fecha_historica.o


$(OBJ)/fecha_historica.o : $(SRC)/fecha_historica.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/fecha_historica.o $(SRC)/fecha_historica.cpp -I$(INC)

documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia:



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
