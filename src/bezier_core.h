#ifndef __HMAH_BEZIER_CORE_H__
#define __HMAH_BEZIER_CORE_H__

double linear(double t, double p0, double p1);
double quadratic(double t, double p0, double p1, double p2);
double cubic(double t, double p0, double p1, double p2, double p3);

float linearf(float t, float p0, float p1);
float quadraticf(float t, float p0, float p1, float p2);
float cubicf(float t, float p0, float p1, float p2, float p3);

#endif // __HMAH_BEZIER_CORE_H__