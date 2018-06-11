
#ifndef MISC_H
#define MISC_H

#include <Windows.h>

#define KEY_W 0x57
#define KEY_A 0x41
#define KEY_S 0x53
#define KEY_D 0x44

class UserCmd;

class Misc
{
public:
	int MoveMouse(int x, int y);
	void ToggleKey(WORD key, bool toggled);

	void CreateMove(UserCmd* cmd);

	void Autohop(UserCmd* cmd);
	void Autosync(UserCmd* cmd);
	float OptimalStrafeDelta(UserCmd* cmd);
	void Optimize(UserCmd* cmd);
	void Autostrafe(UserCmd* cmd);
	void AutostrafeBackwards(UserCmd* cmd);
	void CircleStrafe(UserCmd* cmd);
};

extern Misc misc;

#endif
