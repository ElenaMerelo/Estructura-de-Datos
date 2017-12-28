info& agenda::find_name(string name){
  //Nos aseguramos de que la persona esté en la agenda
  assert(p.count(name)> 0);

  return p.find(name)->second;
}

string agenda::find_telephone(string num){
  people::iterator i;

  for(i= p.begin(); i!= p.end(); i++){
    if((i->second).first.compare(num) == 0)
      return i->first;
  }
  return "nadie";
}

void agenda::insert(pair<string, info> person){
  p.insert(person);
}
