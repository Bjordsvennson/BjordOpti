#include <stdio.h>
#include "createmove.h"
#include "usercmd.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "settings.h"
#include "misc.h"
#include "math.h"

CreateMoveFn oCreateMove;

bool __fastcall hkCreateMove(void* self, void*, float flInputSampleTime, UserCmd* cmd)
{

	Entity* local = engine->GetLocal();

	if (!local || !cmd || cmd && !cmd->command_number)
		return false;

	settings.InputListener();

	misc.CreateMove(cmd);

	clamp_movement(cmd);

	oCreateMove(self, flInputSampleTime, cmd);
	return false;
}

void clamp_movement(UserCmd* cmd)
{
	math.clamp(cmd->forwardmove, -450.f, 450.f);
	math.clamp(cmd->sidemove, -450.f, 450.f);
}
