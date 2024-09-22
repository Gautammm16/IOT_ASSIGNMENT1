// VCC → 5V (on Arduino)
// GND → GND (on Arduino)
// Trig → Digital Pin 7 (on Arduino)
// Echo → Digital Pin 8 (on Arduino)

#define trigPin 7
#define echoPin 8
#define delays 2000
#define LEDR 20
#define LEDG 30


long duration;
long distance;
long avg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);

  long disAdd = 0;

   for(int i=0;i<3;i++)
    {
      digitalWrite(trigPin,1);
      delayMicroseconds(2);

      digitalWrite(trigPin,0);
      delayMicroseconds(10);
      digitalWrite(trigPin,1);

      duration = pulseIn(echoPin,1);
      distance = duration * 0.034 / 2;
      Serial.print("Distance ");
      Serial.print(i + 1);
      Serial.print(" : ");
      Serial.println(distance);
      disAdd += distance;
      delay(delays);
    }

    avg = (long) disAdd / 3;

  Serial.print("Avg distance : ");
  Serial.println(avg);


  long sum  = 0;
  long temp = (long) avg;
  int l = 0;

  while(temp > 0)
  {
    l++;
    temp /= 10;
  }

  temp = (long) avg;

  while(temp > 0)
  {
    int rem = temp % 10;
    sum += pow(rem,l);
    temp /= 10;
  }

  if(avg == sum)
  {
    Serial.println("Number is Armstrong");
    digitalWrite(LEDG,1);
    digitalWrite(LEDR,0);
  }
  else
  {
    Serial.println("Number is Not Armstrong");
    digitalWrite(LEDG,0);
    digitalWrite(LEDR,1);
  }

}

void loop()
{

}
