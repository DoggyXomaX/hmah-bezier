#include "bezier2.h"

#include "bezier_core.h"

Bezier2 Bezier2_CreateLinear(const double x0, const double y0, const double x1, const double y1) {
  return (Bezier2){
    .points = { x0, y0, x1, y1 },
    .pointsCount = 2,
  };
}

Bezier2 Bezier2_CreateQuadratic(const double x0, const double y0, const double x1, const double y1, const double x2, const double y2) {
  return (Bezier2){
    .points = { x0, y0, x1, y1, x2, y2 },
    .pointsCount = 3,
  };
}


Bezier2 Bezier2_CreateCubic(const double x0, const double y0, const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) {
  return (Bezier2){
    .points = { x0, y0, x1, y1, x2, y2, x3, y3 },
    .pointsCount = 4,
  };
}

Point2 Bezier2_Get(const Bezier2* this, const double t) {
  if (this->pointsCount == 4) {
    return (Point2){
      .x = cubic(t, this->points[0].x, this->points[1].x, this->points[2].x, this->points[3].x),
      .y = cubic(t, this->points[0].y, this->points[1].y, this->points[2].y, this->points[3].y),
    };
  }
  if (this->pointsCount == 3) {
    return (Point2){
      .x = quadratic(t, this->points[0].x, this->points[1].x, this->points[2].x),
      .y = quadratic(t, this->points[0].y, this->points[1].y, this->points[2].y),
    };
  }
  if (this->pointsCount == 2) {
    return (Point2){
      .x = linear(t, this->points[0].x, this->points[1].x),
      .y = linear(t, this->points[0].y, this->points[1].y),
    };
  }
  if (this->pointsCount == 1) {
    return this->points[0];
  }
  return (Point2){ .x = 0, .y = 0 };
}

Bezier2f Bezier2f_CreateLinear(const float x0, const float y0, const float x1, const float y1) {
  return (Bezier2f){
    .points = { x0, y0, x1, y1 },
    .pointsCount = 2,
  };
}

Bezier2f Bezier2f_CreateQuadratic(const float x0, const float y0, const float x1, const float y1, const float x2, const float y2) {
  return (Bezier2f){
    .points = { x0, y0, x1, y1, x2, y2 },
    .pointsCount = 3,
  };
}


Bezier2f Bezier2f_CreateCubic(const float x0, const float y0, const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
  return (Bezier2f){
    .points = { x0, y0, x1, y1, x2, y2, x3, y3 },
    .pointsCount = 4,
  };
}

Point2f Bezier2f_Get(const Bezier2f* this, const float t) {
  if (this->pointsCount == 4) {
    return (Point2f){
      .x = cubicf(t, this->points[0].x, this->points[1].x, this->points[2].x, this->points[3].x),
      .y = cubicf(t, this->points[0].y, this->points[1].y, this->points[2].y, this->points[3].y),
    };
  }
  if (this->pointsCount == 3) {
    return (Point2f){
      .x = quadraticf(t, this->points[0].x, this->points[1].x, this->points[2].x),
      .y = quadraticf(t, this->points[0].y, this->points[1].y, this->points[2].y),
    };
  }
  if (this->pointsCount == 2) {
    return (Point2f){
      .x = linearf(t, this->points[0].x, this->points[1].x),
      .y = linearf(t, this->points[0].y, this->points[1].y),
    };
  }
  if (this->pointsCount == 1) {
    return this->points[0];
  }
  return (Point2f){ .x = 0, .y = 0 };
}
