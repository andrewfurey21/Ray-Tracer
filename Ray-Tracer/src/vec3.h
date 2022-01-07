#pragma once

#include <cmath>
#include <iostream>
#include <stdio.h>

using std::sqrt;

class vec3 {
public:
	double x, y, z;
	vec3() : x(0), y(0), z(0) {}
	vec3(double y, double x, double z) : x(x), y(y), z(z) {}
	void print() { printf("y: %f, y: %f, z: %f\n", x, y, z); }

	vec3 operator-() const {
		return vec3(-x, -y, -z);
	}

	void add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void operator+=(const vec3& other) {
		add(other);
	}

	void mult(const double m) {
		x *= m;
		y *= m;
		z *= m;
	}

	void operator*=(const double m) {
		mult(m);
	}

	void div(const double m) {
		x /= m;
		y /= m;
		z /= m;
	}

	void operator/=(const double m) {
		div(m);
	}

	double magnitudeSquared() const {
		return (x * x + y * y + z * z);
	}

	double magnitude() const {
		return sqrt(magnitudeSquared());
	}

};

using point = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream& out, vec3& vector) {
	return out << vector.x << " " << vector.y << " " << vector.z << "\n";
}



inline double dot(const vec3& u, const vec3& v) {
	return u.x * v.x
		+ u.y * v.y
		+ u.z * v.z;
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x);
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.x, t * v.y, t * v.z);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

inline vec3 normal(vec3 vector) {
	return vector / vector.magnitude();
}

inline void writeColor(std::ostream& out, color c) {
	out << static_cast<int>(255.999 * c.x) << " " << static_cast<int>(255.999 * c.y) << " " << static_cast<int>(255.999 * c.z) << "\n";
}




