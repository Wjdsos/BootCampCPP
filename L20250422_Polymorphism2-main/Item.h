#pragma once
class AItem
{
public:
	AItem();
	virtual ~AItem();

	//순수 가상 함수
	virtual void Use() = 0;


};

