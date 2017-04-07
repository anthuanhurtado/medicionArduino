#include <NewPing.h>

#define  TRIGGER_PIN 11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define  ECHO_PIN    10  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
 // digitalWrite(7,HIGH);
  //delay(1000);
  ///digitalWrite(9,HIGH);
  ///delay(1000);
  //digitalWrite(12,HIGH);
  //delay(1000);
  //digitalWrite(7, LOW);
  //digitalWrite(9, LOW);
  //digitalWrite(12, LOW);
  //delay(1000);
  
  delay(1000);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.println("");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  int distance=uS / US_ROUNDTRIP_CM;

  unsigned int medicion = sonar.ping(); 
  if (distance >40){
    digitalWrite(7,HIGH);
    digitalWrite(9,LOW);
  //delay(1000);
  }else if(distance <10){
    digitalWrite(7,LOW);
    digitalWrite(9, HIGH);
  }
}
