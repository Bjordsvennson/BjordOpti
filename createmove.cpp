#include <stdio.h>
#include "createmove.h"
#include "usercmd.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "settings.h"
#include "misc.h"

CreateMoveFn oCreateMove;

bool __fastcall hkCreateMove(void* self, void*, float flInputSampleTime, UserCmd* cmd)
{
	Entity* local = engine->GetLocal();

	if (!local || !cmd || cmd && !cmd->command_number)
		return false;

	misc.CreateMove(cmd);

	oCreateMove(self, flInputSampleTime, cmd);

	return false;
}
