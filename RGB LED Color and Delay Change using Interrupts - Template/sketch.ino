#define colorBtn 6
#define durationBtn 7
bool colors[][3] = {
  {1,1,1} , {1,0,0},{0,1,0},{0,0,1},  // wrgb
  {0,1,1} , {1,1,0},{1,0,1},{0,0,0} // cymk
};
char* colorNames[] = {
  "white","red","green","blue",
  "cyan","yellow","megenta","black" // black is just off so do not need to toggle to black
};

int delays[] = {
  1000, 800, 600, 400, 200
};

//LED pin
#define redPin  13
#define greenPin 12
#define bluePin 11

volatile int colorIndex = 0;
volatile int delayIndex = 0;

unsigned long lastColorInterrupt = 0;
unsigned long lastDurationInterrupt = 0;

const int debounceTime = 200;
unsigned long previousMillis = 0;

void changeColor() {
  unsigned long currentTime = millis();

  if (currentTime - lastColorInterrupt > debounceTime) {
    colorIndex++;
    if (colorIndex >= 8) {
      colorIndex = 0;
    }
    lastColorInterrupt = currentTime;
  }
}

void changeDuration() {
  unsigned long currentTime = millis();

  if (currentTime - lastDurationInterrupt > debounceTime) {
    delayIndex++;
    if (delayIndex >= 5) {
      delayIndex = 0;
    }
    lastDurationInterrupt = currentTime;
  }
}


void setup() {
  pinMode(colorBtn, INPUT_PULLUP);
  pinMode(durationBtn, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(colorBtn), changeColor, FALLING);
  attachInterrupt(digitalPinToInterrupt(durationBtn), changeDuration, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= delays[delayIndex]) {

    previousMillis = currentMillis;

    digitalWrite(redPin, colors[colorIndex][0]);
    digitalWrite(greenPin, colors[colorIndex][1]);
    digitalWrite(bluePin, colors[colorIndex][2]);

  }


}

