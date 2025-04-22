#pragma once

#include <vector> // �迭 ��� ���� ���

class AHerb;
class AMilk;
class ASweetFish;
class AItem;

class AInventory
{
public:
	AInventory();
	virtual ~AInventory();

	// V �̰� �ϳ��� ���ĺ���->�߻�ȭ(�θ�Ŭ����)
	//AMilk* Milk[10]; 
	//AHerb* Herb[10]; 
	//ASweetFish* SweetFish[10];
	
	inline std::vector<AItem*> GetAllItems() // inline�� �Լ��� ���Ǹ� ��� ���Ͽ� �ۼ��� �� ��� 
	{
		return Items;
	}

	void AddItem(AItem* InItem);

	void UseItem(int Index)
	{
		//Items[Index]->Use();
	}

protected:
	std::vector<AItem*> Items; // std::vector�� C++ �����ϴ� ���� �迭 Ŭ����
	// std::vector<AItem*>�� AItem Ŭ���� �����͸� �����ϴ� ���͸� �ǹ�(���������͸� �ǹ��ϱ⵵ ��)

};

