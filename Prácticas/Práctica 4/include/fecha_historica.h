#include<iostream>
#include<fecha_historica.h>
#include<cassert>
#include<string>

using namespace std;

//Añade un evento a set<string>.
void fecha_historica::addEvent(string event){
        events.second.insert(event);
}

//Operador de salida.
ostream& operator<<( ostream& os, const fecha_historica& f){
    os << f.getYear();
    fecha_historica::const_iterator i;
    for(i= f.events.second.begin(); i!= f.events.second.end(); ++i)
        os << '#' << (*i);
    return os;
}

//Operador de entrada.
istream& operator>>( istream& is, fecha_historica& f){
    string aux;
    getline(is, aux, '#');
    f.events.first = atoi(aux.c_str());

    while(!is.eof()){
        getline(is, aux, '#');
        f.addEvent(aux);
    }

    return is;
}

