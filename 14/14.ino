// VCC → 5V (on Arduino)
// GND → GND (on Arduino)
// Trig → Digital Pin 7 (on Arduino)
// Echo → Digital Pin 8 (on Arduino)

#define trigPin 7
#define echoPin 8

long distance;
long duration;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop()
{
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);

  duration = pulseIn(echoPin,HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Duration : ");
  Serial.println(duration);

  Serial.print("Distance : ");
  Serial.println(distance);

  delay(500);

}