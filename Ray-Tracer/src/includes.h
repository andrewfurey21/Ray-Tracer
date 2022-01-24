#define PI 3.1415926535897932385

#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::vector;


inline double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

#endif