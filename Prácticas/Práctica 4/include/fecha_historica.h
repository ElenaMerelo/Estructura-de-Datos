#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>
#include<stdlib.h>
#include<set>

using namespace std;

class fecha_historica{
    private:
        pair<int, set<string> > data;
    public:
        fecha_historica(){};
        fecha_historica(const pair<int, set<string> > &d){ data = d; }
        fecha_historica& operator=(const pair<int, set<string> > &d){ data = d; return *this; }
        int getAge() const { return data.first; }
        void setAge(int a){ data.first = a;}
        set<string>& getEvents(){ return data.second; }
        int getNumEvents(){ return data.second.size(); }
        void addEvent(string event);

        friend ostream& operator<<( ostream& os, const fecha_historica& f);
        friend istream& operator>>( istream& is, fecha_historica& f);

        typedef typename set<string>::iterator iterator;
        typedef typename set<string>::const_iterator const_iterator;

};

#endif