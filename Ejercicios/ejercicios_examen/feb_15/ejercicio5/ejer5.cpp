/*Metemos los elementos de la list<string> en el dictionary iterando sobre sus
elementos en orden, poniendo como clave desde j hasta info.size().*/
dictionary::dictionary(list<string> info){
    data.insert(pair<int, list<string> >(0, info));
}

bool dictionary::is_prime(int number){
  for(int i= 2;i < sqrt(number); i++)
    if(number%i == 0)
      return false;

    return true;
}

void dictionary::insert(int key, list<string> value){
  data.insert(pair<int, list<string> >(key, value));
}

void dictionary::show_elements(){
  typename map<int, list<string> >::iterator i;
  typename list<string>::iterator j;

  cout << "\n";
  for(i= data.begin(); i != data.end(); i++){
    cout << " " << i->first;
    for(j= i->second.begin(); j != i->second.end(); j++)
      cout << " " << *j;
  }

}

dictionary::iterator::iterator(const dictionary::iterator &i){
  my_iterator= i.my_iterator;
}

dictionary::iterator& dictionary::iterator::operator=(const dictionary::iterator &i){
  my_iterator= i.my_iterator;
  return *this;
}

dictionary::iterator& dictionary::iterator::operator++(){

  while(!is_prime(my_iterator->first))
    my_iterator++;

  return *this;
}

pair<int, list<string> >& dictionary::iterator::operator*(){
  return *my_iterator;
}

/*dictionary::iterator dictionary::iterator::begin(){
  return data.begin();
}

dictionary::iterator dictionary::iterator::end(){
  return data.end();
}*/

bool dictionary::iterator::operator==(const dictionary::iterator &other){
  return other.my_iterator == my_iterator;
}

bool dictionary::iterator::operator!=(const dictionary::iterator &other){
  return other.my_iterator != my_iterator;
}
