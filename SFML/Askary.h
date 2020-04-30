#pragma once
#include "Pieces.h"
#include "PositionStruct.h"
#include <vector>
using namespace std;

class Askary :
	public Pieces
{
protected:
	int  Moves = 0;

public:
	Askary(Position);
	virtual void Route(Position);
	///*int MovesNumber();
	//void MovesErase();*/
	//Don't forget to check when it's under attack 
};

