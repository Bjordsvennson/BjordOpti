
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector
{
public:
	float x, y, z;

	Vector(float _x, float _y, float _z) { Init(_x, _y, _z); }
	Vector(float _xyz) { Init(_xyz); }
	Vector(void) { Zero(); }
	
	void Init(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
	void Init(float _xyz = 0.f) { x = y = z = _xyz; }
	
	float* Base(void) { return (float*)this; }
	float Length(void) { return (float)sqrt((double)(x * x + y * y + z * z)); }
	float Length2D(void) { return (float)sqrt((double)(x * x + y * y)); }

	void Normalize(void) 
	{
		float length = (float)sqrt((double)(x * x + y * y + z * z));
		x /= length;
		y /= length;
		z /= length;
	}
	
	void Zero(void) { x = y = z = 0.f; }
	bool IsZero(void) { return x == 0.f && y == 0.f && z == 0.f; }
			    
	bool operator==(const Vector& other) { return x == other.x && y == other.y && z == other.z; }
	bool operator!=(const Vector& other) { return x != other.x || y != other.y || z != other.z; }
	Vector& operator-(void) { return Vector(-x, -y, -z); }
	Vector& operator-(const Vector& other) { return Vector(x - other.x, y - other.y, z - other.z); }
	Vector& operator*(float f) { return Vector(x * f, y * f, z * f); }
	Vector& operator*(const Vector& other) { return Vector(x * other.x, y * other.y, z * other.z); }
	Vector& operator/(float f) { return Vector(x / f, y / f, z / f); }
	Vector& operator/(const Vector& other) { return Vector(x / other.x, y / other.y, z / other.z); }
	float& operator[](int i) { return ((float*)this)[i]; }

	Vector& operator+(Vector& v)
	{
		Vector res;
		res.x = x + v.x;
		res.y = y + v.y;
		res.z = z + v.z;

		return res;
	};
};

typedef Vector QAngle;

typedef float matrix3x4_t[3][4];

#endif
