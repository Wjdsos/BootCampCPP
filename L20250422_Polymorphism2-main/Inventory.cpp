#include "Inventory.h"
#include "Item.h"

AInventory::AInventory()
{
}

AInventory::~AInventory()
{
}

void AInventory::AddItem(AItem* InItem)
{
	if (InItem)
	{
		Items.push_back(InItem);
	}
}

void AInventory::UseItem(int Index)
{
	Items[Index]->Use();
}
