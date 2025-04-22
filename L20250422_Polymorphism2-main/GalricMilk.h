#pragma once
#include "Garlic.h"
#include "Milk.h"
#include "Herb.h"

class AGalricMilk : public AGarlic, AMilk, AHerb
{
public:
	AGalricMilk();
	virtual ~AGalricMilk();

	virtual void Use() override;
};

