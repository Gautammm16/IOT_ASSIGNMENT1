int led = 20;

void setup() {
  
  pinMode(led,OUTPUT);
}

void loop() {
  
  digitalWrite(led,1);
  delay(2000);
  digitalWrite(led,0);
  delay(2000);
}
