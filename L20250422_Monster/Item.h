#pragma once
class AItem
{
public:
	AItem();
	virtual ~AItem();

	// ���� ���� �Լ�
	virtual void Use() = 0; // virtual �Լ��� �ڽ� Ŭ�������� �������� �� �ִ� �Լ��� �ǹ�

};

