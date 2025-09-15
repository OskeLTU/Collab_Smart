#include <Arduino.h>
int M1F = ;   // Motor 1 forward
int M1B = ;   // Motor 1 backward
int M2F = ;   // Motor 2 forward
int M2B = ;   // Motor 2 backward

bool sensor_flag = false;

void setup() {


  pinMode(M1F, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2B, OUTPUT);

  stop_motors();
  
}

void forward() {
  digitalWrite(M1F, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, HIGH);
  digitalWrite(M2B, LOW);
}

void backward() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, HIGH);
}

void turn_left() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2F, HIGH);
  digitalWrite(M2B, LOW);
}

void turn_right() {
  digitalWrite(M1F, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, HIGH);
}

void stop_motors() {
  digitalWrite(M1F, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, LOW);
}

bool read_front_sensor() {
  if("sensor activated"){
    sensor_flag = true;
    return true;
  }else{
    return false;
  }
}

bool read_left_sensor() {
  if("sensor activated"){
    sensor_flag = true;
    return true;
  }else{
    return false;
  }
}

bool read_right_sensor() {
  if("sensor activated"){
    sensor_flag = true;
    return true;
  }else{
    return false;
  }
}

void loop() {
  while(sensor_flag == false) {
    forward();
  
  }
}

#include <Arduino.h>

int motor1A = 0;  
int motor1B = 8;  
int motor2A = 1;  
int motor2B = 12; 

void setMotorPins(int pinA, int pinB, int speedA, int speedB) {
  analogWrite(pinA, speedA);
  analogWrite(pinB, speedB);
}

void motor1Forward(int speed) {
  setMotorPins(motor1A, motor1B, speed, 0);
}

void motor1Backward(int speed) {
  setMotorPins(motor1A, motor1B, 0, speed);
}

void motor1Stop() {
  setMotorPins(motor1A, motor1B, 0, 0);
}

void motor2Forward(int speed) {
  setMotorPins(motor2A, motor2B, speed, 0);
}

void motor2Backward(int speed) {
  setMotorPins(motor2A, motor2B, 0, speed);
}

void motor2Stop() {
  setMotorPins(motor2A, motor2B, 0, 0);
}

void setup() {
  Serial.begin(115200);

  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT); 
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  Serial.println("Motors Forward");
  motor1Forward(255);
  motor2Forward(255);
}