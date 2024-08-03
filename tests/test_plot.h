#ifndef __HMAH_BEZIER_TEST_PLOT_H__
#define __HMAH_BEZIER_TEST_PLOT_H__

#include <stdio.h>
#include <stddef.h>

#define PLOT_FILL '#'
#define PLOT_SPACE '.'
#define PLOT_WIDTH 40
#define PLOT_HEIGHT 20

float absf(const float v) {
  return v < 0.0f ? -v : v;
}

void plot2Df(const float* points, const size_t pointsCount) {
  char canvas[PLOT_HEIGHT][PLOT_WIDTH];
  for (int y = 0; y < PLOT_HEIGHT; y++)
    for (int x = 0; x < PLOT_WIDTH; x++)
      canvas[y][x] = PLOT_SPACE;

  for (size_t i = 0; i < pointsCount; i++) {
    const int x = (int)points[i * 2 + 0];
    const int y = (int)points[i * 2 + 1];
    if (x < 0 || x >= PLOT_WIDTH || y < 0 || y >= PLOT_HEIGHT) continue;
    canvas[y][x] = PLOT_FILL;
  }

  printf("Plot %dx%d\n", PLOT_WIDTH, PLOT_HEIGHT);
  for (int y = 0; y < PLOT_HEIGHT; y++) {
    for (int x = 0; x < PLOT_WIDTH; x++) {
      putchar(canvas[y][x]);
    }
    putchar('\n');
  }
}

#endif // __HMAH_BEZIER_TEST_PLOT_H__
