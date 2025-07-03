#define TRIG_PIN 5
#define ECHO_PIN 18
long duration;
float distanceCm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
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
  delay(500);
}
