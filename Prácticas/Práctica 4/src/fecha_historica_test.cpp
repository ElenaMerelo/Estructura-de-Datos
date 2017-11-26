#include<iostream>
#include<fstream>
#include<cronologia.h>

using namespace std;

int main(int argc, char * argv[]){
    cout << "Programa de prueba" << endl;
    if( argc!= 2){
        cout << "Número de argumentos incorrecto." << endl;
        return 1;
    }
   
    ifstream f (argv[1]);
    if (!f){
    cout<<"Error al abrir el fichero "<<argv[1]<<endl;
    return 1;
    }

    cronologia a;
    f >> a;
    cout << a << endl;

    cout << a.search_fecha_historica(1903) << endl;
}

