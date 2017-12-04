#include <iostream>
#include <cronologia.h>
#include <fstream>


using namespace std;

int main(int argc, char * argv[]){
  cout << "Programa de prueba" << endl;
  if( argc!= 3){
      cout << "Número de argumentos incorrecto. Ha de introducir tres ficheros, dos con cronologías y uno con una fecha histórica." << endl;
      return 1;
  }

  ifstream c1 (argv[1]);
  if (!c1){
    cout<<"Error al abrir el fichero "<< argv[1] << endl;
    return 1;
  }

  ifstream c2 (argv[2]);
  if (!c2){
    cout<<"Error al abrir el fichero "<< argv[2] << endl;
    return 1;
  }

  //Comprobamos el funcionamiento de los operadores de entrada
  // y salida, así como de los constructores vacíos, de copia y operator=
  cronologia a, b;
  c1 >> a;
  cout << "\nCronología a: \n" << a;

  c2 >> b;
  cout << "\nCronología b: \n" << b;

  /*cronologia c(a);
  cronologia d= b;

  cout << "\nCronología c: \n" << c;
  cout << "\nCronología d: \n" << d;*/

  //Prueba de los métodos addFechaHistorica y searchFechaHistorica
  /*
  fecha_historica fecha;
  f1 >> fecha;
  cout << "\nFecha a introducir a la cronología: \n" << fecha;
  a.addFechaHistorica(fecha);
  cout << "\nCronología a tras haber introducido fecha: \n" << a;
  cout <<"\nBúsqueda de la fecha histórica 1962: ";
  cout << a.searchFechaHistorica(1962);
  */

  //Prueba de la intersección de cronologías
  cronologia interseccion;
  a.interseccionCronologias(b,interseccion);
  cout << "\nLa cronología resultante de intersecar a y b es: \n" << interseccion;

  //Prueba de la unión de cronologías
  cronologia u;
  a.unionCronologias(b,u);
  cout << "\nLa cronología resultante de unir a y b es: \n" << u;

  //Prueba del filtro por palabras claves
  cronologia filtrada;
  a.filtroPorPalabrasClaves("The", filtrada);
  cout << "\nCronología a filtrada por la palabra clave The: \n" << filtrada;

  //Prueba del filtro por intervalo de tiempo
  cronologia acotada;
  int anio_inicio, anio_fin;
  cout << "\nIntroduzca años entre los cuales quiere filtrar la cronología primera introducida: ";
  cin >> anio_inicio;
  cin >> anio_fin;
  a.filtroPorIntervalo(anio_inicio, anio_fin, acotada);
  cout << "\nCronología a filtrada: \n" << acotada << endl;


//Estadisticas de la cronología
  a.estadisticas();
  b.estadisticas();
}
