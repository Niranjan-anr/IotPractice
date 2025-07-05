#define redPin 25
#define greenPin 26
#define bluePin 27

#define TRIG_PIN 5
#define ECHO_PIN 18
long duration;
float distanceCm;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

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

  if(distanceCm<20)
  setColor(255,0,0);//Red
  else if(distanceCm>100)
  setColor(0,255,0);//Green
  else vc
  setColor(0,0,255);//Blue
  delay(1000);
}

void setColor(uint8_t red,uint8_t green,uint8_t blue){
  ledcAttachPin(redPin,1);
  ledcAttachPin(greenPin,2);
  ledcAttachPin(bluePin,3);

  ledcSetup(1,5000,8);
  ledcSetup(2,5000,8);
  ledcSetup(3,5000,8);

  ledcWrite(1,red);
  ledcWrite(2,green);
  ledcWrite(3,blue);
  
}
