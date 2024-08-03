#ifndef __HMAH_BEZIER3_H_
#define __HMAH_BEZIER3_H_

#define HMAH_BEZIER3_MAX_POINTS 4

#ifndef uint32_t
  typedef unsigned long uint32_t;
#endif

typedef struct Point3_s {
  double x;
  double y;
  double z;
} Point3;

typedef struct Bezier3_s {
  Point3 points[HMAH_BEZIER3_MAX_POINTS * 2];
  uint32_t pointsCount;
} Bezier3;

typedef struct Point3f_s {
  float x;
  float y;
  float z;
} Point3f;

typedef struct Bezier3f_s {
  Point3f points[HMAH_BEZIER3_MAX_POINTS];
  uint32_t pointsCount;
} Bezier3f;

Bezier3 Bezier3_CreateLinear(double x0, double y0, double z0, double x1, double y1, double z1);
Bezier3 Bezier3_CreateQuadratic(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
Bezier3 Bezier3_CreateCubic(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
Point3 Bezier3_Get(Bezier3* this, double t);

Bezier3f Bezier3f_CreateLinear(float x0, float y0, float z0, float x1, float y1, float z1);
Bezier3f Bezier3f_CreateQuadratic(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
Bezier3f Bezier3f_CreateCubic(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
Point3f Bezier3f_Get(Bezier3f* this, float t);

#endif // __HMAH_BEZIER3_H_