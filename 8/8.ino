#include <DHT.h>

#define DHTPIN 13

DHT dht(DHTPIN,DHT11);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{

  delay(5000);
  float h=dht.readHumidity();
  float c=dht.readTemperature(false);
  float f=dht.readTemperature(true);

  if(isnan(h) || isnan(f) || isnan(c))
  {
    Serial.println("Unable to read Temprature and Humidity");
    return;
  }

  Serial.println("\nNew Temp : ");
  Serial.print("Humidity : ");
  Serial.println(h);

  Serial.print("Fahrenheit : ");
  Serial.println(f);

  Serial.print("Celsius : ");
  Serial.println(c);


}