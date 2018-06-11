#include <stdio.h>

#include "misc.h"
#include "usercmd.h"
#include "settings.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "globals.h"
#include "math.h"

#include "offsets.h"

Vector strafe_view(0, 0, 0);

void Misc::CreateMove(UserCmd* cmd)
{
	Optimize(cmd);

	if (cmd->buttons & IN_JUMP)
	{
		Autohop(cmd);
		//Autosync(cmd);
		Autostrafe(cmd);
		//AutostrafeBackwards(cmd);
	}
}

void Misc::Autohop(UserCmd* cmd)
{
	if (!settings.m_bAutohop)
		return;

	Entity* local = engine->GetLocal();

	if (!local->IsOnGround())
	{
		cmd->buttons ^= IN_JUMP;
	}
}

void Misc::Autosync(UserCmd* cmd)
{
	if (cmd->mousedx < 0.f)
	{
		cmd->sidemove = -450.f;
	}
	else if (cmd->mousedx > 0.f)
	{
		cmd->sidemove = 450.f;
	}
}

float Misc::OptimalStrafeDelta(UserCmd* cmd)
{
	Entity* local = engine->GetLocal();
	float speed = local->GetVelocity().Length2D();
	return (float)RAD2DEG(atan((double)(30.f / speed)));
}

void Misc::Optimize(UserCmd* cmd)
{
	if (!settings.m_bOptimize)
		return;

	Entity* local = engine->GetLocal();

	if (strafe_view.IsZero())
	{
		strafe_view = cmd->viewangles;
	}

	float perfect_delta = OptimalStrafeDelta(cmd);
	float input_delta = (float)(cmd->mousedx * -0.044);

	if ((cmd->buttons & IN_JUMP) && !local->IsOnGround())
	{
		if (cmd->mousedx < 0.f)
		{
			cmd->sidemove = -450.f;
			input_delta = perfect_delta;
		}
		else if (cmd->mousedx > 0.f)
		{
			cmd->sidemove = 450.f;
			input_delta = -perfect_delta;
		}
	}

	strafe_view = strafe_view + QAngle((float)(cmd->mousedy * 0.044), input_delta, 0.f);

	//math.clamp(strafe_view.x, -89.f, 89.f);

	engine->SetViewAngles(strafe_view);
	cmd->viewangles = strafe_view;
}

void Misc::Autostrafe(UserCmd* cmd)
{
	if (!settings.m_bAutostrafe)
		return;

	Entity* local = engine->GetLocal();

	float perfect_delta = OptimalStrafeDelta(cmd);

	if (local->IsOnGround())
	{
		cmd->forwardmove = 450.f;
	}
	else
	{
		if (cmd->mousedx > 1 || cmd->mousedx < -1)
		{
			if (cmd->mousedx < 0.f)
			{
				cmd->sidemove = -450.f;
			}
			else
			{
				cmd->sidemove = 450.f;
			}
		}
		else
		{
			cmd->forwardmove = 6100.f / local->GetVelocity().Length2D();

			if (globals->tickcount % 2 == 0)
			{
				cmd->sidemove = -450.f;
			}
			else
			{
				cmd->sidemove = 450.f;
			}
		}
	}
}

void Misc::AutostrafeBackwards(UserCmd * cmd)
{
	Entity* local = engine->GetLocal();

	if (local->IsOnGround())
	{
		cmd->forwardmove = -450.f;
	}
	else
	{
		if (cmd->mousedx > 1 || cmd->mousedx < -1)
		{
			if (cmd->mousedx < 0.f)
			{
				cmd->sidemove = 450.f;
			}
			else
			{
				cmd->sidemove = -450.f;
			}
		}
		else
		{
			cmd->forwardmove = -6100.f / local->GetVelocity().Length2D();

			if (globals->tickcount % 2 == 0)
			{
				cmd->sidemove = 450.f;
			}
			else
			{
				cmd->sidemove = -450.f;
			}
		}
	}
}

Misc misc;