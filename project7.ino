int ledArray[] = {2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(A0, INPUT);
}

int setLedBrightness(int sensorValue){
  for (int i = 0; i < 8; i++){
     analogWrite(ledArray[i], sensorValue);
  }
  return 0;
}

void turnOnLED(int ledNum){
//  Serial.println(ledNum);
for (int i = 8; ledNum < i; i--){
     analogWrite(ledArray[ledNum], 255);
     }
for (int i = 0; ledNum > i; i++){
     analogWrite(ledArray[i], LOW);
     }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  // The following converts sensorValue to 256 value, 
  // When divided by 32 the result is an 8bit value.
  // This 8 bit value allows us to iterate over leds in the ledArray.
  int ledNum = (sensorValue / 4 +1) / 32;
  delay(10);
  Serial.println(sensorValue / 36);
  turnOnLED(ledNum);
}
