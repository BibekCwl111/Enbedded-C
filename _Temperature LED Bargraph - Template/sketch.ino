// Reference https://docs.wokwi.com/parts/wokwi-ntc-temperature-sensor

#define sensorPin A0
#define BETA 3950

int ledArray[] = {4,5,6,7,8,9,10,11,12,13};

void setup() {
    // initialize LEDs and sensor pin
    for (int i = 0; i < 10; i++) {
      pinMode(ledArray[i], OUTPUT);
    }
}

void loop() {
  // Read the sensor value , calculate the temperature, light up the leds
   int analogValue = analogRead(A0);
    float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;

   int ledCount = map(celsius,0,50,0,10);

   if (ledCount < 0) ledCount =0;
   if (ledCount >10) ledCount =10;

   for (int i = 0; i< 10; i++) {
    if (i < ledCount) {
      digitalWrite(ledArray[i], HIGH);
    } 
    else {
      digitalWrite(ledArray[i], LOW);
    }
   }
  delay(10); // this speeds up the simulation
}
