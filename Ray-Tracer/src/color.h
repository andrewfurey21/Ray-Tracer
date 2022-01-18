#pragma once
#include "vec3.h"


inline void writeColor(std::ostream& out, color c) {
	out << static_cast<int>(255.999 * c.x) << " " 
		<< static_cast<int>(255.999 * c.y) << " " 
		<< static_cast<int>(255.999 * c.z) << "\n";
}