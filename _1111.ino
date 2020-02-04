#define LED 13

void setup() {
pinMode(LED, OUTPUT);
}

void loop() {
for(int i=1000;i<=3000;i+=1000)
{
  digitalWrite(LED,HIGH);
  delay(i);
  digitalWrite(LED,LOW);
  delay(i);
}
}
