#pragma once

#include <vector> // 배열 대신 벡터 사용

class AHerb;
class AMilk;
class ASweetFish;
class AItem;

class AInventory
{
public:
	AInventory();
	virtual ~AInventory();

	// V 이걸 하나로 퉁쳐보장->추상화(부모클래스)
	//AMilk* Milk[10]; 
	//AHerb* Herb[10]; 
	//ASweetFish* SweetFish[10];
	
	inline std::vector<AItem*> GetAllItems() // inline은 함수의 정의를 헤더 파일에 작성할 때 사용 
	{
		return Items;
	}

	void AddItem(AItem* InItem);

	void UseItem(int Index)
	{
		//Items[Index]->Use();
	}

protected:
	std::vector<AItem*> Items; // std::vector은 C++ 제공하는 동적 배열 클래스
	// std::vector<AItem*>은 AItem 클래스 포인터를 저장하는 벡터를 의미(이중포인터를 의미하기도 함)

};

