#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "Herb.h"
#include "Milk.h"
#include "SweetFish.h"
#include "Garlic.h"
#include "GarlicMilk.h"

using namespace std;

int main()
{
	AInventory Inventory;

	Inventory.AddItem(new AMilk());
	Inventory.AddItem(new AHerb());
	Inventory.AddItem(new ASweetFish());
	Inventory.AddItem(new AGarlic());

	AGarlic Milk;

	Milk.Use();
	
	return 0;
}