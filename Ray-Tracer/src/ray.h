#pragma once
#include "vec3.h"
#include "color.h"

class Ray {
public:
	Ray() {}
	Ray(point& origin, vec3 direction) : orig(origin), dir(direction) {}

	point at(double t) const {
		return orig + t * dir;
	}

	point origin() const { return orig; }
	point direction() const { return dir; }

private:

	point orig;
	vec3 dir;


};