#include <iostream>
#include <algorithm>
#include <string>

#define CARD_COUNT	52


using namespace std;

int Deck[CARD_COUNT] = { 0, };
int Count = 0;

void Initialize() 
{
	srand((unsigned int)time(NULL));
	
	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index;
	}
}

void Shuffle() 
{
	int Temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 100; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}
}

int PrintCard(int CardRealNumber)
{
	int CardType = CardRealNumber / 13;
	int CardNumber = CardRealNumber % 13 + 1;
	int Score = CardNumber;

	string Types[4] = {
		"♥",
		"◆",
		"♣",
		"♠"
	};
	
	cout << Types[CardType] << " ";
	
	if(CardNumber == 1)
	{
		cout << "A" << endl;
	}
	else if (CardNumber == 11)
	{
		cout << "J" << endl;
	}
	else if (CardNumber == 12)
	{
		cout << "Q" << endl;
	}
	else if (CardNumber == 13)
	{
		cout << "K" << endl;
	}
	else 
	{
		cout << CardNumber << endl;
	}
	return Score;
}

void Start() 
{
	int ComputerScore = 0;
	int PlayerScore = 0;
	cout << "Computer" << endl << "============" << endl;
	ComputerScore += PrintCard(Deck[0]);
	ComputerScore += PrintCard(Deck[1]);
	cout << "Computer Score : " << ComputerScore << endl;

	cout << "Player" << endl << "============" << endl;
	PlayerScore += PrintCard(Deck[2]);
	PlayerScore += PrintCard(Deck[3]);
	cout << "Player Score : " << PlayerScore << endl;
	Count = 3;
}

int main() 
{
	Initialize();
	Shuffle();
	Start();

	return 0;
}

//int RandomRangeDemo(int RangeMin, int RangeMax) {
//	int Used[52] = { 0, };
//
//	int r = ((double)rand() / RAND_MAX) * (RangeMax - RangeMin) + RangeMin;
//	return r;
//}

/*int n;
	cout << "몇개를 뽑으시겠습니까?" << endl;
	cin >> n;
	bool* Used = (bool*)calloc(52, sizeof(bool));

	for (int i = 0; i < n; i++) {
		int Ball = RandomRangeDemo(1, 52);
		if (!Used[Ball]) {
			Used[Ball] = true;
			cout << Ball << endl;
		}
		else {
			i--;
		}
	}*/