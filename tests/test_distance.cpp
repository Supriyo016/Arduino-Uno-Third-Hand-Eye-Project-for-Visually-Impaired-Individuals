#include <cassert>
#include <cstdio>
#include "../firmware/third_hand_eye/distance.h"

int main() {
  assert(microsecondsToCentimeters(0) == 0);
  assert(microsecondsToCentimeters(-5) == 0);
  assert(microsecondsToCentimeters(58) == 1);
  assert(microsecondsToCentimeters(5800) == 100);
  assert(microsecondsToCentimeters(29000) == 500);

  assert(!shouldAlert(0, 100));    // timeout / no echo
  assert(shouldAlert(1, 100));
  assert(shouldAlert(100, 100));
  assert(!shouldAlert(101, 100));
  std::puts("all distance tests passed");
  return 0;
}
