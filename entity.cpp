
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

bool Entity::IsOnGround(void)
{
	return GetFlags() & FL_ONGROUND;
}
