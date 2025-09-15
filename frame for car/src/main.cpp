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
