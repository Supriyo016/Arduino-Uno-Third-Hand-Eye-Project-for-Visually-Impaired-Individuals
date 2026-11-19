// Third Hand-Eye: ultrasonic obstacle alert for visually impaired users.
// Hardware: Arduino Uno, HC-SR04 ultrasonic sensor, active buzzer.
#include "distance.h"

const int PING_TRIG_PIN = 12;   // HC-SR04 Trig
const int PING_ECHO_PIN = 10;   // HC-SR04 Echo
const int BUZZER_PIN = 5;       // Buzzer signal
const long ALERT_RANGE_CM = 100;
const unsigned long ECHO_TIMEOUT_US = 30000UL;  // ~5 m; avoids a 1 s stall with no echo

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PING_TRIG_PIN, OUTPUT);
  pinMode(PING_ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(PING_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_TRIG_PIN, HIGH);
  delayMicroseconds(10);  // HC-SR04 datasheet: 10 us trigger pulse
  digitalWrite(PING_TRIG_PIN, LOW);

  long duration = pulseIn(PING_ECHO_PIN, HIGH, ECHO_TIMEOUT_US);
  long cm = microsecondsToCentimeters(duration);

  if (shouldAlert(cm, ALERT_RANGE_CM)) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(10);
  }

  Serial.print(cm);
  Serial.println("cm");
  delay(10);
}
