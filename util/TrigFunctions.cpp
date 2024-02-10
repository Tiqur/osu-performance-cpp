#include <math.h>
#include <iostream>
#include "Pos.cpp"

// Convert radians to degrees
float radToDeg(float rad) {
  return rad*(180.0/M_PI);
}

// Convert degrees to radians
float degToRad(float deg) {
  return deg*(M_PI/180.0);
}

// Get the distance between pos1 and pos2
float getDistance(Pos pos1, Pos pos2) {
  return sqrtf32(powf32(pos2.x-pos1.x, 2) + powf32(pos2.y-pos1.y, 2));
}

// Get the angle of B ( between A and C ) since three points create an angle
// Lowercase represents side length
// Uppercase represents angle measure
float getAngleRadOfPos2(Pos pos1, Pos pos2, Pos pos3) {
  float a = getDistance(pos1, pos2);
  float b = getDistance(pos3, pos1);
  float c = getDistance(pos2, pos3);

  // Use law of cosines to get B
  float B = acosf32((powf32(a, 2) + powf32(c, 2) - powf32(b, 2)) / (2 * a * c));

  // Return B in radians
  return B;
}
