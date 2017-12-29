/**
 * @file quienesquien.h
 * @brief Fichero cabecera del QuienEsQuien.
 *
 * Almacena el árbol de preguntas para jugar al ¿Quién es quién?.
 */

#ifndef _QUIENESQUIEN_H_
#define _QUIENESQUIEN_H_

#define DEBUG_QUIENESQUIEN 0

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <set>
#include <sstream>

#include "pregunta.h"
#include "bintree.h"

using namespace std;

/**
 * @brief T.D.A. QuienEsQuien
 *
 * Conjunto de personajes con sus atributos.
 */
class QuienEsQuien{
private:
	/**
	  * @brief Almacena el nombre de los personajes. Su índice en
	  *        este vector corresponde con el índice de su
	  *        descripción en el tablero.
	  */
	vector<string> personajes;

	/**
	  * @brief Almacena los atributos del personaje.Su índice en este vector
	  *        corresponde con el índice correspondiente de cada
	  *        vector del tablero.
	  */
	vector<string> atributos;

	/**
	  * @brief Matriz que almacena para cada personaje su valor para
	  *        cada atributo.
	  */
	vector<vector<bool> > tablero;

	/**
	  * @brief Árbol de preguntas para adivinar personajes.
	  */
	bintree<Pregunta> arbol;

	/**
	  * @brief Nodo del árbol de preguntas correspondiente a la jugada
	  *        actual.
	  */
	bintree<Pregunta>::node jugada_actual;

	/**
	  * @brief Copia el quien es quien pasado como argumento en la clase
	  */
	void copiar_quien_es_quien(const QuienEsQuien &quienEsQuien);

public:
	/**
	  * @brief Constructor básico de la clase
	  */
	QuienEsQuien();

	/**
	  * @brief Constructor de copia.
	  * @param q QuienEsQuien a copiar.
	  */
	QuienEsQuien(const QuienEsQuien &q);

	/**
	* @brief Destructor
	*/
	~QuienEsQuien();

	/**
	  * @brief Vacía todos los datos del QuienEsQuien receptor.
	  */
	void limpiar();

	/**
		* @brief Sobrecarga del operador de asignación.
		* @param q objeto a copiar.
		* @return Referencia al objeto copiado.
		*/
	QuienEsQuien& operator = (const QuienEsQuien &q);

	/**
		* @brief Operador de extracción de flujo.
		* @param is Stream de entrada
		* @param quienEsQuien Quien es quien a leer.
		* @return Referencia al stream de entrada.
		*
		* Lee de @e is un quien es quien y lo almacena en @e
		* quienEsQuien. El formato aceptado para la lectura es un TSV
		* (tab-separated values) en el que las columnas tienen cabecera y
		* son las preguntas. La última columna corresponde al nombre del
		* personaje. Tras la cabecera se especifica en cada línea un
		* personaje, teniendo el valor 1 o 0 si tiene/no tiene el
		* atributo de la columna. En la última columna se da el
		* nombre del personaje.
		*/
	friend istream& operator >> (istream& is, QuienEsQuien &quienEsQuien);

	/**
		* @brief Operador de inserción de flujo.
		* @param os Stream de salida
		* @param quienEsQuien Quien es quien a escribir.
		* @return Referencia al stream de salida.
		*
		* Escribe en @e is un quien es quien.
		* El formato usado para la escritura es un TSV
		* (tab-separated values) en el que las columnas tienen cabecera y
		* son las preguntas. La última columna corresponde al nombre del
		* personaje. Tras la cabecera se especifica en cada línea un
		* personaje, teniendo el valor 1 o 0 si tiene/no tiene el
		* atributo de la columna. En la última columna se da el
		* nombre del personaje.
		*/
	friend ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien);

	/**
	  * @brief Escribe en la salida estándar las estructuras atributos, personajes y tablero.
	  */
	void mostrar_estructuras_leidas();

  /**
	 * @brief Cuenta el número de personajes que tiene el atributo @ e atributo.
	 * @param at Vector de 'bool' que contiene los atributos que deben cumplir los personajes a contar.
	 */
	int count_personajes(vector<bool> &at);

	/**
	 * @brief Crea el árbol de preguntas disponibles.
	 * @param n Nodo a partir del cuál se crea el árbol.
	 * @param index Índice que va desde 0 hasta número_de_atributos-1 para parar la recursividad.
	 * @param at Vector de 'bool' que contiene los atributos que deben cumplir los personajes a contar.
	 */
	void crear_arbol_recursivo(bintree<Pregunta>::node n, int index, vector<bool> at);

	/**
	  * @brief Este método construye el árbol de preguntas para todos los personajes del tablero.
	  */
	bintree<Pregunta> crear_arbol();

	/**
	  * @brief Sustituye el árbol actual por el árbol pasado por parámetro.
	  *
	  * @param arbol_nuevo Árbol de preguntas que sustituye al actual.
	  *
	  */
	void usar_arbol(bintree<Pregunta> arbol_nuevo);

	/**
	  * @brief Escribe el árbol generado en la salida estándar.
	  */
	void escribir_arbol_completo() const;

	/**
	   @brief Método que modifica el árbol de preguntas para que no haya
	          preguntas redundantes.
	   @post El árbol de preguntas se modifica.
	*/
	void eliminar_nodos_redundantes();

	/**
	 * @brief Inicializa el juego.
	 * @post  Si la partida anterior no había terminado se
	 *        pierde el progreso.
	 */
	void iniciar_juego();

	/**
	  * @brief Dado un estado del tablero devuelve los nombres de
	  *        los personajes que aún no han sido tumbados en el
	  *        tablero.
	  *
	  * @param jugada_actual Nodo del estado del tablero.
	  *
	  * @return Conjunto de personajes que no han sido tumbados en el tablero.
	  *
	  * @pre El arbol del QuienEsQuien receptor debe haber sido construido previamente.
	  * @pre El nodo indicado debe ser un nodo del arbol del QuienEsQuien receptor.
	  */
	set<string> informacion_jugada(bintree<Pregunta>::node jugada_actual);

	/**
	  * @brief Calcula la media de la profundidad de las hojas del
		*				 árbol. Este valor representa el número (promedio) de preguntas necesarias
		*				 para adivinar cada personaje. A menor profundidad promedio, mejor solución.
		* 			 Esta métrica es un indicador para evaluar la calidad de vuestra solución.
	  *
	  * @return Profundidad media del árbol de preguntas.
	  *
	  * @pre El árbol de preguntas debe haber sido construido previamente.
	  */
	float profundidad_promedio_hojas();

	/**
	  * @brief Rellena los datos del QuienEsQuien con un tablero calculado aleatoriamente.
	  *
	  * @param numero_de_personajes Número de personajes que tiene el tablero a crear.
	  */
	void tablero_aleatorio(int numero_de_personajes);
};

#endif
