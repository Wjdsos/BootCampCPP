#pragma once
class AItem
{
public:
	AItem();
	virtual ~AItem();

	// 순수 가상 함수
	virtual void Use() = 0; // virtual 함수는 자식 클래스에서 재정의할 수 있는 함수를 의미

};

