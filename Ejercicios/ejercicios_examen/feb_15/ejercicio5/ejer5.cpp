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

void dictionary::show_elements(){
  map<int, list<string> >::iterator i= data.begin();
  list<string>::iterator j;
  cout << "\n";
  for(i= data.begin(); i != data.end(); i++){
    cout << " " << i->first;
    for(j= i->second.begin(); j != i->second.end(); j++)
      cout << " " << *j;
  }

}

dictionary::iterator& dictionary::iterator::operator=(const dictionary::iterator &other){
  i= other.i;
  return *this;
}

dictionary::iterator& dictionary::iterator::operator++(){
  while(!is_prime(i->first))
    i++;

  return *this;
}

pair<int, list<string> > dictionary::iterator::operator*(){
  return make_pair(parent.i->first, parent.i->second);
}


bool dictionary::iterator::operator==(const dictionary::iterator &other){
  return other.i == i;
}

bool dictionary::iterator::operator!=(const dictionary::iterator &other){
  return other.i != i;
}
