 const int buttonPin=15;
const int laserPin=5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin,INPUT);
  pinMode(laserPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState=digitalRead(buttonPin);

  if(buttonState==LOW){
    Serial.println("button pressed"); 
    digitalWrite(laserPin,HIGH);
  }
  else{
    Serial.println("button released");
    digitalWrite(laserPin,LOW);
  }
  delay(200);
}
