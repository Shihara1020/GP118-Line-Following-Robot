float P, I, D;
float error = 0;
float PreviousError = 0;
float Kp = 10; // Proportional gain
float kd =5.7; //Derivative gain
float ki = 0; //Integral gain 

int IR_value[5] = {0, 0, 0, 0, 0};
int IR_weights[5] = {-10, -5, 0, 5, 10}; // Assign values to each sensor
float trus[5];

// Define the function
void PID_control();
void reading();


void setup() {
  //put your setup code here,to run once
}

void loop() {
    PID_control();
}

void reading() {
  error = 0;
  for (byte i = 0; i < 5; i++) {
    IR_value[i] = analogRead(i);
    // Convert analog value to digital
    if (IR_value[i] > trus[i]) {
      IR_value[i] = 1;
    } else { 
      IR_value[i] = 0;
    }
    error += IR_value[i] * IR_weights[i];
  }
}
void PID_control() {
  while (1) {
    reading();
    // Calculations for PID control
    P = error;
    I = I + error;
    D = error - PreviousError;
    PreviousError = error;
    // Main equations
    speedAdjust = (Kp * P + ki * I + kd * D);
    // Set the speed
    LMotorspeed = Motorbasespeed + speedAdjust;
    RMotorspeed = Motorbasespeed - speedAdjust;

    if (LMotorspeed < 0) {
      LMotorspeed = 0;
    }
    if (LMotorspeed > Maxium_speed) {
      LMotorspeed = Maxium_speed;
    }
    if (RMotorspeed < 0) {
      RMotorspeed = 0;

    }
    if (RMotorspeed > Maxium_speed) {
      RMotorspeed = Maxium_speed;
    }
    if (RMotorspeed==Motorbasespeed) {
      RMotorspeed = Maxium_speed;
    }
    if (LMotorspeed==Motorbasespeed) {
      LMotorspeed = Maxium_speed;
    }
    set_speed();  
  }
}

void set_speed() {
  analogWrite(Leftmotorf, LMotorspeed);
  analogWrite(Rightmotorf, RMotorspeed);
}



