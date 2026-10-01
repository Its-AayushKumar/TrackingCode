void main() {
  String name = 'panfda';
  // printName(name);
  // passing name does not affect the original value inside the fuction
  // print(name);

  printName(age: 20, name: name, greetings: 'Yooooo');
}

// void printName(String name) {
//   name = "panda";
//   print(name);
// }

// positional arguments
void printName({
  required String name,
  required int age,
  required String greetings,
}) {
  print(name);
} // by using this we dont have to worry about the order of this variables  we can just co name: Aayush in any order

// if we dont want every field requeired then we can just use ?

void printName1({
  required String name,
  required int age,
  String? greetings,
}) {
  print(name);
}
// now its not compulsory to give greetings a value 


// we can make posittional as well as named arguments together 

void printName2(int age ,{required String name, String? greetings}) {
  print(name);
}
//  so in this we have to first enter name after that we can use named agruments 