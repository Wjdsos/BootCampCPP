#include "Inventory.h"

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
		// nullptr은 포인터가 가리키는 대상이 없음을 나타내는 값
		// push_back은 벡터의 끝에 요소를 추가하는 함수
	}
}
