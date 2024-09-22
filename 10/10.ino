#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 13

DHT dht(DHTPIN,DHTTYPE);
// float humarr[10];
float humtot = 0 ;
float ftot = 0;
float ctot = 0;

void setup() {
  dht.begin();
  Serial.begin(9600);

  for(int i=0;i<10;i++)
  {
    humtot += dht.readHumidity();
    if(i<3)
    {
      ftot += dht.readTemperature(true);
      ctot += dht.readTemperature(false);
    }
  } 

  Serial.print("Humidity : ");
  Serial.println(humtot);
  Serial.println(humtot / 10.0);
  Serial.print("F : ");
  Serial.println(ftot);
  Serial.println(((int)ftot % 2 == 0) ? "Even" : "Odd");
  Serial.print("C : ");
  Serial.println(ctot);
  Serial.println(((int)ctot % 2 == 0) ? "Even" : "Odd");
}

void loop() {
  
}
