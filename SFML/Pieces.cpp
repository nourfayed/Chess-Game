#include "Pieces.h"
#include "PositionStruct.h"


Pieces::Pieces(Position IntialPostion)
{
	Intial = IntialPostion;
}

void Pieces::SetScore(int PieceScore)
{
	Score = PieceScore;
}

int Pieces::CheckScore(){
	if (Score < 0){
		return -1;
	}
	else if (Score > 0){
		return 1;
	}
	else{
		return 0;
	}
}

int Pieces::GetScore(){
	int x = Score;
	return x;
}
