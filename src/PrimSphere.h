//lucia fuentes //fall 2019 //changed
// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f center, float radius)
		: CPrim(color)
		, m_center(center)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
        float one = ray.dir.dot(ray.dir);
        float two = 2 * ray.dir.dot(ray.org - m_center);
        float three = (ray.org - m_center).dot(ray.org - m_center) - m_radius * m_radius;
        
        float exam = two * two - (4 * one * three);
        if (exam < 0){
            return false;
        }
        
        float tot = ((-two) + sqrt(exam)) / one;
        
        if (tot < Epsilon || tot > ray.t){
            return false;
        }
        
        ray.t = tot;
		
		return true;
	}
	
	
private:
	Vec3f m_center;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

