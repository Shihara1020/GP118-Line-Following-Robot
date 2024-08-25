void setup() {
  Serial.begin(9600);
}

void loop() {
  Read_the_sensor_value();
}

void Read_the_sensor_value() {
  for (short int i = 5; i >=0 ; i--) Serial.print(String(analogRead(i)) + " ");
  Serial.println();
  delay(100);
}
