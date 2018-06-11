
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "vmt.h"

int Engine::GetLocalPlayer(void)
{
	typedef int(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 12))(this);
}

Entity* Engine::GetLocal()
{
	return entitylist->GetEntity(engine->GetLocalPlayer());
}

void Engine::GetViewAngles(QAngle& va)
{
	typedef void(__thiscall* Fn)(void*, QAngle&);
	return ((Fn)vmt.GetVirtual(this, 19))(this, va);
}

void Engine::SetViewAngles(QAngle& va)
{
	typedef void(__thiscall* Fn)(void*, QAngle&);
	return ((Fn)vmt.GetVirtual(this, 20))(this, va);
}

bool Engine::IsInGame(void)
{
	typedef bool(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 26))(this);
}

const matrix3x4_t& Engine::WorldToScreenMatrix(void)
{
	typedef const matrix3x4_t&(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 37))(this);
}

Engine* engine = 0;
