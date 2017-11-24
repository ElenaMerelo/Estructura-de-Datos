# Práctica 3 (ED) TDA Lineales.
#### Enunciado de la práctica:
Crear el T.D.A Pila_max (Pila con máximo). Esta Pila contiene un conjunto de enteros y el valor máximo que existe en la Pila. Por ejemplo si queremos insertar los datos 2, 7, 6  y 9:
1. Se pone el dato 2. Como la pila estaba vacía 2 este valor será el máximo. 
2. Se inserta el dato 7. Ahora  para establecer cual es el máximo que hay que poner junto con 7, se compara 2 con  el máximo previo, que es 2. En este caso como 7 es mayor este valor es el que  se pone como máximo con el dato 7.  
3. Se inserta 6 y se vuelve a repetir el proceso de comparación. Por lo tanto se compara 6 con el máximo previo que es 7, como 7 es mayor se pone 7 como máximo del dato 6.
4. Finalmente se inserta el valor 9, y se compara 9 con 7, como 9 es mayor este  se coloca como máximo.

Se pedía implementar esta pila a partir de un vector dinámico y una cola, sin usar la STL y usando un mismo programa de prueba.

#### Funcionamiento
* Para elegir que versión compilar debes cambiar los siguientes campos:
	* En el makefile, `VERSION`, a `$(OBJ)/pila\_max\_vd.h` u `$(OBJ)/pila\_max\_cola.h`.
	* En uso\_pila\_max.cpp, `CUAL_COMPILA` a `2`, si queréis la implementación con `pila_max_vd.h`, a `1`, si queréis la `pila\_max\_cola.h`.
