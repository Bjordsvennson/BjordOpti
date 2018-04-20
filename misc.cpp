
#include <stdio.h>
#include "misc.h"
#include "usercmd.h"
#include "settings.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "globals.h"

#include "offsets.h"

void Misc::CreateMove(UserCmd* cmd)
{
	Entity* local = engine->GetLocal();

	if (settings.m_bAutohop && (cmd->buttons & IN_JUMP) && !local->IsOnGround())
	{
		cmd->buttons &= ~IN_JUMP;

		//if (cmd->mousedx > 1 || cmd->mousedx < -1) {
		//	cmd->sidemove = cmd->mousedx < 0.f ? -450.f : 450.f;
	}
}

Misc misc;
