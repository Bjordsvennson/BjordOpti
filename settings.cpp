
#include "settings.h"
#include "windows.h"

#include <stdio.h>

void Settings::Init()
{
	settings.home_down = false;
	settings.prior_down = false;
	settings.next_down = false;

	settings.m_bAutohop = false;
	settings.m_bAutostrafe = false;
	settings.m_bOptimize = false;
}

void Settings::ToggleSetting(bool& setting)
{
	setting = !setting;
}

bool Settings::KeyDown(int key, bool& key_last_down)
{
	if (GetAsyncKeyState(key) && !key_last_down)
	{
		key_last_down = true;
		return true;
	}
	else if (!GetAsyncKeyState(key) && key_last_down)
	{
		key_last_down = false;
		return false;
	}
	return false;
}

void Settings::InputListener()
{
	if (KeyDown(VK_HOME, home_down))
	{
		ToggleSetting(settings.m_bAutohop);
	}
	
	if (KeyDown(VK_PRIOR, prior_down))
	{
		ToggleSetting(settings.m_bAutostrafe);
	}
	
	if (KeyDown(VK_NEXT, next_down))
	{
		ToggleSetting(settings.m_bOptimize);
	}
}

Settings settings;