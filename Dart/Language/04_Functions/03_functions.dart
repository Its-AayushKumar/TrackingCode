import '01_function.dart';

void main() {
  final stuff = printStuff();

  print(stuff.name);
  print(stuff.age);

  printstuff();
}


({int age, String name}) printStuff() {
  return (age: 12, name: 'Panda');
}


// Arrow function - its basically used when we want to perform one operation only

void printstuff() => print('hii');

// Anonymous Functions  -> Functions that don't have any name but behave like a function (block of code that can be executed )are anonymous functions .

//  eg. (){
// print('hi');
// }