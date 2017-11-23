/**
  * @file vectordinamico.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  *
  */
#ifndef _vectordinamico_h
#define _vectordinamico_h


/**
 *  @brief T.D.A. Vector_Dinamico
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c Vector_Dinamico sobre el
 * tipo @c float es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petición del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 */

template <class T>
class Vector_Dinamico{
  private:
    T * data;    // Apunta a los elementos del vector
    int num_elements;   // Indica el número de elementos en @c datos
    void copy(const Vector_Dinamico<T> &other);
    void freeMemory();

  public:
    /**
     * @brief Constructor por defecto
     * @param n indica el número de componentes iniciales reservados
     *          para el vector
     */
    Vector_Dinamico(int n=0);

    /**
     * @brief Constructor de copia
     * @param other Vector dinámico del que se hará la copia.
     */
    Vector_Dinamico(const Vector_Dinamico<T> &other);

    /**
     * @brief Operador de asignación
     * @param other Vector dinámico del que se hará la copia.
     */
    Vector_Dinamico& operator=(const Vector_Dinamico<T> &other);

    /**
     * @brief Destructor
     */
    ~Vector_Dinamico();

    /**
     * @brief Número de componentes del vector
     * @return Devuelve el número de componentes que puede almacenar en este
     * instante el vector
     */
    int size() const;

    /**
     * @brief Acceso a un elemento
     * @param i Posición del vector donde está el componente. 0<=i<size()
     * @return Referencia al elemento. Por tanto, se puede usar para almacenar
     *     un valor en esa posición.
     */
    T& operator[] (int i);

    /**
     * @brief Acceso a un elemento de un vector constante
     * @param i Posición del vector donde está el componente. 0<=i<size()
     * @return Referencia al elemento. Se supone que el vector no se puede
     *  modificar y por tanto es acceso de solo lectura.
     */
    const T& operator[] (int i) const;

    /**
     * @brief Redimensión del vector
     * @param n El nuevo tamaño del vector. n>=0
     * @post Los valores almacenados antes de la redimensión no se pierden
     *  (excepto los que se salen del nuevo rango de índices)
     */
    void resize(int n);

};

#include <vectordinamico.cpp>
#endif
