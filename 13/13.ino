//GND in ground pin
//VCC in 5 walt
//Data in any digital pin


#define PIRPIN 13
#define LEDR 50 
#define LEDW 52

void setup() {
  // Serial.begin(9600);
  pinMode(PIRPIN,INPUT);
  pinMode(LEDR,OUTPUT);
  pinMode(LEDW,OUTPUT);
}

void loop() {
  if(digitalRead(PIRPIN) == 1)
  {
    digitalWrite(LEDW,1);
    digitalWrite(LEDR,0);
  }
  else
  {
    digitalWrite(LEDW,0);
    digitalWrite(LEDR,1);
  }

}
