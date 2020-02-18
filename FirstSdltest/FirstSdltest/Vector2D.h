#pragma once
#include<math.h>
class Vector2D
{
public:
	Vector2D(float x, float y) :x(x), y(y) {}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float _x) { x = _x; }
	void setY(float _y) { y = _y; }
	Vector2D operator+(const Vector2D& v2) const;
	Vector2D& operator+=(const Vector2D& v2);
	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);
	Vector2D operator-(const Vector2D& v2) const;
	Vector2D& operator-=(const Vector2D& v2);
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);
	Vector2D* normalize();
	float length();
	float x;
	float y;
private:
	
};





