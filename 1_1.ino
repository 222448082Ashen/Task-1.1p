const int ledPin = 12;
const int buttonPin = 11;
int buttonState = 0;

const int dotDuration = 200;
const int dashDuration = 3 * dotDuration;

const char* morseCode[] = {".-", "...", "....", ".", "-"};

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(dotDuration);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    for (int i = 0; i < 5; i++) {
      const char* letter = morseCode[i];
      for (int j = 0; letter[j] != '\0'; j++) {
        if (letter[j] == '.') {
          dot();
        } else if (letter[j] == '-') {
          dash();
        }
      }
      delay(dotDuration * 3);
    }
 
  }
}
