/*Metemos los elementos de la list<string> en el dictionary iterando sobre sus
elementos en orden, poniendo como clave desde j hasta info.size().*/

bool is_prime(int number){
  for(int i= 2;i < sqrt(number); i++)
    if(number%i == 0)
      return false;

  return true;
}

dictionary::dictionary(list<string> info){
    data.insert(pair<int, list<string> >(0, info));
}

void dictionary::insert(int key, list<string> value){
  data.insert(pair<int, list<string> >(key, value));
}

void dictionary::show_elements_normal(){
  map<int, list<string> >::iterator m;
  list<string>::iterator n;
  cout << "\n";
  for(m= data.begin(); m != data.end(); m++){
    cout << " " << m->first;
    for(n= m->second.begin(); n != m->second.end(); n++)
      cout << " " << *n;

    cout << "\n";
  }

}

void dictionary::show_elements_my_it(){
  dictionary::iterator my_i;
  list<string>::iterator my_j;

  for(my_i= data.begin(); my_i != data.end(); ++my_i){
    cout << my_i.first();
    for(my_j= my_i.begin(); my_j != my_i.end(); ++my_j)
      cout << " " << *my_j;
    cout << "\n";
  }

}

dictionary::iterator& dictionary::iterator::operator=(const map<int, list<string> >::iterator &other){
  i= other;

  return *this;
}

dictionary::iterator& dictionary::iterator::operator++(){
  while(!is_prime(i->first))
    ++i;

  return *this;
}

pair<int, list<string> > dictionary::iterator::operator*(){
  return make_pair(i->first, i->second);
}

bool dictionary::iterator::operator==(dictionary::iterator other){
  return other.i == i;
}

bool dictionary::iterator::operator!=(const map<int, list<string> >::iterator &other){
  return other != i;
}

dictionary::iterator dictionary::begin(){
  map<int, list<string> >::iterator map_it= data.begin();
  dictionary::iterator it(map_it);
  return it;
} 

dictionary::iterator dictionary::end(){
  map<int, list<string> >::iterator map_it= data.end();
  dictionary::iterator it(map_it);
  return it;
}

int dictionary::iterator::first(){
  return i->first;
}

list<string> dictionary::iterator::second(){
  return i->second;
}

list<string>::iterator dictionary::iterator::begin(){

  return i->second.begin();
}

list<string>::iterator dictionary::iterator::end(){

  return i->second.end();
}