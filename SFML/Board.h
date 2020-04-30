#pragma once
#include "Askary.h"
#include "Feel.h"
#include "Hossan.h"
#include "Malek.h"
#include "Pieces.h"
#include "PositionStruct.h"
#include "TabiaParent.h"
#include "Wazer.h"
#include "Empty.h"
#include <iostream>
#include <vector>
using namespace std;

class Board
{
private:
	Pieces *board[8][8];
public:

	Board();
	~Board(); 
	bool IsValid(Position, Position);
	int GetGameState();
	void ChangePosition(Position, Position);
	bool Warning(Position);
	void UpdateTheVector(Position);
	Position MalekPosition(int);
	int CheckTurn(Position);
	vector <Position> ReturnVector(Position);
};

