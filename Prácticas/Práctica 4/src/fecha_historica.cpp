#include<iostream>
#include<fecha_historica.h>
#include<cassert>
#include<string>

using namespace std;

void fecha_historica::addEvent(string event){ 
    if( data.second.count(event) == 0 )
        data.second.insert(event);
}

ostream& operator<<( ostream& os, const fecha_historica& f){
    os << f.getAge();
    fecha_historica::const_iterator i;
    for(i = f.data.second.begin(); i!=f.data.second.end(); ++i)
        os << '#' << (*i);
    return os;
}

istream& operator>>( istream& is, fecha_historica& f){
    string aux;
    getline(is, aux, '#');
    f.data.first = atoi(aux.c_str());

    while(!is.eof()){
        getline(is, aux, '#');
        f.addEvent(aux);
    }
    
    return is;
}