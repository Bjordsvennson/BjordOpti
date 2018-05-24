
#ifndef ENTITY_H
#define ENTITY_H

struct player_info_t;
class Vector;

#define	FL_ONGROUND (1 << 0)

class Entity
{
public:
	int entindex(void);
	int GetFlags(void);
	Vector GetVelocity(void);
	bool IsOnGround(void);
};

#endif
