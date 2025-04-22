#pragma once
#include <vector>

class AMilk;
class ASweetFish;
class AHerb;
class ABranch;
class AItem;

class AInventory
{
public:
	AInventory();
	virtual ~AInventory();

	//AMilk* Milks[10];
	//ASweetFish* SweetFish[10];
	//AHerb* Herbs[10];
	//ABranch* Branches[10];

	inline std::vector<AItem*> GetAllItems()
	{
		return Items;
	}

	void AddItem(AItem* InItem);

	void UseItem(int Index);



protected:
	std::vector<AItem*> Items;


};

//Inventory has a Milk.
//Inventory has a SweetFish.
//Inventory has a Herb.
//Inventory has a Branch.

//추상화(부모 클래스)
//Inventory has a Item

//Milk is a Item.
//SweetFish is a Item.
//Herb is a Item.
//Branch is a Item.
//Item is a Milk.