#define TRIG_PIN 5
#define ECHO_PIN 18
#define BZ_S 5
const int buttonPin=15;

long duration;
float distanceCm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(BZ_S,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);
  duration=pulseIn(ECHO_PIN,HIGH);
  distanceCm=duration*0.034 / 2 ;

  Serial.print("Distance:");
  Serial.print(distanceCm);
  Serial.println("cm");
  int buttonState=digitalRead(buttonPin);
  if(buttonState==LOW)
  if(distanceCm<10){
     digitalWrite(BZ_S,HIGH);
  }
  else digitalWrite(BZ_S,LOW);
  delay(500);
}
