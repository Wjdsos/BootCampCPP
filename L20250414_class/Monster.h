#include "Actor.h"

class AMonster : public AActor
{
public:
	void Move();

protected:
	bool Decision()
	{
		return true;
	}
};
