#pragma once

#include "Item.h"


class AMilk : public AItem
{
public:
	AMilk();
	virtual ~AMilk();

	virtual void Use() override;
};

