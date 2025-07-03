const int buttonPin=15;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState=digitalRead(buttonPin);

  if(buttonState==LOW){
    Serial.println("button pressed");
  }
  else{
    Serial.println("button released");
  }
  delay(2000);
}
