#pragma once
#include "Item.h"
class AGarlic : public AItem
{
public:
	AGarlic();
	virtual ~AGarlic();

	virtual void Use() override;

	void Smell();
};

