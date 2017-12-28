/*Enunciado: Construye una clase agenda que de soporte al manejo de información del
tipo persona: <nombre, num_telefono, direccion>. Los nombre son todos distintos y se
tiene que poder buscar de forma eficiente tanto por nombre como por número de
teléfono o dirección. Además de en tiempo también debe ser eficiente en espacio.
Implementa las funciones: persona buscar_nombre(string nom), persona
buscar_telefono(string num), void insertar(persona p).
Author: Elena Merelo Molina
*/
#include <ejer1.h>

int main(){
  agenda mi_agenda;
  typedef pair<string, string> info;

  mi_agenda.insert(pair<string, info>("Elena Merelo", make_pair("958 09 05 08", "nobody knows")));
  mi_agenda.insert(pair<string, info>("Ceci", make_pair("902 20 21 22", "carrera de la virgen")));
  mi_agenda.insert(pair<string, info>("Antonio", make_pair("955 55 55 55", "su casa")));

  string name= "Antonio";
  info info_name= mi_agenda.find_name(name);
  cout << "\nEl número de teléfono de " << name << " es: " << info_name.first << " y su dirección: " << info_name.second;

  string telefono= "958 09 05 08";
  string persona= mi_agenda.find_telephone(telefono);
  cout << "\nLa persona con teléfono " << telefono << " es: " << persona;




}
