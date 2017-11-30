#include<iostream>
#include<fstream>
#include<fecha_historica.h>

using namespace std;

int main(int argc, char * argv[]){
    cout << "Programa de prueba" << endl;
    if( argc!= 3){
        cout << "Número de argumentos incorrecto. Ha de introducir dos ficheros." << endl;
        return 1;
    }

    ifstream f1 (argv[1]);
    if (!f1){
      cout<<"Error al abrir el fichero "<< argv[1] << endl;
      return 1;
    }

    ifstream f2 (argv[2]);
    if (!f2){
      cout<<"Error al abrir el fichero "<< argv[2] << endl;
      return 1;
    }

    fecha_historica a;
    f1 >> a;
    cout << "Fecha histórica a: "<< a << endl;

    fecha_historica b;
    f2 >> b;
    cout << "Fecha histórica b: "<< b << endl;

    //Probamos el funcionamiento del constructor de copia
    fecha_historica c(a);
    cout << "Fecha histórica c: "<< c << endl;

    //Probamos el funcinamiento del operador de asignación
    fecha_historica d= b;
    cout << "Fecha histórica d: "<< d << endl;

    //Probamos los métodos fecha_historica::setYear() y fecha_historica::getYear()
    cout << "Año de la fecha a: " << a.getYear() << endl;
    a.setYear(2017);
    cout << "Año de la fecha a cambiado: " << a.getYear() << endl;

    //Probamos fecha_historica::getEvents() y fecha_historica::getNumEvents()
    cout << "Número de eventos de a: " << a.getNumEvents() << endl;

    cout << "Añado evento #ID3 decision tree algorithm developed by Ross Quinlan a la fecha_historica a: " << endl;
    a.addEvent("#ID3 decision tree algorithm developed by Ross Quinlan");
    cout << a;

    //Probamos fecha_historica::estaRepetido(string evento)
    if(a.estaRepetido("AVL trees"))
      cout << "\nAVL trees está en la fecha histórica a";
    else
      cout << "AVL trees no está en la fecha histórica a";

    //Prueba de fecha_historica::getElement(int n) y de la unión de eventos
    cout << "\nEl evento 3 de la fecha a es: " << a.getElement(3);
    fecha_historica u;
    a.unionEventos(b, u);
    cout << "\nLa fecha histórica resultante de la unión de la fecha a: " << a << "\ny b: " << b << "\nes: \n" << u;

    //Prueba de la intersección de eventos
    fecha_historica inter;
    a.interseccionEventos(u, inter);
    cout << "\nLa fecha histórica resultante de la intersección de la fecha a y su unión con b es: \n" << inter;
}
