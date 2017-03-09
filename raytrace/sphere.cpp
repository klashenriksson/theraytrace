#include "geometry.h"

bool Sphere::intersects(const Ray& ray, float& t) const
{
	vec3f L = (center - ray.pos);
	float tca = L.dot(ray.dir);

	if (tca < 0)
		return false;

	//L^2 + d^2 = tca
	//d^2 = tca - l^2
	//d = sqrt(tca - l^2)
	float d2 = L.length() - tca * tca;
	if (d2 > radius2())
		return false;

	float thc = sqrt(radius2() - d2);

	float t0 = tca - thc;
	float t1 = tca + thc;

	if (t0 > t1)
		std::swap(t0, t1);

	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return false;
	}

	t = t0;

	return true;
}

float Sphere::radius2() const 
{
	return radius*radius;
}