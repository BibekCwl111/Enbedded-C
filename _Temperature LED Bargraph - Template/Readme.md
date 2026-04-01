# Problem Statement

Design an Arduino program to read temperature data from an NTC temperature sensor
and display the temperature level using a series of 10 LEDs(LED array).
The LEDs should light up proportionally to the temperature, ranging from -24°C to 80°C.

### Requirements:
- **Sensor Input**: Connect the NTC temperature sensor to analog pin A0.
- **LED Output**: Connect 10 LEDs to digital pins 4 through 13.
- **Temperature Calculation**: Use the provided formula to convert the sensor's analog reading to Celsius.
- **LED Display**: Quantize the temperature value into 10 levels and illuminate the corresponding number of LEDs.
- **Range**: Temperature range from -24°C to 80°C.

### Example:
- If the temperature is at the minimum (-24°C), no LEDs should be lit.
- If the temperature is at the maximum (80°C), all 10 LEDs should be lit.
