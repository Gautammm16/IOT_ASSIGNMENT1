#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 13
#define AVG 5.0

DHT dht(DHTPIN,DHTTYPE);

float ftot = 0;
float ctot = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(" ");
  dht.begin();

  if(isnan(dht.readTemperature(true)) || isnan(dht.readTemperature(false)))
  {
    Serial.println("Enable to read Temprature");
    return;
  }


  for(int i=0;i<(int)AVG;i++)
  {
    ftot += dht.readTemperature(true);
    ctot += dht.readTemperature(false);
  }

  Serial.print("AVG : ");
  // Serial.println(ftot / AVG);
  Serial.println(ctot / AVG);

  long add=0;
  long f = 0;
  long s = 1;

  for(int i=0;i<((int)(ctot / AVG));i++)
  {
    Serial.print(add);
    Serial.print("  ");
    f = s;
    s = add;
    add = f + s;
  }

  Serial.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}

