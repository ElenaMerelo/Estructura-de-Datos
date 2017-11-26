#include<iostream>
#include<cronologia.h>
#include<cassert>
#include<string>

using namespace std;

typedef pair<int, fecha_historica> par;


//Implementar.
void cronologia::addEvent(fecha_historica& f){
    data.insert(par(f.getAge(), f));
}

//Devuelve una fecha histórica en la cronología con año a.
fecha_historica& cronologia::search_fecha_historica(int a){
    if(data.count(a))
        return data.find(a)->second;
    fecha_historica f;
    return f;
}

//Operador de salida.
ostream& operator<< (ostream& os, const cronologia& c){
    cronologia::const_it i;
    for(i=c.begin(); i!=c.end(); ++i){
        cout << (*i).second  << endl;
    }
    return os;
}

//Operador de entrada.
istream& operator>> (istream& is, cronologia& c){
    fecha_historica b;
    while ( is >> b){
        c.addEvent(b);
    }
    return is;
}