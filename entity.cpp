
#include "vector.h"
#include "entity.h"
#include "engine.h"
#include "vmt.h"
#include "offsets.h"

int Entity::entindex(void)
{
	return *(int*)(this + 0x64);
}

int Entity::GetFlags(void)
{
	return *(int*)(this + offsets.m_fFlags);
}

Vector Entity::GetVelocity()
{
	return *(Vector*)(this + offsets.m_vecVelocity);
}

bool Entity::IsOnGround(void)
{
	return GetFlags() & FL_ONGROUND;
}
