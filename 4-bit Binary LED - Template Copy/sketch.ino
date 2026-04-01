
int ledPin[] = {13, 12, 11,10};
int ledDelay[4]={8000, 4000,2000, 1000};
// declare other required variables
unsigned long currTime;
unsigned long lastChangeTimes[4];
bool ledState[4]={false, false, false, false};

void setup() {
  currTime =0;
  for(int i=0;i<4;i++){
    // initialize lastChangeTimes
    lastChangeTimes[i] = 0;

    // set pin mode for ledPins
    pinMode(ledPin[i], OUTPUT);
    
  }
}


void loop() {
  // implement the toggling logic
  currTime = millis();
  for (int i = 0; i<4; i++) {
    if (currTime - lastChangeTimes[i] >= ledDelay[i]) {
      lastChangeTimes[i] = currTime;
      ledState[i] = !ledState[i];
      digitalWrite(ledPin[i], ledState[i]);
    }
  }
  
}
