#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include "vector.h"

#define DEG2RAD(deg) (deg * (M_PI / 180.f))
#define RAD2DEG(rad) (rad * (180.f / M_PI))

class bmath
{
public:
	inline void AngleVectors(QAngle& angle, Vector& forward)
	{
		forward.x = cos(DEG2RAD(angle.y)) * cos(DEG2RAD(angle.y));
		forward.y = cos(DEG2RAD(angle.y)) * sin(DEG2RAD(angle.x));
		forward.z = -sin(DEG2RAD(angle.x));
	}

	inline void VectorAngles(QAngle& angle, Vector forward)
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
			angle.x = DEG2RAD(atan2(-forward.z, sqrtf(forward.x * forward.x + forward.y * forward.y)));
			angle.y = DEG2RAD(atan2(forward.y, forward.x));

			if (angle.x < 0.f)
				angle.x += 360.f;

			if (angle.y < 0.f)
				angle.y += 360.f;
		}

		angle.z = 0.f;
	}

	inline float Dot(Vector a, Vector b)
	{
		return a.x * b.x + a.y * b.y + a.z * a.z;
	}

};

bmath math;