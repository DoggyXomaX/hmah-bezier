#include "bezier_core.h"

double linear(const double t, const double p0, const double p1) {
  return p0 + (p1 - p0) * t;
}

double quadratic(const double t, const double p0, const double p1, const double p2) {
  const double at = 1.0 - t;
  return
    at * at * p0 +
    2.0 * at * t * p1 +
    t * t * p2;
}

double cubic(const double t, const double p0, const double p1, const double p2, const double p3) {
  const double at = 1.0 - t;
  return
    at * at * at * p0 +
    3.0 * at * at * t * p1 +
    3.0 * at * t * t * p2 +
    t * t * t * p3;
}

float linearf(const float t, const float p0, const float p1) {
  return p0 + (p1 - p0) * t;
}

float quadraticf(const float t, const float p0, const float p1, const float p2) {
  const float at = 1.0f - t;
  return
    at * at * p0 +
    2.0f * at * t * p1 +
    t * t * p2;
}

float cubicf(const float t, const float p0, const float p1, const float p2, const float p3) {
  const float at = 1.0f - t;
  return
    at * at * at * p0 +
    3.0f * at * at * t * p1 +
    3.0f * at * t * t * p2 +
    t * t * t * p3;
}
