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
		// nullptr�� �����Ͱ� ����Ű�� ����� ������ ��Ÿ���� ��
		// push_back�� ������ ���� ��Ҹ� �߰��ϴ� �Լ�
	}
}
