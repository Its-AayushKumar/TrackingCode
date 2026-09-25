void main() {
  // Optional Variables
  // String/int/bool and null

  String? someValue;
  print(someValue);

  someValue = "wtf";
  print(someValue.length);

  someValue = null;
  print(someValue);

  // print(someValue.length);

  //  The last line fails because someValue might be null, and null has no length.

  print(someValue?.length);
  // But if we are using ? it means we are tell if its null print null if its not print whatever it is

  print(someValue?.length ?? 0);
  // This means if some value is null print 0 (Ternary operator)

  someValue = " Aayush";
    print(someValue?.length ?? 1);

}
