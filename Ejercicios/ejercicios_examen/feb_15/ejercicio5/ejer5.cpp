/*Metemos los elementos de la list<string> en el dictionary iterando sobre sus
elementos en orden, poniendo como clave desde j hasta info.size().*/
dictionary::dictionary(const list<string> &info){
  typename list<string>::iterator i;
  int j= 0;
  for(i= info.begin(); i != info.end(); i++){
    data[j]= *i;
    j++;
  }
}

bool dictionary::is_prime(int number){
  for(int i= 2;i < sqrt(number); i++)
    if(number%i == 0)
      return false;

    return true;
}

void dictionary::insert(int key, string value){
  data.insert(pair<int, string>(key, value));
}

void dictionary::show_elements(){
  typename map<int, list<string> >::iterator i;
  for(i= data.begin(); i != data.end(); i++)
    cout << " " << i->first << " " << i->second;

  cout << "\n";
}

dictionary::iterator::iterator(const iterator &i){
  my_iterator= i;
}

iterator& dictionary::iterator::operator=(const iterator &i){
  my_iterator= i;
  return *this;
}

iterator& dictionary::iterator::operator++(){
  while(!is_prime(*my_iterator))
    my_iterator++;

  return *this;
}

map<int, list<string> >& dictionary::iterator::operator*(){
  return *my_iterator;
}

iterator dictionary::iterator::begin(){
  return data.begin();
}

iterator dictionary::iterator::end(){
  return data.end();
}

bool dictionary::iterator::operator==(const iterator &other){
  return other.my_iterator == my_iterator;
}

bool dictionary::iterator::operator!=(const iterator &other){
  return other.my_iterator != my_iterator;
}
