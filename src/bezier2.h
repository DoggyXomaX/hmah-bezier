#ifndef __HMAH_BEZIER2_H__
#define __HMAH_BEZIER2_H__

#define HMAH_BEZIER2_MAX_POINTS 4

#ifndef uint32_t
  typedef unsigned long uint32_t;
#endif

typedef struct Point2_s {
  double x;
  double y;
} Point2;

typedef struct Bezier2_s {
  Point2 points[HMAH_BEZIER2_MAX_POINTS * 2];
  uint32_t pointsCount;
} Bezier2;

typedef struct Point2f_s {
  float x;
  float y;
} Point2f;

typedef struct Bezier2f_s {
  Point2f points[HMAH_BEZIER2_MAX_POINTS];
  uint32_t pointsCount;
} Bezier2f;

Bezier2 Bezier2_CreateLinear(double x0, double y0, double x1, double y1);
Bezier2 Bezier2_CreateQuadratic(double x0, double y0, double x1, double y1, double x2, double y2);
Bezier2 Bezier2_CreateCubic(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);
Point2 Bezier2_Get(Bezier2* this, double t);

Bezier2f Bezier2f_CreateLinear(float x0, float y0, float x1, float y1);
Bezier2f Bezier2f_CreateQuadratic(float x0, float y0, float x1, float y1, float x2, float y2);
Bezier2f Bezier2f_CreateCubic(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);
Point2f Bezier2f_Get(Bezier2f* this, float t);

#endif // __HMAH_BEZIER2_H__
