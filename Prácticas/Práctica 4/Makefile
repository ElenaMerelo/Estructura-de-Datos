SRC=./src
INC=./include
OBJ=./obj
BIN=./bin
CXX = g++
CPPFLAGS = -Wall -g -c


all: $(BIN)/cronologia_test


$(BIN)/cronologia_test : $(SRC)/cronologia_test.cpp $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	g++ -g -o $(BIN)/cronologia_test $(SRC)/cronologia_test.cpp -I$(INC) $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o


$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp
	g++ $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp -I$(INC)

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
