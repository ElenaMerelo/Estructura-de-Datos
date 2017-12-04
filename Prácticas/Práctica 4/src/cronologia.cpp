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
  for(i=data.begin(); i!=data.end(); ++i){
    u.addFechaHistorica((*i).second);
  }
}

//Interseca dos cronologías
void cronologia::interseccionCronologias(cronologia &c, cronologia &u){
  cronologia::it i;
  for(i=data.begin(); i!=data.end(); ++i){
    if( c.data.count((*i).second.getYear()) > 0 ){
      u.addFechaHistorica((*i).second);
      u.addFechaHistorica(c.data[(*i).second.getYear()]);
    }
  }
}

//Crea una cronología con los eventos que contienen el string pasado como argumento
void cronologia::filtroPorPalabrasClaves(string s, cronologia &c){
  cronologia::it i;
  for(i= data.begin(); i!= data.end(); i++){
    fecha_historica matches;
    if((*i).second.findWords(s, matches))
      c.addFechaHistorica(matches);
  }
}

<<<<<<< HEAD
//Crea una cronología con los eventos que pasaron en dicho intervalo de tiempo
void cronologia::filtroPorIntervalo(int anio_inicio, int anio_fin, cronologia &c){
  cronologia::it i= data.lower_bound(anio_inicio);
  while(i != data.upper_bound(anio_fin)){
    c.addFechaHistorica(i->second);
    i++;
  }
=======
int cronologia::numeroAcontecimientos(){
  cronologia::it i;
  int sum=0;
  for(i=data.begin(); i!=data.end(); ++i)
    sum+=(*i).second.getNumEvents();
  return sum;
>>>>>>> 6b5706d487e7fbd4859a22502a4bbfe050d1d4af
}

void cronologia::estadisticas(){
  cout << "Número total de fechas históricas: " << data.size() << endl;
  cout << "Número total de acontecimientos: " << numeroAcontecimientos() << endl;
}

//Operador de salida
ostream& operator<< (ostream& os, const cronologia& c){
  cronologia::const_it i;
  for(i=c.begin(); i!=c.end(); ++i)
    cout << (*i).second  << endl;

  return os;
}

//Operador de entrada
istream& operator>> (istream& is, cronologia& c){
  //c.data.clear();
  fecha_historica b;
  while ( is >> b){
    c.addFechaHistorica(b);
  }
  return is;
}
