void main() {
  // for loop

  for (int i = 1; i <= 10; i++) {
    String hi = 'Hello world';
    print(hi.substring(0, 5));
    print('Hello world ${i + 1}');
  }

  // for in loop 
  String value = 'Hello';
  for (int i = 0 ; i<value.length;i++){
    print(value[i]);
  }
}
