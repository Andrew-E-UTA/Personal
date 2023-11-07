#pragma once
#include <iostream>
#include <cmath>

class Vec2
{
public:
	float x = 0, y = 0;

	Vec2() {}

	Vec2(float xin, float yin)
		:x(xin), y(yin) {}
	Vec2(const Vec2& inst)
		:x(inst.x), y(inst.y) {}

	Vec2 operator + (const Vec2& rhs) const;
	Vec2 operator - (const Vec2& rhs) const;
	Vec2 operator * (const float& val) const;
	void operator += (const Vec2& rhs);
	void operator *= (const float rhs);
	void normalize();
	float length() const; 
};
