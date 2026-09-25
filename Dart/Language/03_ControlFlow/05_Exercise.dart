/* Excercise :
Develop a program to calculate the shipping cost based on 
the destination zone and the weight of the package ( you will be provided )
calculate the shipping cost according to these conditions:
  If the destination zone is 'XYZ' the shipping cost is $5 per kg.
  If the destination zone is 'ABC' the shipping cost is $7 per kg.
  If the destination zone is 'PQR' the shipping cost is $10 per kg.
  If the destination zone is not 'XYZ','ABC' OR 'PQR' , display an error message.
   */

void main() {
  String destinationZone = 'ABC';
  double weight = 10;

  if (destinationZone == 'ABC') {
    print("The shipping cost is : ${weight * 7}");
  } else if (destinationZone == 'XYZ') {
    print("The shipping cost is : ${weight * 5}");
  }
   else if (destinationZone == 'PQR') {
    print("The shipping cost is : ${weight * 10}");
  }
  else{
    print("ERROR 506!!");
  }

}
