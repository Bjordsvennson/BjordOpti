
#ifndef MISC_H
#define MISC_H

class UserCmd;

class Misc
{
public:
	void CreateMove(UserCmd* cmd);
	void Autohop(UserCmd* cmd);
	void Autosync(UserCmd* cmd);
	void Optimize(UserCmd* cmd);
	void Autostrafe(UserCmd* cmd);
};

extern Misc misc;

#endif
