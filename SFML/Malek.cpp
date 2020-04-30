#include "Malek.h"
#include "PositionStruct.h"
#include "Pieces.h"
#include <vector>

using namespace std;

Malek::Malek(Position CurP) : Pieces(CurP) {};

void Malek::Route(Position CurPosition)
{
	Position Cells;
	int I = CurPosition.X;
	int J = CurPosition.Y;

	if (I - 1 >= 0){
		Cells.X = CurPosition.X - 1;
		Cells.Y = CurPosition.Y;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (I + 1 < 8){
		Cells.X = CurPosition.X + 1;
		Cells.Y = CurPosition.Y;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (J - 1 >= 0){
		Cells.X = CurPosition.X;
		Cells.Y = CurPosition.Y - 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (J + 1 < 8){
		Cells.X = CurPosition.X;
		Cells.Y = CurPosition.Y + 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (I - 1 >= 0 && J - 1 >= 0) {
		Cells.X = CurPosition.X - 1;
		Cells.Y = CurPosition.Y - 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (I - 1 >= 0 && J + 1 < 8) {
		Cells.X = CurPosition.X - 1;
		Cells.Y = CurPosition.Y + 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (I + 1 < 8 && J + 1 < 8) {
		Cells.X = CurPosition.X + 1;
		Cells.Y = CurPosition.Y + 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
	if (I + 1 < 8 && J - 1 >= 0) {
		Cells.X = CurPosition.X + 1;
		Cells.Y = CurPosition.Y - 1;
		AvailableMoves.push_back(Cells);
		Cells.X = -1;
		Cells.Y = -1;
		AvailableMoves.push_back(Cells);
	}
}

