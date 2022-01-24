#pragma once

#include "ray.h"

struct hitRecord {
	point p;
	vec3 normal;
	double t;

	bool frontFace;

	//sign of dot product tells us whether the ray is facing away or not from normal
	inline void setFaceNormal(const Ray& r, const vec3& outwardNormal) {
		frontFace = dot(r.direction(), outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

//Abstract hittable class that is used to check whether the derived class has been hit
class Hittable {
public:
	virtual bool hit(const Ray& r, double tMin, double tMax, hitRecord& rec) const = 0;
};