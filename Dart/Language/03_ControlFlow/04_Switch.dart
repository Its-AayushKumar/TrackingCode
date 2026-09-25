void main (){
  String someValue = 'hi!!!';

  switch (someValue) {    
    case 'hi':
      print ('Hello');
      
    case 'hi!':
      print ('Hello!');
      
    case 'hi!!':
      
      break;
    default:
    print('yooo');
  }

  int age = 10 ;

  switch (someValue) {
    case 'hi!!!' when age >= 10:
    print('panda');
    case 'hii':
      
      
    default:
    print("yoo");
  }
}

// Using break is not compulsory here its only required when the case is empty 