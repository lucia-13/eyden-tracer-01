//lucia fuentes//fall 2019 //changed

// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(Vec3f origin, Vec3f normal)
		: CPrim()
		, m_normal(normal)
		, m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;

	virtual bool Intersect(Ray& ray) override
	{
        float num = m_normal.dot(m_origin - ray.org);
        float den = m_normal.dot(ray.dir);
        float tot;
        
        if (den == 0){
            return 0;
        }
        else{
            tot = num / den;
        }
        
        if (tot < Epsilon || tot > ray.t){
            return false;
        }
        
        ray.t = tot;
		return true;
	}
	
	
private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
