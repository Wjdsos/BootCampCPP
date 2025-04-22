#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "SweetFish.h"
#include "Herb.h"
#include "Milk.h"
#include "Branch.h"
#include "GalricMilk.h"
#include "Garlic.h"

int main()
{
	AItem* Inventory = new AGarlic();

	Inventory->Use();


	//C++ + define language => UHT ->  UE +  C++ -> VS
	//리플렉션 , C#, java, 네트워크
	// 만들어 
	//넌 마늘이다. 메타 데이터, C++
	AGarlic* Garlic = dynamic_cast<AGarlic*>(Inventory);
	if (Garlic)
	{
		Garlic->Smell();
	}

	ABranch* Branch = dynamic_cast<ABranch*>(Inventory);
	if (Branch) // IS_VAlid
	{
		Branch->Swing();
	}

	//Inventory->Smell();
}
