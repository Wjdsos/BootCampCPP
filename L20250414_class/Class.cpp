#include <iostream>

using namespace std;


class State
{
public:
	int ID;
	string Name;
};

class Transition
{
public:
	int CurrentState;
	string Condition;
	int NextState;
};

class MonsterFSM
{
public:
	State States[4];
	Transition Transitions[5];

	void Process(Monster _Monster)
	{

	}
};

class Monster
{
public:
	int State;
	string Condition;
};

//MonsterFSM has a State.
//MonsterFSM has a Transition.

int main()
{
	MonsterFSM MyMonsterFSM;

	MyMonsterFSM.States[0].ID = 1;
	MyMonsterFSM.States[0].Name = "��ȸ";

	MyMonsterFSM.States[1].ID = 2;
	MyMonsterFSM.States[1].Name = "�߰�";

	MyMonsterFSM.States[2].ID = 3;
	MyMonsterFSM.States[2].Name = "����";

	MyMonsterFSM.States[3].ID = 4;
	MyMonsterFSM.States[3].Name = "����";

	MyMonsterFSM.Transitions[0].CurrentState = 1;
	MyMonsterFSM.Transitions[0].Condition = "���߰�";
	MyMonsterFSM.Transitions[0].NextState = 2;

	MyMonsterFSM.Transitions[1].CurrentState = 2;
	MyMonsterFSM.Transitions[1].Condition = "����ħ";
	MyMonsterFSM.Transitions[1].NextState = 1;

	MyMonsterFSM.Transitions[2].CurrentState = 2;
	MyMonsterFSM.Transitions[2].Condition = "�����Ÿ�����";
	MyMonsterFSM.Transitions[2].NextState = 3;

	MyMonsterFSM.Transitions[3].CurrentState = 3;
	MyMonsterFSM.Transitions[3].Condition = "�����Ÿ���Ż";
	MyMonsterFSM.Transitions[3].NextState = 2;

	MyMonsterFSM.Transitions[4].CurrentState = 3;
	MyMonsterFSM.Transitions[4].Condition = "HP����";
	MyMonsterFSM.Transitions[4].NextState = 4;

	Monster ����;
	����.State = 1;
	����.Condition = "���߰�";

	cout << ����.State << endl;

	return 0;
}