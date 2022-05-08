#define SensorPin A0
#define RED_LED 13   // The pin the LED is connected to
#define GREEN_LED 12 // The pin the LED is connected to
#define LED_OFF LOW  // digitalWrite value to turn LED off
#define LED_ON HIGH

float sensorValue = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}
void loop()
{
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  }
  sensorValue = sensorValue / 100.0;
  Serial.println(sensorValue);
  if (sensorValue > 800)
  {
    digitalWrite(RED_LED, LED_ON); // Turn the LED on
    digitalWrite(GREEN_LED, LED_OFF);
  }
  else
  {
    digitalWrite(GREEN_LED, LED_ON);
    digitalWrite(RED_LED, LED_OFF);
  }
  delay(3000);
}
