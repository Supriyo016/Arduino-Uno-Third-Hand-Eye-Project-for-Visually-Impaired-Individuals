// Pure helpers with no Arduino dependency, so they can be unit-tested on a PC.
#pragma once

// Sound travels about 29 microseconds per centimetre; the echo covers the
// distance twice (out and back).
inline long microsecondsToCentimeters(long microseconds) {
  if (microseconds <= 0) return 0;  // 0 = no echo / timeout
  return microseconds / 29 / 2;
}

// Buzz when an obstacle is detected within the alert range.
inline bool shouldAlert(long cm, long alertRangeCm) {
  return cm > 0 && cm <= alertRangeCm;
}
