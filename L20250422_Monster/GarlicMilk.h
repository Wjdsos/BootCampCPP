#pragma once
#include "Item.h"
#include "Milk.h"
#include "Garlic.h"
#include "Herb.h"

class AGarlicMilk : public AMilk, AGarlic, AItem, AHerb
{
public:
	AGarlicMilk();
	virtual ~AGarlicMilk();

	virtual void Use() override; // virtual �Լ��� �ڽ� Ŭ�������� �������� �� �ִ� �Լ��� �ǹ�
};

