int MICRO = 0;
void setup()
{
    Serial.begin(9600);
    pinMode(2,INPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);

}
void loop()
{
    MICRO = digitalRead(2);
    Serial.println(MICRO);
    delay(50);
    if(MICRO == 1)
    {
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
    }
    else
    {
        digitalWrite(6,LOW);
        digitalWrite(7,LOW)
    }
    
}