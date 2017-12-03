#include<iostream>
#include<cronologia.h>
#include<cassert>
#include<string>

using namespace std;

typedef pair<int, fecha_historica> par;


//Añade una fecha a la cronología
void cronologia::addFechaHistorica(fecha_historica& f){
  cronologia::it i = data.find(f.getYear());

  if( i != data.end() ){

    fecha_historica aux;
    aux.setYear(f.getYear());
    f.unionEventos((*i).second,aux);

    data.erase(i);
    data.insert(par(f.getYear(),aux));
  }
  else
     data.insert(par(f.getYear(), f));

}

//Devuelve una fecha histórica en la cronología con año a
fecha_historica& cronologia::searchFechaHistorica(int a){
  if(data.count(a))
    return data.find(a)->second;
  fecha_historica f;
  return f;
}

//Une dos cronologías
void cronologia::unionCronologias(const cronologia &f, cronologia &u){
  u=f;
  cronologia::it i;
  for(i=data.begin(); i!=data.end(); ++i)
    u.addFechaHistorica((*i).second);

}

//Interseca dos cronologías
void cronologia::interseccionCronologias(cronologia& c, cronologia &u){
  cronologia::it i;
  for(i=data.begin(); i!=data.end(); ++i){
    if( c.data.count((*i).second.getYear()) > 0 ){
      u.addFechaHistorica((*i).second);
      u.addFechaHistorica(c.data[(*i).second.getYear()]);
    }
  }
}

//Operador de salida
ostream& operator<< (ostream& os, const cronologia& c){
  cronologia::const_it i;
  for(i=c.begin(); i!=c.end(); ++i){
    cout << (*i).second  << endl;
  }
  return os;
}

//Operador de entrada
istream& operator>> (istream& is, cronologia& c){
  fecha_historica b;
  while ( is >> b){
    c.addFechaHistorica(b);
  }
  return is;
}
