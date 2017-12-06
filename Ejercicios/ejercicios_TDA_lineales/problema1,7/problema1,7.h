/**
* @brief Implementa el tipo de dato Cola utilizando como representación el tipo de dato abstracto
Lista.
* @author Elena Merelo Molina
*/
#include <list>
using namespace std;

template <class T>
class my_queue{
  private:
    list<T> data;
  public:
    //Constructor vacío
    my_queue(){}

    //Constructor de copia
    my_queue(const my_queue<T> &q){ data= q.data; }

    //Operador de asignación. La clase queue de la stl no lo tiene, pero la list sí, por eso la implementamos
    my_queue& operator=(const my_queue<T> &q){ data= q.data; }

    //Construye una cola con n veces element
    my_queue(int n, T element);

    //Comprueba si una cola está vacía
    bool empty(){ return data.empty(); }

    //Devuelve el tamaño de la cola
    int size(){ return data.size(); }

    //Método de acceso al siguiente elemento
    T& front(){ return data.front(); }

    //Método de acceso al último elemento
    T& back(){ return data.back(); }

    //Inserta un elemento en la cola
    void push(T element){ data.push_back(element); }

    //Borra un próximo elemento de la cola
    void pop(){ data.pop_front(); };

    //Muestra la cola
    void show_queue();

};

#include <problema1,7.cpp>
