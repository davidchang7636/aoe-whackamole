const int buttonPin = 3;
const int ledPin = 7;
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 250;

int currScore = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  startMillis = millis();
}

void loop() {
  currentMillis = millis();
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    if (currentMillis - startMillis >= period) {
      currScore += 50;
      Serial.println(currScore);
      startMillis = currentMillis;
    }
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
  /**
  if(buttonState == HIGH) { 
    currScore += 50;
    Serial.println(currScore);
    digitalWrite(ledPin, LOW);
    delay(2000);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
  **/
}
