#include <DHT.h>
#define DHTV DHT11
#define DHTPIN 13
#define LEDBUZZPIN 20
// #define LEDPIN 8
#define DL 3000

DHT dht(DHTPIN,DHTV);

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDBUZZPIN,OUTPUT);
  // pinMode(LEDPIN,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  float h=dht.readHumidity();
  float c=dht.readTemperature(false);
  float f=dht.readTemperature(true);

  if(isnan(h) || isnan(c) || isnan(f))
  {
    Serial.println("Enable to read the Temprature or Humidity from DHT11 sensor");
    return;
  }

  if(c > 30)
  {
    digitalWrite(LEDBUZZPIN,HIGH);
    // digitalWrite(LEDPIN,LOW);
  }
  else
  {
    digitalWrite(LEDBUZZPIN,LOW);
    // digitalWrite(LEDPIN,HIGH);
  }

  Serial.println("New..");
  Serial.print("Humidity : ");
  Serial.println(h);

  Serial.print("Fahrenheit : ");
  Serial.println(f);

  Serial.print("Celsius : ");
  Serial.println(c);
  
}
