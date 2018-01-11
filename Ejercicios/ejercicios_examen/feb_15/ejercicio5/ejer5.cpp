/*Metemos los elementos de la list<string> en el dictionary iterando sobre sus
elementos en orden, poniendo como clave desde i hasta info.size().*/
dictionary::dictionary(const list<string> info){
  for(int i= 0; i< info.size(); i++)
    data[i]= *j;
}

bool is_prime(int number){
  for(int i= 2;i < sqrt(number); i++)
    if(number%i == 0)
      return false;

    return true;
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

map<int, list<string> >& operator*(){

}
