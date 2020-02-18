#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D& v2) const
{
	return Vector2D(x + v2.x, y + v2.y);
}
Vector2D& Vector2D::operator +=(const Vector2D& v2)
{
	x += v2.x;
	y += v2.y;
	return *this;
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(x * scalar, y * scalar);
}
Vector2D& Vector2D::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
	return Vector2D(x - v2.x, y - v2.y);
}
Vector2D& Vector2D::operator-=(const Vector2D& v2)
{
	x -= v2.x;
	y -= v2.y;
	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(x / scalar, y / scalar);
}
Vector2D& Vector2D::operator/=(float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

float Vector2D::length() { return sqrt(x * x + y * y); }

Vector2D* Vector2D::normalize()
{
	float l = length();
	if (l > 0) // we never want to attempt to divide by 0
	{
		return  &(((*this) * 1) / l);
	}
}