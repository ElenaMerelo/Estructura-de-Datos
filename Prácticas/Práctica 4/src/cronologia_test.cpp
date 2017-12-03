#include<iostream>
#include<cronologia.h>
#include<fstream>
using namespace std;

int main(int argc, char * argv[]){

    ifstream f1(argv[1]);
    if(!f1){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    ifstream f2(argv[2]);
    if(!f2){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    cronologia a;
    cronologia b;

    f1 >> a;
    f2 >> b;

    // cout << a << endl;
    // cout << b << endl;

    // cronologia u;
    // a.unionCronologias(b,u);

    // cout << u << endl;

    cronologia i;
    a.interseccionCronologias(b,i);

    cout << i << endl;

    // cout << a.search_fecha_historica(19334) << endl;

}
