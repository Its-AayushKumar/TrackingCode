// <datatype> funcName(){}


void main() {
  printName();
  print(num());

  print(multi());
  print(multi().$4);// by this way we can select which value we want to return 
  var (age,name,isAdult,namee)= multi();
  print(age);
  print(name);
  print(isAdult);
  print(namee);

}

void printName() {
  print("Panda");
}

int num() {
  return 10;
}

(int, String,bool,String) multi() {
  return (69, "panda",true,"mice");
}
// by this method we can return multiple datatypes in a function 