#define redPin 25
#define greenPin 26
#define bluePin 27

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(255,0,0);//Red
  delay(1000);
  setColor(0,255,0);//Green
  delay(1000);
  setColor(0,0,255);//Blue
  delay(1000);
  setColor(255,255,255);//white
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
