int MIC_IN = 2;
int BUTTON = 8;
int LED1 = 7;
int LED2 = 6;
int BUZZER1 = 4;
int BUZZER2 = 5;

int micValue;
boolean alarmOn;
unsigned long Timer; 
boolean alreadyOn;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT);
  alarmOn = false;
  alreadyOn = false;
  pinMode(MIC_IN, INPUT);
  count = 0;
}

void loop() {
  micValue = digitalRead(MIC_IN);
  if(millis() - Timer > 1500UL) {
    alarmOn = false;
  }
  if(micValue == HIGH && !alreadyOn) {
    alarmOn = true;
    Timer = millis();
  }

  int buttonPressed = digitalRead(BUTTON);
  if(buttonPressed == LOW) {
    alarmOn = false;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }

  if(alarmOn){
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER2, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    alreadyOn = true;
  } else{
    digitalWrite(BUZZER1, LOW);
    digitalWrite(BUZZER2, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    if(alreadyOn) {
      delay(250);
      alreadyOn = false;
    }
  }
}
