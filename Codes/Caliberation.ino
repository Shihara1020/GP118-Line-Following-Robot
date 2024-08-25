// Caliberations
int sensorValues[5];
int minValues[5];
int maxValues[5];
float trus[5];
// Define the function prototypes
void caliberate();


void setup() {
  //Caliberations
  for (int i = 0; i < 5; i++) {
    minValues[i] = 1023;
    maxValues[i] = 0;
  }
}

void loop() {
  caliberate();
} 

void caliberate() {
  for (int i = 0; i < 10000; i++) {
    turn(); //Rotate the car for caliberation
    for (int i = 0; i < 5; i++) {
      int value = analogRead(i);
      if (value < minValues[i]) {
        minValues[i] = value;
      }
      if (value > maxValues[i]) {
        maxValues[i] = value;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    trus[i] = (minValues[i] + maxValues[i]) / 2.0;
  }
  stop(); //Stop the car
}
