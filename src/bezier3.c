#include "bezier3.h"

#include "bezier_core.h"

Bezier3 Bezier3_CreateLinear(const double x0, const double y0, const double z0, const double x1, const double y1, const double z1) {
  return (Bezier3){
    .points = { x0, y0, z0, x1, y1, z1 },
    .pointsCount = 2,
  };
}

Bezier3 Bezier3_CreateQuadratic(const double x0, const double y0, const double z0, const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) {
  return (Bezier3){
    .points = { x0, y0, z0, x1, y1, z1, x2, y2, z2 },
    .pointsCount = 3,
  };
}


Bezier3 Bezier3_CreateCubic(const double x0, const double y0, const double z0, const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3) {
  return (Bezier3){
    .points = { x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3 },
    .pointsCount = 4,
  };
}

Point3 Bezier3_Get(const Bezier3* this, const double t) {
  if (this->pointsCount == 4) {
    return (Point3){
      .x = cubic(t, this->points[0].x, this->points[1].x, this->points[2].x, this->points[3].x),
      .y = cubic(t, this->points[0].y, this->points[1].y, this->points[2].y, this->points[3].y),
      .z = cubic(t, this->points[0].z, this->points[1].z, this->points[2].z, this->points[3].z),
    };
  }
  if (this->pointsCount == 3) {
    return (Point3){
      .x = quadratic(t, this->points[0].x, this->points[1].x, this->points[2].x),
      .y = quadratic(t, this->points[0].y, this->points[1].y, this->points[2].y),
      .z = quadratic(t, this->points[0].z, this->points[1].z, this->points[2].z),
    };
  }
  if (this->pointsCount == 2) {
    return (Point3){
      .x = linear(t, this->points[0].x, this->points[1].x),
      .y = linear(t, this->points[0].y, this->points[1].y),
      .z = linear(t, this->points[0].z, this->points[1].z),
    };
  }
  if (this->pointsCount == 1) {
    return this->points[0];
  }
  return (Point3){ .x = 0, .y = 0, .z = 0 };
}

Bezier3f Bezier3f_CreateLinear(const float x0, const float y0, const float z0, const float x1, const float y1, const float z1) {
  return (Bezier3f){
    .points = { x0, y0, z0, x1, y1, z1 },
    .pointsCount = 2,
  };
}

Bezier3f Bezier3f_CreateQuadratic(const float x0, const float y0, const float z0, const float x1, const float y1, const float z1, const float x2, const float y2, const float z2) {
  return (Bezier3f){
    .points = { x0, y0, z0, x1, y1, z1, x2, y2, z2 },
    .pointsCount = 3,
  };
}


Bezier3f Bezier3f_CreateCubic(const float x0, const float y0, const float z0, const float x1, const float y1, const float z1, const float x2, const float y2, const float z2, const float x3, const float y3, const float z3) {
  return (Bezier3f){
    .points = { x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3 },
    .pointsCount = 4,
  };
}

Point3f Bezier3f_Get(const Bezier3f* this, const float t) {
  if (this->pointsCount == 4) {
    return (Point3f){
      .x = cubic(t, this->points[0].x, this->points[1].x, this->points[2].x, this->points[3].x),
      .y = cubic(t, this->points[0].y, this->points[1].y, this->points[2].y, this->points[3].y),
      .z = cubic(t, this->points[0].z, this->points[1].z, this->points[2].z, this->points[3].z),
    };
  }
  if (this->pointsCount == 3) {
    return (Point3f){
      .x = quadratic(t, this->points[0].x, this->points[1].x, this->points[2].x),
      .y = quadratic(t, this->points[0].y, this->points[1].y, this->points[2].y),
      .z = quadratic(t, this->points[0].z, this->points[1].z, this->points[2].z),
    };
  }
  if (this->pointsCount == 2) {
    return (Point3f){
      .x = linear(t, this->points[0].x, this->points[1].x),
      .y = linear(t, this->points[0].y, this->points[1].y),
      .z = linear(t, this->points[0].z, this->points[1].z),
    };
  }
  if (this->pointsCount == 1) {
    return this->points[0];
  }
  return (Point3f){ .x = 0, .y = 0, .z = 0 };
}
