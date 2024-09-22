int btn = 20;
int led = 30;

void setup() {
  pinMode(btn,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn) == 0)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }

}
