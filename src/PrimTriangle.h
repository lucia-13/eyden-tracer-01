//lucia Fuentes //fall 2019//changed
// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
		: CPrim()
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool Intersect(Ray& ray) override
	{
        Vec3f a = (m_b - ray.org).cross(m_a - ray.org);
        Vec3f b = (m_c - ray.org).cross(m_b - ray.org);
        Vec3f c = (m_a - ray.org).cross(m_c - ray.org);
        
        float area = a.dot(ray.dir) + b.dot(ray.dir) + c.dot(ray.dir);
        float lam1 = a.dot(ray.dir) / area;
        float lam2 = b.dot(ray.dir) / area;
        float lam3 = c.dot(ray.dir) / area;
        
        if (lam1 < 0 || lam2 < 0 || lam3 < 0){
            return false;
        }
        
        Vec3f p = lam1 * m_a + lam2 * m_b + lam3 * m_c;
        
        float tot = p[0] / ray.dir[0];
        if (tot < Epsilon || tot > ray.t){
            return false;
        }
        
        ray.t = tot;
		return true;
	}

	
private:
	Vec3f m_a;	///< Position of the first vertex
	Vec3f m_b;	///< Position of the second vertex
	Vec3f m_c;	///< Position of the third vertex
};
