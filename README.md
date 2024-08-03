# hmah-bezier

Simple and lightweight bezier curve library

## Requirements

1. ![CMake 3.14^](https://img.shields.io/badge/CMake-3.14^-green?logo=cmake)

2. ![GCC](https://img.shields.io/badge/GCC-blue) or ![MSVC](https://img.shields.io/badge/MSVC-purple) compiler

## Build

```shell
cd <hmah-bezier-directory>
mkdir build
cd build
cmake -S .. -B .
cmake --build .
# Output will be libhmahbezier.so or libhmahbezier.a or hmahbezier.dll
```

### CMake flags
* `HMAH_BEZIER_SHARED` build shared lib (.so) (default: OFF)
* `HMAH_BEZIER_STATIC` build static lib (.a) (default: ON)
* `HMAH_BEZIER_INCLUDE_BEZIER2` include Bezier2 class in library (default: ON)
* `HMAH_BEZIER_INCLUDE_BEZIER3` include Bezier3 class in library (default: ON)


## Usage
This lib contains core definition of the bezier math in 2 precisions: `float` and `double` (F32/F64)

Also there are two classes: `Bezier2` (x, y) and `Bezier3` (x, y, z)

### Core
```c++
/* Works as basic lerp (linear interpolation) */
double linear(double t, double p0, double p1);

/* Interpolate quadratic bezier component (x, y or z) by 3 values (from, control, to) */
double quadratic(double t, double p0, double p1, double p2);

/* Interpolate cubic bezier component (x, y or z) by 4 values (from, control1, control2, to) */
double cubic(double t, double p0, double p1, double p2, double p3);

// Float version
float linearf(float t, float p0, float p1);
float quadraticf(float t, float p0, float p1, float p2);
float cubicf(float t, float p0, float p1, float p2, float p3);
```

### Bezier2
```c++
/* Point and bezier representations */
typedef struct Point2_s { double x; double y; } Point2;
typedef struct Bezier2_s {
  Point2 points[4];
  uint32_t pointsCount;
} Bezier2;

/* Creation methods */
Bezier2 Bezier2_CreateLinear(double x0, double y0, double x1, double y1);
Bezier2 Bezier2_CreateQuadratic(double x0, double y0, double x1, double y1, double x2, double y2);
Bezier2 Bezier2_CreateCubic(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);

/* Interpolation by t */
Point2 Bezier2_Get(const Bezier2* this, double t);

// Float version
typedef struct Point2f_s { float x; float y; } Point2f;
typedef struct Bezier2f_s {
  Point2f points[HMAH_BEZIER2_MAX_POINTS];
  uint32_t pointsCount;
} Bezier2f;

Bezier2f Bezier2f_CreateLinear(float x0, float y0, float x1, float y1);
Bezier2f Bezier2f_CreateQuadratic(float x0, float y0, float x1, float y1, float x2, float y2);
Bezier2f Bezier2f_CreateCubic(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);

Point2f Bezier2f_Get(const Bezier2f* this, float t);
```

### Bezier3
```c++
/* Point and bezier representations */
typedef struct Point3_s { double x; double y; double z; } Point3;
typedef struct Bezier3_s {
  Point3 points[HMAH_BEZIER3_MAX_POINTS];
  uint32_t pointsCount;
} Bezier3;

/* Creation methods */
Bezier3 Bezier3_CreateLinear(double x0, double y0, double z0, double x1, double y1, double z1);
Bezier3 Bezier3_CreateQuadratic(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
Bezier3 Bezier3_CreateCubic(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);

/* Interpolation by t */
Point3 Bezier3_Get(const Bezier3* this, double t);

// Float version
typedef struct Point3f_s { float x; float y; float z; } Point3f;
typedef struct Bezier3f_s {
  Point3f points[HMAH_BEZIER3_MAX_POINTS];
  uint32_t pointsCount;
} Bezier3f;

Bezier3f Bezier3f_CreateLinear(float x0, float y0, float z0, float x1, float y1, float z1);
Bezier3f Bezier3f_CreateQuadratic(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
Bezier3f Bezier3f_CreateCubic(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);

Point3f Bezier3f_Get(const Bezier3f* this, float t);
```

## Example
```c++
#include "bezier2.h"

#define PCOUNT 20

int main(int argc, char* argv[]) {
    const Bezier2f curve = Bezier2f_CreateCubic(0, 0, 100, 100, 200, 100, 300, 0);
    const float dt = 1.0 / (float)(PCOUNT - 1);
    for (float t = 0.0; t <= 1.0; t += dt) {
        const Point2f point = Bezier2f_Get(&curve, t);
        printf("x = %.2f y = %.2f\n", point.x, point.y);
    }
}
```

## License
MIT
