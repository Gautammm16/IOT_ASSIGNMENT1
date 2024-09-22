//GND in ground pin
//VCC in 5 walt
//Data in any digital pin


#define PIRPIN 13

void setup() {
  Serial.begin(9600);
  pinMode(PIRPIN,INPUT);
}

void loop() {
  delay(1000);
  if(digitalRead(PIRPIN) == 1)
  {
    Serial.println("Object Detected");
  }
  else
  {
    Serial.println("Object Not Detected");
  }

}
