#pragma once

#include "Item.h"


class AHerb : public AItem
{
public:
	AHerb();
	virtual ~AHerb();

	virtual void Use() override;
};

