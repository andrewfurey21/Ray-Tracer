#pragma once

#include "hittable.h"
#include "vec3.h"

class Sphere : public Hittable {
	Sphere() {}
	Sphere(point center, double radius) : center(center), radius(radius) {}

	virtual bool hit(const Ray& r, double tMin, double tMax, hitRecord& rec) const override;

	point center;
	double radius;
};



bool Sphere::hit(const Ray& r, double tMin, double tMax, hitRecord& rec) const {

    //This uses the quadratic formula. Ultimately were checking whether a point on the ray at t
    //is ever touching the surface of the sphere with x^2+y^2+z^2=r^2

    vec3 originToCenter = r.orig - center;
    double a = dot(r.dir, r.dir);
    double b = dot(originToCenter, r.dir);
    double c = dot(originToCenter, originToCenter) - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant < 0) {
        return false;
    }

    double root = (-b - sqrt(discriminant)) / a;
    if (root < tMin || root > tMax) {
        root = (-b - sqrt(discriminant)) / a;

        if (root < tMin || root > tMax) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    
    vec3 outwardNormal = (rec.p - center) / radius;
    rec.setFaceNormal(r, outwardNormal);

   

    return true;
}