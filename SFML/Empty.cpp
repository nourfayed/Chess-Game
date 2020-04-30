#include "Empty.h"


Empty::Empty(Position CurP) :Pieces(CurP)
{
	Score = 0;
};

void Empty::Route(Position CurPosition){
	CurPosition = { -1, -1 };
	AvailableMoves.push_back(CurPosition);
}