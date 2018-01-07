#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stack>

void QuienEsQuien::copiar_quien_es_quien(const QuienEsQuien &quienEsQuien){
	this->personajes= quienEsQuien.personajes;
	this->atributos= quienEsQuien.atributos;
	this->tablero= quienEsQuien.tablero;
	this->arbol= quienEsQuien.arbol;
	this->jugada_actual= quienEsQuien.jugada_actual;
}

QuienEsQuien::QuienEsQuien(){}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &q){
	copiar_quien_es_quien(q);
}

QuienEsQuien& QuienEsQuien::operator=(const QuienEsQuien &q){
	if(&q != this){
		limpiar();
		copiar_quien_es_quien(q);
	}
	return *this;
}

QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	personajes.clear();
	atributos.clear();
	tablero.clear();
	arbol.clear();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

int QuienEsQuien::buscar_indice_personaje(string personaje){
	for(int i=0; i < personajes.size(); i++){
			if( personajes[i].compare(personaje) == 0 )
				return i;
		}
}

void QuienEsQuien::mostrar_personajes_levantados(const set<string> & personajes_levantados){
	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}

	cout << endl;
	
	int indice_personaje;
	string nombre_personaje;
	
	for(set<string>::iterator personaje = personajes_levantados.begin();
		personaje!= personajes_levantados.end();
		personaje++){

		indice_personaje=buscar_indice_personaje(*personaje);
		nombre_personaje = this->personajes[indice_personaje];
		
		for(int i = 0; i < tablero[indice_personaje].size(); i++){
			cout << tablero[indice_personaje][i] << "\t";
		}
		
		cout << nombre_personaje << endl;
	}
}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  *
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();

  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");

    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}

    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;

	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));

	    		assert(valor == "0" || valor == "1");

	    		bool valor_atributo = valor == "1";

	    		atributos_personaje.push_back(valor_atributo);

	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}

			string nombre_personaje = linea;

	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}

	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un número a un vector de bool que corresponde
  *        con su representación en binario con un numero de digitos
  *        fijo.
  *
  * @param n Número a convertir en binario.
  * @param digitos Número de dígitos de la representación binaria.
  *
  * @return Vector de booleanos con la representación en binario de @e n
  *      con el número de elementos especificado por @e digitos.
  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

int QuienEsQuien::count_personajes(vector<bool> &at){
	int n=0;
	int x=0;
	for(vector<vector<bool> >::iterator i=tablero.begin();
	i!=tablero.end();
	++i){
		for(int j=0; j<at.size(); j++){
			if( (*i)[j] == at[j] )
				x++;
		}
		if ( x==at.size() ){
			n++;
		}
		x=0;
	}

	return n;
}

string QuienEsQuien::buscar_personaje(const vector<bool> &atrib){
	int indice=0;
	int x=0;
	bool found=false;
	for( int i=0; i < tablero.size() && !found; i++ ){
		x=0;
		for( int j=0; j < atrib.size(); j++ ){
			if(tablero[i][j]==atrib[j]) 
				x++;
		}
		if( x == atrib.size()){
			found=true;
			indice=i;	
		}
	}
	return personajes[indice];
}

void QuienEsQuien::crear_arbol_recursivo(bintree<Pregunta>::node n, int index, vector<bool> at){
	if(!n.null() && index <= atributos.size()){

		at.push_back(1);
		int n_pers=count_personajes(at);
		
		if(n_pers){
			if( n_pers == 1){
				if( (*n).obtener_num_personajes() > 1 )
					arbol.insert_left(n, Pregunta(buscar_personaje(at), n_pers));
			}
			else
				arbol.insert_left(n, Pregunta(atributos[index], n_pers));
		}
		at.pop_back();
		at.push_back(0);
		n_pers=count_personajes(at);
		
		if(n_pers){
			if( n_pers == 1 ){
				if( (*n).obtener_num_personajes() > 1 )
					arbol.insert_right(n, Pregunta(buscar_personaje(at), n_pers));
			}
			else
				arbol.insert_right(n, Pregunta(atributos[index], n_pers));
		}
		at.pop_back();

		at.push_back(1);
		crear_arbol_recursivo(n.left(), 1+index, at);
		at.pop_back(); 
		at.push_back(0);
		crear_arbol_recursivo(n.right(), 1+index, at);
	}
}


bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	vector<bool> aux;
	if( arbol.empty() ){
		arbol=bintree<Pregunta>(Pregunta(atributos[0], count_personajes(aux)));
	}

	crear_arbol_recursivo(arbol.root(), 1, aux);
	
	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	if(!arbol.empty()){
    	jugada_actual=arbol.root();
    	string respuesta;
		while( (*jugada_actual).obtener_num_personajes() != 1 ){
			cout << (*jugada_actual) << endl;
			
			cin >> respuesta;
			
			if( respuesta.compare("y") == 0 && !jugada_actual.left().null() )
				jugada_actual=jugada_actual.left();
			else if( respuesta.compare("n") == 0 && !jugada_actual.right().null() )
				jugada_actual=jugada_actual.right();
			else if( respuesta.compare("p") == 0 )
				mostrar_personajes_levantados(informacion_jugada(jugada_actual));
			else if( respuesta.compare("q") == 0 )
				mostrar_preguntas_formuladas(preguntas_formuladas(jugada_actual));
			else 
				cout << "Respuesta incorrecta. Escriba \"y\", \"n\" o \"p\"." << endl;
		}

    cout << "¡Ya lo sé! Tu personaje es " << (*jugada_actual).obtener_personaje() << endl;
    cout << "¿Desea jugar otra partida?" << endl;
	cin >> respuesta;
    
	if( respuesta.compare("y") == 0 )
    	iniciar_juego();
    else if( respuesta.compare("n") == 0 ){
    	cout << "¡Hasta la próxima!" << endl;
    	jugada_actual=arbol.root();
    }else{
    	cout << "Respuesta incorrecta. Se termina el juego." << endl;
    	jugada_actual=arbol.root();
	}
  } else{
	  cout << "Error: el árbol de preguntas no se ha creado correctamente." << endl;
  }
}

void QuienEsQuien::personajes_restantes(set<string> & personajes_levantados,bintree<Pregunta>::node n){
	if((*n).obtener_num_personajes()==1)		
		personajes_levantados.insert((*n).obtener_personaje());
	else{
		if(!n.left().null())
			personajes_restantes(personajes_levantados, n.left());
		if(!n.right().null())		
			personajes_restantes(personajes_levantados, n.right());
	}
}

void QuienEsQuien::preguntas_formuladas_recursivo(stack<pair<string, bool> > & p, bintree<Pregunta>::node n){
	if( !n.null() && ( n != arbol.root() ) ){
		if( n.parent().left() == n ){
			pair<string, bool> aux((*n.parent()).obtener_pregunta(),1);
			p.push(aux);
		}
		if( n.parent().right() == n ){
			pair<string, bool> aux((*n.parent()).obtener_pregunta(),0);
			p.push(aux);
		}
		preguntas_formuladas_recursivo(p, n.parent());
		
	}
}

stack<pair<string, bool> > QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada){
	stack<pair<string, bool> > preguntas_respuesta;
	preguntas_formuladas_recursivo(preguntas_respuesta, jugada);
	return preguntas_respuesta;
}

void QuienEsQuien::mostrar_preguntas_formuladas(stack<pair<string, bool> >  preguntas_respuestas){
	cout << "El personaje oculto tiene las siguientes características: " << endl;
	while(!preguntas_respuestas.empty()){
		cout << preguntas_respuestas.top().first << " --- " << (preguntas_respuestas.top().second ? "Sí" : "No") << endl;
		preguntas_respuestas.pop();
	}
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	set<string> personajes_levantados;
	personajes_restantes(personajes_levantados,jugada_actual);
	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a,
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes_recursivo(bintree<Pregunta>::node n){
	if( !n.null() && (*n).obtener_num_personajes() > 1 ) {	
		if(!n.left().null() && n.right().null()){
			if( n == arbol.root() ){
				arbol.assign_subtree(arbol, n.left());
				eliminar_nodos_redundantes_recursivo(arbol.root());
			}		
			else{
				bintree<Pregunta> subarbol;
				subarbol.assign_subtree(arbol, n.left());
				bintree<Pregunta>::node padre=n.parent();
				if( padre.left() == n ){
					arbol.insert_left(padre, subarbol);
					eliminar_nodos_redundantes_recursivo(padre.left());
				}else{
					arbol.insert_right(padre, subarbol);
					eliminar_nodos_redundantes_recursivo(padre.right());
				}
			}
		}
		else if( n.left().null() && !n.right().null() ){			
			if( n == arbol.root() ){
				arbol.assign_subtree(arbol, n.right());
				eliminar_nodos_redundantes_recursivo(arbol.root());
			}
			else{
				bintree<Pregunta> subarbol;
				subarbol.assign_subtree(arbol, n.right());
				bintree<Pregunta>::node padre=n.parent();
				if( padre.left() == n ){
					arbol.insert_left(padre, subarbol);
					eliminar_nodos_redundantes_recursivo(padre.left());
				}else{
					arbol.insert_right(padre, subarbol);
					eliminar_nodos_redundantes_recursivo(padre.right());
				}
			}
		}
		else if( n.left().null() && n.right().null() ){
			cerr<<"Arbol mal contruido (dos personajes iguales)."<<endl;
		}else{
			eliminar_nodos_redundantes_recursivo(n.left());
			eliminar_nodos_redundantes_recursivo(n.right());
		}		
	}
}

void QuienEsQuien::eliminar_nodos_redundantes(){
	eliminar_nodos_redundantes_recursivo(arbol.root());
}

float QuienEsQuien::profundidad_promedio_hojas(){
	//TODO :)

	return -1;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atr_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
