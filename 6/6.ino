int buzz=30;
int arr[]={1,0,1,0,1,1,1,0,1};

void setup() {
  // put your setup code here, to run once:
  pinMode(buzz,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int l = sizeof(arr) / sizeof(int);

  for(int i=0;i<l;i++)
  {
    digitalWrite(buzz,arr[i]);
  }
  
}
