
#ifndef USERCMD_H
#define USERCMD_H

#include "vector.h"

#define IN_JUMP (1 << 1)

class UserCmd
{
private:
	virtual ~UserCmd(void) {}
public:
	int		command_number;
	int		tick_count;
	QAngle	viewangles;
	float	forwardmove;
	float	sidemove;
	float	upmove;
	int		buttons;
	unsigned char    impulse;
	int		weaponselect;
	int		weaponsubtype;
	int		random_seed;
	short	mousedx;
	short	mousedy;
	bool	hasbeenpredicted;
};

#endif
