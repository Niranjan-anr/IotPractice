const int VRx=34;
const int VRy=35;
const int SW=18;

void setup() {
  Serial.begin(115200);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

    Serial.println("Joystick started");
}

void loop() {
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  bool buttonPressed = digitalRead(SW) == LOW;

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" Button: ");
  Serial.println(buttonPressed ? "Pressed" : "Released");

  delay(100);
}
