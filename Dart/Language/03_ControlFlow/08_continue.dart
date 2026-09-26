void main(){
  String value = 'Hello';
  for (int i = 0; i<value.length;i++){
    if(i == 1 || i == 2 || i==3){
      continue;
    }
    print(value[i]);
  }
}
// if the condition is met then continue will again run the loop 