#pragma once
#include "PositionStruct.h"
#include <vector>
using namespace std;
class Pieces
{
protected:
	Position Intial;
public:
	int Score;
	Pieces();
	Pieces(Position);

	virtual void Route(Position)=0 ;


	vector <Position> ValidMoves;
	vector <Position> AvailableMoves;

	void SetScore(int);
	int CheckScore();
	int GetScore();
};