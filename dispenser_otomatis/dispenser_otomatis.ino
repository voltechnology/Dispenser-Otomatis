#include <Servo.h>

Servo servoMotor; // Membuat objek servo
const int trigPin = 9; // Pin untuk Trig
const int echoPin = 10; // Pin untuk Echo
const int servoPin = 11; // Pin untuk Servo

long duration;
int distance;

void setup() {
servoMotor.attach (servoPin); // Menghubungkan servo
pinMode(trigPin, OUTPUT); // Set Trig sebagai OUTPUT
pinMode(echoPin, INPUT); // Set Echo sebagai INPUT
Serial.begin(9600); // Memulai komunikasi serial
servoMotor.write(0); // Menutup kran dispenser

}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034/2; 
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");

if (distance < 10) {
servoMotor.write(90); 
delay(2000); 
servoMotor.write(0);
}

delay(500); 
}