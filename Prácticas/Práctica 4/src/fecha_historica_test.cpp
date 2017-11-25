#include<iostream>
#include<fecha_historica.h>

using namespace std;

int main(){
    cout << "Programa de prueba para fecha_historica.h" << endl;

    fecha_historica f;

    cout << "Introduzca una fecha histórica" << endl;
    cin >> f;

    cout << f.getAge() << endl;
    cout << f.getNumEvents() << endl;

    cout << f << endl;

    f.setAge(1899);
    fecha_historica f_ = f;

    cout << f_ << endl;
}

