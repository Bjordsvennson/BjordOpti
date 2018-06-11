#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#define DEG2RAD(deg) (deg * (M_PI / 180.f))
#define RAD2DEG(rad) (rad * (180.f / M_PI))

class bmath
{
public:
	void AngleVectors(QAngle& angle, Vector& forward);
	void VectorAngles(QAngle& angle, Vector forward);
	void NormalizeAngles(QAngle& vecAngles);
	float Dot(Vector a, Vector b);
	void clamp(float& value, float low, float high);
	void lerp(float& from, float to, float fract);
};

extern bmath math;