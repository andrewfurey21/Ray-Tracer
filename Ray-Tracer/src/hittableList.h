#pragma once
#include "includes.h"
#include "hittable.h"


class HittableList : public Hittable {
public:
	HittableList() {}
	HittableList(shared_ptr<Hittable> hittable) {};

	bool hit(const Ray& r, double tMin, double tMax, hitRecord& rec) const override;
	void clear() { hittables.clear(); }
	void add(shared_ptr<Hittable> hittable) { hittables.emplace_back(hittable); }

	vector<shared_ptr<Hittable>> hittables;
};

inline bool HittableList::hit(const Ray& r, double tMin, double tMax, hitRecord& rec) const {
	hitRecord tempRecord;
	bool hitSomething = false;
	double closest = tMax;

	for (const auto& object : hittables) {
		if (object->hit(r, tMin, closest, tempRecord)) {
			closest = rec.t;
			hitSomething = true;
			rec = tempRecord;
		}
	}

	return hitSomething;
}