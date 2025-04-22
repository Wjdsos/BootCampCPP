#pragma once

#include "Item.h"

class ASweetFish : public AItem
{
public:
	ASweetFish();
	virtual ~ASweetFish();
	
	virtual void Use() override;

};

