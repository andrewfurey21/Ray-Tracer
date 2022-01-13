#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


double hitSphere(const point& center, double radius, const Ray& r) {
    vec3 originToCenter = r.orig - center;
    double a = dot(r.dir, r.dir);
    double b = dot(originToCenter, r.dir);
    double c = dot(originToCenter, originToCenter) - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant)) / a;
    }
}

color rayColor(const Ray& r) {
    double t = hitSphere(point(0, 0, -1), 0.5, r);
    if (t > 0.0) {
        vec3 n = normalize(r.at(t) - point(0, 0, -1));
        return (color(n.x + 1, n.y + 1, n.z + 1) * .5);
    }
    vec3 unitDirection = normalize(r.direction());
    t =  (unitDirection.y+1);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}



int main() {

    const double aspectRatio = 16.0 / 9.0;
    const int width = 400;
    const int height = static_cast<int>(width / aspectRatio);

    std::cerr << width << " " << height << "\n";

    //Camera stuff
    double viewportHeight = 2.0;
    double viewportWidth = aspectRatio * viewportHeight;
    double focalLength = 1.0;

    point cameraOrigin = point();
    vec3 horizontal = vec3(viewportWidth, 0, 0);
    vec3 vertical = vec3(0, viewportHeight, 0);
    point lowerLeftCorner = cameraOrigin - horizontal / 2 - vertical / 2 - vec3(0, 0, focalLength);

    std::cout << "P3 ";
    std::cout << width << " " << height << " ";
    std::cout << 255 << "\n";

    for (int i = height-1; i >= 0; i--) {
        std::cerr << "Scanlines remaining: " << (i) << "\n" << std::flush;
        for (int j = 0; j < width; j++) {
            double u = double(j) / (width - 1.0);
            double v = double(i) / (height - 1.0);
            Ray r(cameraOrigin, lowerLeftCorner + u * horizontal + v * vertical - cameraOrigin);
            color pixelColor = rayColor(r);
            writeColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone render" << std::endl;
    return 0;
}
