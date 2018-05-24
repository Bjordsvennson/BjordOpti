
#include <stdio.h>
#include <windows.h> // for getasynckeystate
#include <cmath>

#include "misc.h"
#include "usercmd.h"
#include "settings.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "globals.h"
#include "math.h"

#include "offsets.h"

void Misc::CreateMove(UserCmd* cmd)
{
	if (cmd->buttons & IN_JUMP)
	{
		Autohop(cmd);
		//Autosync(cmd);
		Autostrafe(cmd);
		//Optimize(cmd);
	}
}

void Misc::Autohop(UserCmd* cmd)
{
	Entity* local = engine->GetLocal();

	if (settings.m_bAutohop && !local->IsOnGround())
	{
		cmd->buttons ^= IN_JUMP;
	}
}

void Misc::Autosync(UserCmd* cmd)
{
	if (cmd->mousedx > 1 || cmd->mousedx < -1)
	{
		cmd->sidemove = cmd->mousedx < 0.f ? -450.f : 450.f;
	}	
}

void Misc::Optimize(UserCmd* cmd)
{

}

void Misc::Autostrafe(UserCmd* cmd)
{
	Entity* local = engine->GetLocal();

	if (local->IsOnGround())
	{
		cmd->forwardmove = 400.f;
	}
	else 
	{
		if (cmd->mousedx > 1 || cmd->mousedx < -1) 
		{
			if (cmd->mousedx < 0.f)
			{
				cmd->sidemove = -400.f;
			}
			else
			{
				cmd->sidemove = 400.f;
			}
		}
		else
		{
			cmd->forwardmove = 5850.f / local->GetVelocity().Length2D();

			if (globals->tickcount % 2 == 0)
			{
				cmd->sidemove = -400.f;
			}
			else
			{
				cmd->sidemove = 400.f;
			}
		}
	}
}

Misc misc;