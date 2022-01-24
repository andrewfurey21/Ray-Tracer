#include <iostream>
#include "includes.h"
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "hittableList.h"


const double infinity = std::numeric_limits<double>::infinity();


color rayColor(const Ray& r, const Hittable& world) {
    hitRecord record;
    if (world.hit(r, 0, infinity, record)) {
        return 0.5 * (record.normal + color(1, 1, 1));
    }
    vec3 unit = normalize(r.direction());
    double t = 0.5 * (unit.y + 1.0);
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

    //World
    HittableList world;
    world.add(make_shared<Sphere>(point(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(point(0, -100.5, -1), 100));

    std::cout << "P3 ";
    std::cout << width << " " << height << " ";
    std::cout << 255 << "\n";

    for (int i = height-1; i >= 0; i--) {
        std::cerr << "Scanlines remaining: " << (i) << "\n" << std::flush;
        for (int j = 0; j < width; j++) {
            double u = double(j) / (width - 1.0);
            double v = double(i) / (height - 1.0);
            Ray r(cameraOrigin, lowerLeftCorner + u * horizontal + v * vertical - cameraOrigin);
            color pixelColor = rayColor(r, world);
            writeColor(std::cout, pixelColor);
        }
    }
    std::cerr << "\nDone render" << std::endl;
    return 0;
}
