#define IR_S 5
#define BZ_S 5
void setup() {
  // put your setup code here, to run once:
  pinMode(IR_S,INPUT);
  pinMode(BZ_S,OUTPUT)
  Serial.begin(115200);
}

void loop() {
  int S_state=digitalRead(IR_S)
  if(S_state==LOW){
    digitalWrite(BZ_S,HIGH)
    Serial.println("detected!");
  }
  else{
    digitalWrite(BZ_S,LOW)
    Serial.println("nopee");}
  delay(300);
}
