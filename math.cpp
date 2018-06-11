
#include <cmath>
#include "vector.h"
#include "math.h"

void bmath::AngleVectors(QAngle & angle, Vector & forward)
{
	forward.x = (float)(cos(DEG2RAD(angle.y)) * cos(DEG2RAD(angle.y)));
	forward.y = (float)(cos(DEG2RAD(angle.y)) * sin(DEG2RAD(angle.x)));
	forward.z = (float)(-sin(DEG2RAD(angle.x)));
}

void bmath::VectorAngles(QAngle & angle, Vector forward)
{
	if (forward.x == 0 && forward.y == 0)
	{
		if (forward.z > 0.f)
			angle.x = 270.f;
		else
			angle.x = 90.f;

		angle.y = 0.f;
	}
	else
	{
		angle.x = (float)(DEG2RAD(atan2(-forward.z, sqrtf(forward.x * forward.x + forward.y * forward.y))));
		angle.y = (float)(DEG2RAD(atan2(forward.y, forward.x)));

		if (angle.x < 0.f)
			angle.x += 360.f;

		if (angle.y < 0.f)
			angle.y += 360.f;
	}

	angle.z = 0.f;
}

void bmath::NormalizeAngles(QAngle & vecAngles)
{
	for (int iAxis = 0; iAxis < 3; iAxis++)
	{
		while (vecAngles[iAxis] > 180.f)
			vecAngles[iAxis] -= 360.f;

		while (vecAngles[iAxis] < -180.f)
			vecAngles[iAxis] += 360.f;
	}
}

float bmath::Dot(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y + a.z * a.z;
}

void bmath::clamp(float& value, float low, float high)
{
	if (value > high)
	{
		value = high;
	}
	else if (value < low)
	{
		value = low;
	}

	return;
}

void bmath::lerp(float& from, float to, float fract)
{
	from = (1 - fract) * from + fract * to;
	return;
}

bmath math;