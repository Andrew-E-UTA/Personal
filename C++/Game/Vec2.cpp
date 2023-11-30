#include "Vec2.h"

Vec2 Vec2::operator + (const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator - (const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}


Vec2 Vec2::operator * (const float& val) const
{
	return Vec2(x * val, y * val);
}

void Vec2::operator += (const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vec2::operator *= (float rhs)
{
	x *= rhs;
	y *= rhs;
}
float Vec2::length() const
{
	return sqrt(x*x + y*y);
}

void Vec2::normalize()
{
	float len = sqrt(x * x + y * y);
	x /= len;
	y /= len;
}

std::ostream& operator << (std::ostream& out, const Vec2& v)
{
	out << "Vector(" << v.x << ", " << v.y << ")" << std::endl;
	return out;
}
//VEC2======================================================================