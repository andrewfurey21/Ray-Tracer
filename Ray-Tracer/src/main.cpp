#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"

color rayColor(const Ray& r) {
    vec3 unitDirection = normal(r.direction());
    double t = 0.5*(unitDirection.y + 1);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}


int main() {

    const double aspectRatio = 16 / 9;
    const int width = 400;
    const int height = static_cast<int>(width / aspectRatio);

    const double max = 255.999;

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

    for (int i = 0; i < height; i++) {
        std::cerr << "Scanlines remaining: " << (height - i) << "\n" << std::flush;
        for (int j = 0; j < width; j++) {
            auto u = double(i) / (width - 1);
            auto v = double(j) / (height - 1);
            Ray r(cameraOrigin, lowerLeftCorner + u * horizontal + v * vertical - cameraOrigin);
            color pixel_color = rayColor(r);
            writeColor(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone render" << std::endl;
    return 0;
}
