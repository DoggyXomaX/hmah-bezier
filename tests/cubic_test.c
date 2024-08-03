#include "bezier2.h"
#include "test_plot.h"

#include <stdio.h>

#define PCOUNT 10

int main() {
  printf("Cubic bezier test with %d points\n", PCOUNT);

  const Bezier2f curve = Bezier2f_CreateCubic(0, 0, 20, 20, 20, 0, 40, 0);
  const float dt = 1.0f / (float)PCOUNT;

  Point2f points[PCOUNT];

  float t = 0.0f;
  for (int i = 0; i < PCOUNT; i++, t += dt)
    points[i] = Bezier2f_Get(&curve, t);

  plot2Df((const float*)points, PCOUNT);
}
