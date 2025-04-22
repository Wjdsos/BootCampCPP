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

	virtual void Use() override; // virtual 함수는 자식 클래스에서 재정의할 수 있는 함수를 의미
};

